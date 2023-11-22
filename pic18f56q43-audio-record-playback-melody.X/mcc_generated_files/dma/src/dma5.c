/**
 * DMA5 Generated Driver File.
 * 
 * @file dma5.c
 * 
 * @ingroup  dma5
 * 
 * @brief This file contains the API implementations for the DMA5 driver.
 *
 * @version DMA5 Driver Version 2.12.1
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
#include "../dma5.h"

uint8_t srcVarName5[1];

uint8_t dstVarName5[1];

/**
  Section: DMA5 APIs
*/

void DMA5_Initialize(void)
{   
    
    //DMA Instance Selection : 0x4
    DMASELECT = 0x4;
    //Source Address : (uint24_t) &srcVarName5
    DMAnSSA = 0x0B00;//(uint24_t) &srcVarName5;
    //Destination Address : (uint16_t) &dstVarName5
    DMAnDSA = 0x2500;//(uint16_t) &dstVarName5;
    //SSTP not cleared; SMODE incremented; SMR GPR; DSTP not cleared; DMODE incremented; 
    DMAnCON1 = 0x42;
    //Source Message Size : 512
    DMAnSSZ = 512;
    //Destination Message Size : 256
    DMAnDSZ = 256;
    //Start Trigger : SIRQ None; 
    DMAnSIRQ = 0x0;
    //Abort Trigger : AIRQ None; 
    DMAnAIRQ = 0x0;
	
    // Clear Destination Count Interrupt Flag bit
    PIR12bits.DMA5DCNTIF = 0; 
    // Clear Source Count Interrupt Flag bit
    PIR12bits.DMA5SCNTIF = 0; 
    // Clear Abort Interrupt Flag bit
    PIR12bits.DMA5AIF = 0; 
    // Clear Overrun Interrupt Flag bit
    PIR12bits.DMA5ORIF =0; 
    
    PIE12bits.DMA5DCNTIE = 0;
    PIE12bits.DMA5SCNTIE = 0;
    PIE12bits.DMA5AIE = 0;
    PIE12bits.DMA5ORIE = 0;
	
    //AIRQEN disabled; DGO not in progress; SIRQEN disabled; EN enabled; 
    DMAnCON0 = 0x80;
	 
}

void DMA5_Enable(void)
{
    DMASELECT = 0x4;
    DMAnCON0bits.EN = 0x1;
}

void DMA5_Disable(void)
{
    DMASELECT = 0x4;
    DMAnCON0bits.EN = 0x0;
}

void DMA5_SourceRegionSelect(uint8_t region)
{
    DMASELECT = 0x4;
	DMAnCON1bits.SMR  = region;
}

void DMA5_SourceAddressSet(uint24_t address)
{
    DMASELECT = 0x4;
	DMAnSSA = address;
}

uint24_t DMA5_SourceAddressGet(void)
{
    DMASELECT = 0x4;
    return DMAnSSA;
}

void DMA5_DestinationAddressSet(uint16_t address)
{
    DMASELECT = 0x4;
	DMAnDSA = address;
}

uint16_t DMA5_DestinationAddressGet(void)
{
    DMASELECT = 0x4;
    return DMAnDSA;
}

void DMA5_SourceSizeSet(uint16_t size)
{
    DMASELECT = 0x4;
	DMAnSSZ= size;
}

uint16_t DMA5_SourceSizeGet(void)
{
    DMASELECT = 0x4;
    return DMAnSSZ;
}

void DMA5_DestinationSizeSet(uint16_t size)
{                     
    DMASELECT = 0x4;
	DMAnDSZ= size;
}

uint16_t DMA5_DestinationSizeGet(void)
{                     
    DMASELECT = 0x4;
    return DMAnDSZ;
}

uint24_t DMA5_SourcePointerGet(void)
{
    DMASELECT = 0x4;
	return DMAnSPTR;
}

uint16_t DMA5_DestinationPointerGet(void)
{
    DMASELECT = 0x4;
	return DMAnDPTR;
}

uint16_t DMA5_SourceCountGet(void)
{
    DMASELECT = 0x4;
    return DMAnSCNT;
}

uint16_t DMA5_DestinationCountGet(void)
{                     
    DMASELECT = 0x4;
    return DMAnDCNT;
}

void DMA5_StartTriggerSet(uint8_t sirq)
{
    DMASELECT = 0x4;
	DMAnSIRQ = sirq;
}

void DMA5_AbortTriggerSet(uint8_t airq)
{
    DMASELECT = 0x4;
	DMAnAIRQ = airq;
}

void DMA5_TransferStart(void)
{
    DMASELECT = 0x4;
	DMAnCON0bits.DGO = 1;
}

void DMA5_TransferWithTriggerStart(void)
{
    DMASELECT = 0x4;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA5_TransferStop(void)
{
    DMASELECT = 0x4;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA5_DMAPrioritySet(uint8_t priority)
{
    uint8_t GIESaveState = INTCON0bits.GIE;
    INTCON0bits.GIE = 0;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA5PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
    INTCON0bits.GIE = GIESaveState;
}

/**
 End of File
*/
