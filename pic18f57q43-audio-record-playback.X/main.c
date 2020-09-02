/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
        Device            :  PIC18F57Q43
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

// DEBUG Macros
#define DBG_ENABLE              true       // Enable/disable debug function calls
#if DBG_ENABLE
    #define DBG(x) x
#else
    #define DBG(x) 
#endif

// LED Marcos
#define LED0_TurnOn             LED0_SetLow
#define LED0_TurnOff            LED0_SetHigh

// DMA Macros
#define MAX_DMA                 6           // Max number of DMAs being used
#define DMA1                    0           // ADC to DAC               // Passthrough
#define DMA2                    1           // ADC to PingPong          // Record
#define DMA3                    2           // SPI to DAC               // Playback
#define DMA4                    3           // PingPong to SPI          // Record
#define DMA5                    4           // PingPong to BufferRAM    // Record
#define DMA6                    5           // PFM to DAC               // Playback
#define DMA7                    6           // Unused - not available in Q43
#define DMA8                    7           // Unused - not available in Q43

// Memory Macros and variables
#define GPR_PFM_BLOCK_SIZE      256         // Bank size of GPR space in bytes
#define PFM_AUDIO_START_ADDR    0x4000      // Start address of audio#1 in flash // default 0x4000
#define PFM_AUDIO_END_ADDR      0x01FEFF    // Last address available in PFM for audio storage (excludes SAF)
#define PFM_AUDIO_SIZE_PAGES    447         // Size of each audio in pages // from 0x4000 447 pages reached last-1 page // 192 pages reaches 0xFFFF
#define PFM_AUDIO_METADATA_ADDR 0x0000      // Offset from 0x380000 in EEPROM // Metadata stored here

uint16_t gpr11_ping __at(0x0B00);           // GPR11 is ping buffer
uint16_t gpr12_pong __at(0x0C00);           // GPR12 is pong buffer

uint16_t gpr_bank36 __at(0x2400);
uint16_t gpr_bufferRam __at(0x2500);

// External Memory Macros and variables
#include "SST26VF064B.h"
#define EXTMEM_ENABLE           true

#define EXTMEM_BLOCK_SIZE       256         // Page size (in bytes) in external memory
#define EXTMEM_START_ADDR       0x0         // First available memory location
#define EXTMEM_END_ADDR         0x7FFFFF    // Last available memory location
#define EXTMEM_SIZE_PAGES       32768       // Total number of pages available
#define EXTMEM_METADATA_ADDR    0x0010      // Offset from 0x380000 in EEPROM // Metadata stored here

bool extMem = false;                        // Is external memory present?

// Application macros and variables

#define DELAY_4s                0x0BDC      // TMR1H:L values for wait times
#define DELAY_3s                0x48E5      // at CLK=MFINTOSC_31.25kHz
#define DELAY_500ms             0xE17B      // and 1:2 prescaler
#define DELAY_400ms             0xE796      // Used to time the buttons
#define DELAY_300ms             0xEDB0

#define PrintChar               UART1_Write // Print debug char into UART

bool volatile transferToStorage = false;
bool volatile tickOccured = false;

extern bool sw0_pressed;                    // Defined in clc1.c
extern bool sw0_released; 
extern bool sw1_pressed;                    // Defined in clc2.c
extern bool sw1_released; 

typedef struct {                            // Metadata about stored audio
    uint32_t audioStartAddr;
    uint16_t audioSize_pages;
} Metadata;
Metadata pfmAudio, extMemAudio;             // Separate metadata for PFM and extMem

typedef enum operatingMode {Idle, Record, Playback, Erase, Passthrough} Mode;
typedef enum sourceReg {ping, pong} SourceReg;
Mode mode = Idle;

/**
 * @brief This is the TMR0 user defined ISR
 * @return None
 * @param None
 * @example Called from TMR0_ISR();
 */
void TimerTick_ISR(void) 
{
    DBG(IO_RD0_SetHigh());
    
    tickOccured = true;      // This flag is cleared elsewhere in code wherever applicable

    static volatile uint16_t count = 0;
    
    if (++count >= GPR_PFM_BLOCK_SIZE)
    {
        count = 0;
        if(!transferToStorage) {            // TODO: Why this logic? Replace this logic with DMA transfer counts
            transferToStorage = true;
        } 
    }
    
    DBG(IO_RD0_SetLow());
    return;
}

