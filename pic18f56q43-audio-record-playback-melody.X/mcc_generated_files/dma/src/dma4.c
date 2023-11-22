/**
 * DMA4 Generated Driver File.
 * 
 * @file dma4.c
 * 
 * @ingroup  dma4
 * 
 * @brief This file contains the API implementations for the DMA4 driver.
 *
 * @version DMA4 Driver Version 2.12.1
 */ 

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

 /**
   Section: Included Files
 */

#include <xc.h>
#include "../dma4.h"

uint8_t srcVarName4[1];

/**
  Section: DMA4 APIs
*/

void DMA4_Initialize(void)
{   
    
    //DMA Instance Selection : 0x3
    DMASELECT = 0x3;
    //Source Address : (uint24_t) &srcVarName4
    DMAnSSA = 0x0B00; //(uint24_t) &srcVarName4;
    //Destination Address : (uint16_t) &SPI1TXB
    DMAnDSA = (uint16_t) &SPI1TXB;
    //SSTP cleared; SMODE incremented; SMR GPR; DSTP not cleared; DMODE unchanged; 
    DMAnCON1 = 0x3;
    //Source Message Size : 256
    DMAnSSZ = 256;
    //Destination Message Size : 1
    DMAnDSZ = 1;
    //Start Trigger : SIRQ SPI1TX; 
    DMAnSIRQ = 0x19;
    //Abort Trigger : AIRQ None; 
    DMAnAIRQ = 0x0;
	
    // Clear Destination Count Interrupt Flag bit
    PIR11bits.DMA4DCNTIF = 0; 
    // Clear Source Count Interrupt Flag bit
    PIR11bits.DMA4SCNTIF = 0; 
    // Clear Abort Interrupt Flag bit
    PIR11bits.DMA4AIF = 0; 
    // Clear Overrun Interrupt Flag bit
    PIR11bits.DMA4ORIF =0; 
    
    PIE11bits.DMA4DCNTIE = 0;
    PIE11bits.DMA4SCNTIE = 0;
    PIE11bits.DMA4AIE = 0;
    PIE11bits.DMA4ORIE = 0;
	
    //AIRQEN disabled; DGO not in progress; SIRQEN disabled; EN enabled; 
    DMAnCON0 = 0x80;
	 
}

void DMA4_Enable(void)
{
    DMASELECT = 0x3;
    DMAnCON0bits.EN = 0x1;
}

void DMA4_Disable(void)
{
    DMASELECT = 0x3;
    DMAnCON0bits.EN = 0x0;
}

void DMA4_SourceRegionSelect(uint8_t region)
{
    DMASELECT = 0x3;
	DMAnCON1bits.SMR  = region;
}

void DMA4_SourceAddressSet(uint24_t address)
{
    DMASELECT = 0x3;
	DMAnSSA = address;
}

uint24_t DMA4_SourceAddressGet(void)
{
    DMASELECT = 0x3;
    return DMAnSSA;
}

void DMA4_DestinationAddressSet(uint16_t address)
{
    DMASELECT = 0x3;
	DMAnDSA = address;
}

uint16_t DMA4_DestinationAddressGet(void)
{
    DMASELECT = 0x3;
    return DMAnDSA;
}

void DMA4_SourceSizeSet(uint16_t size)
{
    DMASELECT = 0x3;
	DMAnSSZ= size;
}

uint16_t DMA4_SourceSizeGet(void)
{
    DMASELECT = 0x3;
    return DMAnSSZ;
}

void DMA4_DestinationSizeSet(uint16_t size)
{                     
    DMASELECT = 0x3;
	DMAnDSZ= size;
}

uint16_t DMA4_DestinationSizeGet(void)
{                     
    DMASELECT = 0x3;
    return DMAnDSZ;
}

uint24_t DMA4_SourcePointerGet(void)
{
    DMASELECT = 0x3;
	return DMAnSPTR;
}

uint16_t DMA4_DestinationPointerGet(void)
{
    DMASELECT = 0x3;
	return DMAnDPTR;
}

uint16_t DMA4_SourceCountGet(void)
{
    DMASELECT = 0x3;
    return DMAnSCNT;
}

uint16_t DMA4_DestinationCountGet(void)
{                     
    DMASELECT = 0x3;
    return DMAnDCNT;
}

void DMA4_StartTriggerSet(uint8_t sirq)
{
    DMASELECT = 0x3;
	DMAnSIRQ = sirq;
}

void DMA4_AbortTriggerSet(uint8_t airq)
{
    DMASELECT = 0x3;
	DMAnAIRQ = airq;
}

void DMA4_TransferStart(void)
{
    DMASELECT = 0x3;
	DMAnCON0bits.DGO = 1;
}

void DMA4_TransferWithTriggerStart(void)
{
    DMASELECT = 0x3;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA4_TransferStop(void)
{
    DMASELECT = 0x3;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA4_DMAPrioritySet(uint8_t priority)
{
    uint8_t GIESaveState = INTCON0bits.GIE;
    INTCON0bits.GIE = 0;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA4PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
    INTCON0bits.GIE = GIESaveState;
}

/**
 End of File
*/