/**
 * @brief This inline routine stalls program execution until a timer tick occurs
 * @return None
 * @param None
 * @example WaitForTick();
 */
void inline WaitForTick()
{
    // Stall the program execution until a timer tick occurs
    while(!tickOccured);
    tickOccured = false;
}

/**
 * @brief This is the TMR6 user defined ISR
 * @return None
 * @param None
 * @example Called from TMR6_ISR();
 */
void BlinkTimer_ISR(void)
{
    LED0_Toggle();
}

/**
 * @brief This function starts the timer to blink LED0
 * @return None
 * @param None
 * @example LED0_Blink_Start();
 */
inline void LED0_Blink_Start() 
{
    TMR6_StartTimer();
}

/**
 * @brief This function stops the timer to blink LED0
 * @return None
 * @param None
 * @example LED0_Blink_Stop();
 */
inline void LED0_Blink_Stop()
{
    TMR6_StopTimer();
    LED0_TurnOff();
}

/**
 * @brief This clears IF flag, stops, reloads, and starts TMR1
 * @return None
 * @param [in] 16-bit TMR1H:L value
 * @example TMR1_StopAndStartTimer(DELAY_3s);
 */
inline void TMR1_StopAndStartTimer(uint16_t delay)
{
    // Clearing IF flag.
    PIR3bits.TMR1IF = 0;
    
    // Stop, reload, start
    TMR1_StopTimer();
    TMR1_WriteTimer(delay);
    TMR1_StartTimer();
}

/**
 * @brief This clears all pressed/released flags of all switches
 * @return None
 * @param None
 * @example ResetSwitches();
 */
inline void ResetSwitches()
{
    sw0_pressed = false;
    sw0_released = false;
}

/**
 * @brief This routine resets a specified DMA instance by disabling and enabling the DMA
 * @return None
 * @param None
 * @example ResetDMA(0x01); // Resets DMA2
 */
void inline ResetDMA(uint8_t dma)
{
    // Max up to DMA6
    if(dma > MAX_DMA-1)
        return;
    
    DMASELECT = dma;
    DMAnCON0bits.EN = 0;
    DMAnCON0bits.EN = 1;
}

/**
 * @brief This routine disables, stops, re-enables all DMAs
 * @return None
 * @param None
 * @example ResetAllDMA();
 */
void inline ResetAllDMA()
{
    for(int8_t dma = MAX_DMA-1; dma >= 0; dma--) {
        DMASELECT = dma;
        DMAnCON0bits.EN = 0;
        DMAnCON0bits.SIRQEN = 0; 
        DMAnCON0bits.DGO = 0;
        DMAnCON0bits.EN = 1;
    }
}

/**
 * @brief This routine writes one word from NVMDAT to given address of Program Flash Memory
 * @return
 * @param [in] Target address in Program Flash Memory
 * @example FLASH_WriteWord_ByWord(flashAddr);
 */
void FLASH_WriteWord_ByWord(uint32_t flashAddr)
{
    uint8_t GIEBitValue = INTCON0bits.GIE; // Save interrupt enable

    //Set NVMADR with the target word address
    NVMADRU = (uint8_t) ((flashAddr & 0x00FF0000) >> 16);
    NVMADRH = (uint8_t) ((flashAddr & 0x0000FF00) >> 8);
    NVMADRL = (uint8_t) (flashAddr & 0x000000FF);

    //Set the NVMCMD control bits for Write Word operation
    NVMCON1bits.NVMCMD = 0b011;

    //Disable all interrupt
    INTCON0bits.GIE = 0;

    //Perform the unlock sequence
    NVMLOCK = 0x55;
    NVMLOCK = 0xAA;

    //Start page programming and wait for the operation to complete
    NVMCON0bits.GO = 1;
    while (NVMCON0bits.GO);

    //Restore the interrupts
    INTCON0bits.GIE = GIEBitValue;

    //Set the NVMCMD control bits for Word Read operation to avoid accidental writes
    NVMCON1bits.NVMCMD = 0b000;
}

/**
 * @brief This routine writes one block from Buffer RAM to given address of Program Flash Memory word-by-word
 * @return
 * @param [in] Starting address of a Program Flash Memory block
 * @example FLASH_WritePage_ByWord(flashAddr);
 */
int8_t FLASH_WritePage_ByWord(uint32_t flashAddr)
{
    uint16_t *bufferRamPtr = (uint16_t*) & gpr_bufferRam;
    uint32_t blockStartAddr = (uint32_t) (flashAddr & ((END_FLASH - 1) ^ ((ERASE_FLASH_BLOCKSIZE * 2) - 1)));
    uint8_t i;

    //Block write must start at the beginning of a row
    if (flashAddr != blockStartAddr)
    {
        return -1;
    }
    
    //Erase the given block
    //FLASH_EraseBlock(flashAddr);  //Removed cuz this block is cleared prior to function call

    //Copy Buffer RAM into NVMDAT one word at a time
    for (i = 0; i < ERASE_FLASH_BLOCKSIZE; i++) // ERASE_FLASH_BLOCKSIZE = 128
    {
        NVMDAT = *bufferRamPtr++;
        
        // Proceed only if a timer tick event occurs
        WaitForTick();
        
        DBG(IO_RD3_SetHigh());
        //Write NVMDAT contents to given Program Flash Memory location
        FLASH_WriteWord_ByWord(flashAddr);
        flashAddr+=2;
        DBG(IO_RD3_SetLow());
    }

    return 0;
}

/**
 * @brief This routine erases specified number of pages from given address of Program Flash Memory
 * @return
 * @param [in] Starting address of a Program Flash Memory block
 * @param [in] Number of pages to erase
 * @example FLASH_ErasePages(PFM_AUDIO_START_ADDR, PFM_AUDIO_SIZE_PAGES);
 */
void FLASH_ErasePages(uint32_t flashAddr, uint16_t numPages)
{
    if(numPages > PFM_AUDIO_SIZE_PAGES) {
        numPages = PFM_AUDIO_SIZE_PAGES;
    }
    
    for(uint16_t i = 0; i < numPages; i++) {
        FLASH_EraseBlock(flashAddr);
        flashAddr += GPR_PFM_BLOCK_SIZE;
    }
}

/**
 * @brief This routine transfers ping/pong buffer contents to buffer RAM
 * @return None
 * @param None
 * @example PingPong2BufferRam();
 */
void inline PingPong2BufferRam()
{
    DBG(IO_RD3_SetHigh());
    DMASELECT = DMA5;
    DMAnCON0bits.DGO = 1;
    while(DMAnCON0bits.DGO == 1);   // DGO cleared when DCNT=1
    DBG(IO_RD3_SetLow());
}

/**
 * @brief This routine transfers ping/pong buffer contents to SPITX
 * @return None
 * @param None
 * @example PingPong2SPI();
 */
void inline PingPong2SPI()
{
    DBG(IO_RD3_SetHigh());
    
    static SourceReg src = ping;
    
    // Prepare SPI to transmit a block of data
    while(SPI1CON2bits.BUSY);
    SPI1CON2bits.RXR = 0;
    SPI1TCNT = GPR_PFM_BLOCK_SIZE;
    
    // Prepare DMA for transfer
    PIR11bits.DMA4SCNTIF = 0;
    DMASELECT = DMA4;
    DMAnCON0bits.EN = 0;
    if(src == ping) DMAnSSA = &gpr11_ping;  // Update DMA source addr
    else DMAnSSA = &gpr12_pong;
    
    // Invoke DMA transfer
    DMAnCON0bits.EN = 1;
    DMAnCON0bits.SIRQEN = 1;
    while(PIR11bits.DMA4SCNTIF == 0);
    PIR11bits.DMA4SCNTIF = 0;

    // Reset SPI to Full Duplex
    while(SPI1CON2bits.BUSY);
    SPI1CON2bits.RXR = 1;
    
    // Update source reg for next transfer
    if(src == ping) src = pong;
    else src = ping;
           
    DBG(IO_RD3_SetLow());
}

/**
 * @brief This routine selects appropriate microphone input based on hardware jumper
 * @return None
 * @param None
 * @example AUDIO_SelectMicInput();
 */
void inline AUDIO_SelectMicInput()
{
    if(Mic_SEL_GetValue())
        ADPCH = channel_MIC2_AND7;
    else
        ADPCH = channel_MIC_ANA0;
}

/**
 * @brief This routine reads the metadata of the stored audio
 * @return None
 * @param None
 * @example AUDIO_ReadMetaData();
 */
void AUDIO_ReadMetaData()
{
    if(extMem)
    {
        extMemAudio.audioStartAddr  = ((uint32_t)DATAEE_ReadByte(EXTMEM_METADATA_ADDR))   << 24;
        extMemAudio.audioStartAddr += ((uint32_t)DATAEE_ReadByte(EXTMEM_METADATA_ADDR+1)) << 16;
        extMemAudio.audioStartAddr += ((uint32_t)DATAEE_ReadByte(EXTMEM_METADATA_ADDR+2)) << 8;
        extMemAudio.audioStartAddr += ((uint32_t)DATAEE_ReadByte(EXTMEM_METADATA_ADDR+3));
        
        extMemAudio.audioSize_pages = ((uint32_t)DATAEE_ReadByte(EXTMEM_METADATA_ADDR+4)) << 8;
        extMemAudio.audioSize_pages+= ((uint32_t)DATAEE_ReadByte(EXTMEM_METADATA_ADDR+5));
        
        // Did EEPROM return all 0xFF? Then it is blank and no metadata exists
        // In that case initialize metadata here
        if(extMemAudio.audioStartAddr == 0xFFFFFFFF && extMemAudio.audioSize_pages == 0xFFFF) {
            extMemAudio.audioStartAddr = EXTMEM_START_ADDR;
            extMemAudio.audioSize_pages = 0;
        }
    }
    else
    {
        pfmAudio.audioStartAddr  = ((uint32_t)DATAEE_ReadByte(PFM_AUDIO_METADATA_ADDR))   << 24;
        pfmAudio.audioStartAddr += ((uint32_t)DATAEE_ReadByte(PFM_AUDIO_METADATA_ADDR+1)) << 16;
        pfmAudio.audioStartAddr += ((uint32_t)DATAEE_ReadByte(PFM_AUDIO_METADATA_ADDR+2)) << 8;
        pfmAudio.audioStartAddr += ((uint32_t)DATAEE_ReadByte(PFM_AUDIO_METADATA_ADDR+3));
        
        pfmAudio.audioSize_pages = ((uint32_t)DATAEE_ReadByte(PFM_AUDIO_METADATA_ADDR+4)) << 8;
        pfmAudio.audioSize_pages+= ((uint32_t)DATAEE_ReadByte(PFM_AUDIO_METADATA_ADDR+5));
        
        // Did EEPROM return all 0xFF? Then it is blank and no metadata exists
        // In that case initialize metadata here
        if(pfmAudio.audioStartAddr == 0xFFFFFFFF && pfmAudio.audioSize_pages == 0xFFFF) {
            pfmAudio.audioStartAddr = PFM_AUDIO_START_ADDR;
            pfmAudio.audioSize_pages = 0;
        }
    }
}

/**
 * @brief This routine updates the metadata of the stored audio
 * @return None
 * @param None
 * @example AUDIO_UpdateMetaData();
 */
void AUDIO_UpdateMetaData()
{
    if(extMem)
    {
        DATAEE_WriteByte(EXTMEM_METADATA_ADDR,   extMemAudio.audioStartAddr >> 24);
        DATAEE_WriteByte(EXTMEM_METADATA_ADDR+1, extMemAudio.audioStartAddr >> 16);
        DATAEE_WriteByte(EXTMEM_METADATA_ADDR+2, extMemAudio.audioStartAddr >> 8);
        DATAEE_WriteByte(EXTMEM_METADATA_ADDR+3, extMemAudio.audioStartAddr);
        
        DATAEE_WriteByte(EXTMEM_METADATA_ADDR+4, extMemAudio.audioSize_pages >> 8);
        DATAEE_WriteByte(EXTMEM_METADATA_ADDR+5, extMemAudio.audioSize_pages);
    }
    else
    {  
        DATAEE_WriteByte(PFM_AUDIO_METADATA_ADDR,   pfmAudio.audioStartAddr >> 24);
        DATAEE_WriteByte(PFM_AUDIO_METADATA_ADDR+1, pfmAudio.audioStartAddr >> 16);
        DATAEE_WriteByte(PFM_AUDIO_METADATA_ADDR+2, pfmAudio.audioStartAddr >> 8);
        DATAEE_WriteByte(PFM_AUDIO_METADATA_ADDR+3, pfmAudio.audioStartAddr);
        
        DATAEE_WriteByte(PFM_AUDIO_METADATA_ADDR+4, pfmAudio.audioSize_pages >> 8);
        DATAEE_WriteByte(PFM_AUDIO_METADATA_ADDR+5, pfmAudio.audioSize_pages);
    }
}

/**
 * @brief This routine services Erase mode and whenever erase is needed
 * @return None
 * @param None
 * @example AUDIO_Erase();
 */
void AUDIO_Erase()
{
    DBG(PrintChar('E'));
    
    // Reset any pre-existing switch states
    ResetSwitches();
    
    // Clear all pages for storage
    LED0_Blink_Start();
    if(extMem) {
        SST26VF064B_ChipErase();
        while( SST26VF064B_Busy() );    // Wait for Erase to finish
        
        // Update metadata
        extMemAudio.audioStartAddr = EXTMEM_START_ADDR;
        extMemAudio.audioSize_pages = 0;
    } 
    else {
        FLASH_ErasePages(PFM_AUDIO_START_ADDR, PFM_AUDIO_SIZE_PAGES);
        
        // Update metadata
        pfmAudio.audioStartAddr = PFM_AUDIO_START_ADDR;
        pfmAudio.audioSize_pages = 0;
    }
    AUDIO_UpdateMetaData();     // Save metadata to EEPROM
    LED0_Blink_Stop();
    
    DBG(PrintChar('x'));
    
    // Change mode to Idle only if current mode is Erase
    // Retain current mode for all other modes.
    // This is because Erase can be called from other modes too.
    if(mode == Erase) {
        mode = Idle;
    }
}

/**
 * @brief This routine services Idle mode
 * @return None
 * @param None
 * @example AUDIO_Idle();
 */
void AUDIO_Idle()
{
    // Monitor switches to change modes
    // SW0 = Record/Play/Erase Button
    // Single press = Playback
    // Double press = Record
    // Long press = Erase
    if(sw0_pressed) {
        sw0_pressed = false;                            
        sw0_released = false;                           // Ensure sw0 is reset
        TMR1_StopAndStartTimer(DELAY_3s);               // Start 3s timer
        while(!TMR1_HasOverflowOccured()){
            if(sw0_released){                           // sw0 released before 3s timer could elapse
                sw0_released = false;
                LED0_Blink_Start();                     // Blink LED to show transition phase
                TMR1_StopAndStartTimer(DELAY_500ms);    // Start 500ms timer
                while(!TMR1_HasOverflowOccured()){
                    if(sw0_pressed) {                   // sw0 pressed again within 500ms - double press detected
                        sw0_pressed = false;
                        mode = Record;
                        TMR1_StopTimer();
                        LED0_Blink_Stop();              // Stop LED blink to end transition phase
                        return;
                    }
                }
                mode = Playback;                        // sw0 not pressed within 500ms - single press detected
                TMR1_StopTimer();
                LED0_Blink_Stop();                      // Stop LED blink to end transition phase
                return;
            }  
        }
        mode = Erase;                                   // 3s timer elapsed and sw0 did not get released - long press detected
        TMR1_StopTimer();
        return;
    }
    
    // SW1 = Passthrough Button
    // Long press = Passthrough
    else if(sw1_pressed) {
        sw1_pressed = false;                            
        sw1_released = false;                           // Ensure sw1 is reset
        TMR1_StopAndStartTimer(DELAY_3s);               // Start 3s timer
        while(!TMR1_HasOverflowOccured()){
            if(sw1_released) {                          // sw1 released before 3s timer could elapse - single press detected
                sw1_released = false;
                return;
            }
        }
        mode = Passthrough;                             // 3s timer elapsed and sw0 did not get released - long press detected
        TMR1_StopTimer();
        return;
    }
}

/**
 * @brief This routine services Record mode. This is non-blocking implementation.
 * @return None
 * @param None
 * @example AUDIO_Record();
 */
void AUDIO_Record()
{
    DBG(PrintChar('R'));
    
    // Reset any pre-existing switch states
    ResetSwitches();
    
    // Start by erasing the existing data in flash
    AUDIO_Erase();
    
    // Initialize writing to memory
    uint32_t flashAddr;
    uint32_t maxFlashAddr;
    uint16_t numPagesWritten = 0;
    uint16_t *bufferRamPtr;
    uint32_t blockStartAddr;
    uint16_t maxAudioSize;
    uint16_t i = 0;
    
    if(extMem)
    {
        flashAddr = EXTMEM_START_ADDR;
        maxFlashAddr = EXTMEM_END_ADDR;
        maxAudioSize = EXTMEM_SIZE_PAGES;
        extMemAudio.audioStartAddr = flashAddr;     // metadata
    }
    else
    {
        flashAddr = PFM_AUDIO_START_ADDR;
        maxFlashAddr = PFM_AUDIO_END_ADDR;
        maxAudioSize = PFM_AUDIO_SIZE_PAGES;
        pfmAudio.audioStartAddr = flashAddr;        // metadata
    }
    
    // Select microphone input channel
    AUDIO_SelectMicInput();

    // Enable ADC
    ADCON0bits.ON = 1;
    
    // Reset relevant DMAs
    ResetDMA(DMA2);     // DMA2 (ADC to ping/pong)
    ResetDMA(DMA4);     // DMA4 (ping/pong to SPI)
    ResetDMA(DMA5);     // DMA5 (ping/pong to BufferRAM)
    
    // Reset and start sampling timer and DMA
    DMA2_StartTransferWithTrigger();
    TMR0_Reload();
    TMR0_StartTimer();
    LED0_TurnOn();
    
    // Writing loop
    // This is non-blocking implementation 
    // Break out if record button is pressed again 
    // [or] if reached the end of allocated memory
    while(!sw0_pressed && (flashAddr < maxFlashAddr)){
    
        
        // Keep checking for when to write to storage
        // transferToStorage flag is set in ISR
        if(transferToStorage) {
            
            // Transfer to external memory if present
            if(extMem) {
                DBG(IO_RD1_SetHigh());
                
                // Initialize external memory
                while( SST26VF064B_Busy() );
                SST26VF064B_WriteEnable();
                SST26VF064B_CS_Low();
                SST26VF064B_PageProgram_Cmd();
                SST26VF064B_WriteAddress(flashAddr);
                
                // Transfer ping/pong to SPI
                PingPong2SPI(); 
                
                // Close out transfer
                SST26VF064B_CS_High();
                while( SST26VF064B_Busy() );    // Wait for pending transfer to complete
                numPagesWritten++;              // Increment number of pages written
                flashAddr += EXTMEM_BLOCK_SIZE; // Update flashAddr to new location
                transferToStorage = false;      // Clear flag
                DBG(IO_RD1_SetLow());               
            }
            
            // Otherwise transfer to internal memory
            else {
                // First, transfer ping/pong to buffer RAM
                if(i == 0) {
                    // Initialize memory
                    bufferRamPtr = (uint16_t*) & gpr_bufferRam;
                    blockStartAddr = (uint32_t) (flashAddr & ((END_FLASH - 1) ^ ((ERASE_FLASH_BLOCKSIZE * 2) - 1)));

                    //Block write must start at the beginning of a row
                    if (flashAddr != blockStartAddr)
                    {
                        return;
                    }

                    DBG(IO_RD1_SetHigh());

                    // Proceed only if a timer tick event occurs
                    WaitForTick();

                    // Transfer ping/pong to buffer RAM
                    PingPong2BufferRam();
                }

                // Next, write buffer RAM contents to PFM one word at a time
                if(i < ERASE_FLASH_BLOCKSIZE) // ERASE_FLASH_BLOCKSIZE = 128
                {
                    // Transfer word to NVMDAT
                    NVMDAT = *bufferRamPtr++;

                    // Proceed only if a timer tick event occurs
                    WaitForTick();

                    DBG(IO_RD3_SetHigh());

                    //Write NVMDAT contents to given Program Flash Memory location
                    FLASH_WriteWord_ByWord(flashAddr);

                    // Increment flash write address and word counter
                    flashAddr+=2;
                    i++;
                    DBG(IO_RD3_SetLow());

                    // Check for PFM write error
                    if(NVMCON1bits.WRERR == 1) {
                        // Write Error Detected - Do whatever appropriate
                        NVMCON1bits.WRERR = 0;
                        DBG(IO_RD3_Toggle());
                    }

                }

                // End when entire bufferRAM has been written to PFM
                else {
                    // Increment number of pages written
                    numPagesWritten++;

                    // Reset word counter
                    i = 0;

                    // Clear flag
                    transferToStorage = false;
                    DBG(IO_RD1_SetLow());
                }        
            }
        }
    }
    
    // Stop sampling timer and DMA
    DMA2_StopTransfer();
    TMR0_StopTimer();
    TMR0_Reload();
    LED0_TurnOff();
    
    // Disable ADC
    ADCON0bits.ON = 0;
    
    // Save metadata for recorded audio
    if(extMem)
        extMemAudio.audioSize_pages = numPagesWritten;
    else
        pfmAudio.audioSize_pages = numPagesWritten;
    
    AUDIO_UpdateMetaData();
    
    // Reset any lurking switch states
    ResetSwitches();

    // Change operation mode back to Idle
    mode = Idle;
    DBG(PrintChar('x'));
}

/**
 * @brief This routine services Playback mode
 * @return None
 * @param None
 * @example AUDIO_Playback();
 */
void AUDIO_Playback()
{
    DBG(PrintChar('P'));
    
    // Reset any pre-existing switch states
    ResetSwitches();
    
    // Initialize playback from memory
    uint32_t flashAddr;
    uint16_t numPages;
    
    if(extMem)
    {
        flashAddr = extMemAudio.audioStartAddr;
        numPages = extMemAudio.audioSize_pages;
    }
    else
    {
        flashAddr = pfmAudio.audioStartAddr;
        numPages = pfmAudio.audioSize_pages;
    }
    
    // Enable PWM for power amplifier
    PWM2_16BIT_Enable();
    
    // Enable DAC
    DAC1CONbits.EN = 1;
    
    // Reset relevant DMAs
    ResetDMA(DMA3);     // DMA3 (SPI to DAC)
    ResetDMA(DMA6);     // DMA6 (PFM to DAC)
    
    // Reset and start sampling timer
    TMR0_Reload();
    TMR0_StartTimer();
    LED0_TurnOn();
    
    if(extMem) {
        while( SST26VF064B_Busy() );

        SST26VF064B_CS_Low();
        SST26VF064B_Read_Cmd( );
        SST26VF064B_WriteAddress(flashAddr);
        
        // Prepare SPI to receive a block of data
        while(SPI1CON2bits.BUSY);
        SPI1CON2bits.TXR = 0;
         
        // Read one page at a time
        for(uint16_t i = numPages; i > 0; i--)
        {
            // Kick off SPI in Receive-only mode            
            SPI1TCNT = EXTMEM_BLOCK_SIZE;
            
            // Kick off DMA (SPI to DAC)
            PIR10bits.DMA3SCNTIF = 0;
            DMASELECT = DMA3;
            DMAnCON0bits.SIRQEN = 1;
            while(PIR10bits.DMA3SCNTIF == 0);
            PIR10bits.DMA3SCNTIF = 0;
            
            // Break out if playback button is pressed again
            if(sw0_pressed) {
                sw0_pressed = false;
                break;
            }
            
        }
        
        // Reset SPI to Full Duplex
        while(SPI1CON2bits.BUSY);
        SPI1CON2bits.TXR = 1;
        
        SST26VF064B_CS_High();
    }
    else {
        // Where to start from?
        DMASELECT = DMA6;
        DMAnSSA = flashAddr;

        // Read data from PFM one page at a time using DMA
        for(uint16_t i = numPages; i > 0; i--)
        {
            DBG(IO_RD3_SetHigh());
            PIR13bits.DMA6SCNTIF = 0;
            DMASELECT = DMA6;
            DMAnCON0bits.SIRQEN = 1;            // Enable auto-transfer
            DMAnSSA += GPR_PFM_BLOCK_SIZE;      // Update source pointer for next transfer
            while(PIR13bits.DMA6SCNTIF == 0);
            PIR13bits.DMA6SCNTIF = 0;
            DBG(IO_RD3_SetLow());
            
            // Break out if playback button is pressed again
            if(sw0_pressed) {
                sw0_pressed = false;
                break;
            }
        }
    }
    
    // Stop sampling timer
    TMR0_StopTimer();
    TMR0_Reload();
    LED0_TurnOff();
    
    // Disable DAC
    DAC1CONbits.EN = 0;
    
    // Disable PWM for power amplifier
    PWM2_16BIT_Disable();
    
    // Reset any lurking switch states
    ResetSwitches();
    
    // Change operation mode back to Idle
    mode = Idle;
    DBG(PrintChar('x'));
}

/**
 * @brief This routine services Passthrough mode
 * @return None
 * @param None
 * @example AUDIO_Playback();
 */
void AUDIO_Passthrough()
{
    DBG(PrintChar('T'));
    
    // Reset switch states
    ResetSwitches();
    
    // Select microphone input channel
    AUDIO_SelectMicInput();
    
    // Enable PWM for power amplifier
    PWM2_16BIT_Enable();
    
    // Enable ADC and DAC
    ADCON0bits.ON = 1;
    DAC1CONbits.EN = 1;
    
    // Reset relevant DMAs
    ResetDMA(0x00);     // DMA1 (ADC to DAC)
    
    // Reset and start sampling timer and DMA
    DMA1_StartTransferWithTrigger();
    TMR0_Reload();
    TMR0_StartTimer();
    LED0_TurnOn();
    
    // DMA1 kicks in and does the magic here
    
    // Continue until sw0 is pressed again
    while(!sw0_pressed);
    sw0_pressed = false;
    
    // Stop DMA and sampling timer
    DMA1_StopTransfer();
    TMR0_StopTimer();
    TMR0_Reload();
    LED0_TurnOff();
    
    // Disable ADC and DAC
    ADCON0bits.ON = 0;
    DAC1CONbits.EN = 0;
    
    // Disable PWM for power amplifier
    PWM2_16BIT_Disable();
    
    // Reset switch states
    ResetSwitches();
    
    // Change operation mode back to Idle
    mode = Idle;
    DBG(PrintChar('x'));
}


/**
 * @brief This routine initializes the application
 * @return None
 * @param None
 * @example APP_Initialize();
 */
void APP_Initialize()
{
    // Stop and reset sampling timer
    TMR0_StopTimer();
    TMR0_Reload();
    
    // Stop other timers as needed
    TMR1_StopTimer();
    
    // Disable ADC and DAC 
    ADCON0bits.ON = 0;
    DAC1CONbits.EN = 0;
    
    // Disable PWM for power amplifier
    PWM2_16BIT_Disable();
    
    // Reset all DMAs
    ResetAllDMA();
    
    // Reset all switches
    ResetSwitches();
    
    // Set custom Timer ISRs
    TMR0_SetInterruptHandler(TimerTick_ISR);
    TMR6_SetInterruptHandler(BlinkTimer_ISR);
    
    // Initialize external memory
    #if EXTMEM_ENABLE
    extMem = SST26VF064B_Initialize();
    if(extMem) {
        SST26VF064B_GlobalBlockUnlock();
    }
    #endif

    // Read metadata for stored audio
    AUDIO_ReadMetaData();

    // Clear all pages for storage // DO NOT CLEAR IF MEMORY IS TO BE RETAINED
    //AUDIO_Erase();
    
    // Set default operating mode
    mode = Idle;
}

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable high priority global interrupts
    INTERRUPT_GlobalInterruptHighEnable();

    // Enable low priority global interrupts.
    INTERRUPT_GlobalInterruptLowEnable();
    
    // Disable high priority global interrupts
    //INTERRUPT_GlobalInterruptHighDisable();

    // Disable low priority global interrupts.
    //INTERRUPT_GlobalInterruptLowDisable();
    
    
    //// APPLICATION CODE //////////////////////////////////////////////////////
    
    // Initialize application
    APP_Initialize();
    
    
    while (1)
    {
        if(mode == Idle) {
            AUDIO_Idle();
        }
        
        else if(mode == Record) {
            AUDIO_Record();
        }
        
        else if(mode == Playback) {
            AUDIO_Playback();
        }
        
        else if(mode == Erase) {
            AUDIO_Erase();
        }
        
        else if(mode == Passthrough) {
            AUDIO_Passthrough();
        }
        
        else {
            
        }
    }
}


/**
 End of File
*/