/**
 * DMA6 Generated Driver File.
 * 
 * @file dma6.c
 * 
 * @ingroup  dma6
 * 
 * @brief This file contains the API implementations for the DMA6 driver.
 *
 * @version DMA6 Driver Version 2.12.1
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
#include "../dma6.h"

/**
  Section: DMA6 APIs
*/

void DMA6_Initialize(void)
{   
    
    //DMA Instance Selection : 0x5
    DMASELECT = 0x5;
    //Source Address : 0x4000
    DMAnSSA = 0x4500;
    //Destination Address : (uint16_t) &DAC1DATL
    DMAnDSA = (uint16_t) &DAC1DATL;
    //SSTP cleared; SMODE incremented; SMR Program Flash; DSTP not cleared; DMODE unchanged; 
    DMAnCON1 = 0xB;
    //Source Message Size : 256
    DMAnSSZ = 256;
    //Destination Message Size : 1
    DMAnDSZ = 1;
    //Start Trigger : SIRQ TMR0; 
    DMAnSIRQ = 0x1F;
    //Abort Trigger : AIRQ None; 
    DMAnAIRQ = 0x0;
	
    // Clear Destination Count Interrupt Flag bit
    PIR13bits.DMA6DCNTIF = 0; 
    // Clear Source Count Interrupt Flag bit
    PIR13bits.DMA6SCNTIF = 0; 
    // Clear Abort Interrupt Flag bit
    PIR13bits.DMA6AIF = 0; 
    // Clear Overrun Interrupt Flag bit
    PIR13bits.DMA6ORIF =0; 
    
    PIE13bits.DMA6DCNTIE = 0;
    PIE13bits.DMA6SCNTIE = 0;
    PIE13bits.DMA6AIE = 0;
    PIE13bits.DMA6ORIE = 0;
	
    //AIRQEN disabled; DGO not in progress; SIRQEN enabled; EN enabled; 
    DMAnCON0 = 0xC0;
	 
}

void DMA6_Enable(void)
{
    DMASELECT = 0x5;
    DMAnCON0bits.EN = 0x1;
}

void DMA6_Disable(void)
{
    DMASELECT = 0x5;
    DMAnCON0bits.EN = 0x0;
}

void DMA6_SourceRegionSelect(uint8_t region)
{
    DMASELECT = 0x5;
	DMAnCON1bits.SMR  = region;
}

void DMA6_SourceAddressSet(uint24_t address)
{
    DMASELECT = 0x5;
	DMAnSSA = address;
}

uint24_t DMA6_SourceAddressGet(void)
{
    DMASELECT = 0x5;
    return DMAnSSA;
}

void DMA6_DestinationAddressSet(uint16_t address)
{
    DMASELECT = 0x5;
	DMAnDSA = address;
}

uint16_t DMA6_DestinationAddressGet(void)
{
    DMASELECT = 0x5;
    return DMAnDSA;
}

void DMA6_SourceSizeSet(uint16_t size)
{
    DMASELECT = 0x5;
	DMAnSSZ= size;
}

uint16_t DMA6_SourceSizeGet(void)
{
    DMASELECT = 0x5;
    return DMAnSSZ;
}

void DMA6_DestinationSizeSet(uint16_t size)
{                     
    DMASELECT = 0x5;
	DMAnDSZ= size;
}

uint16_t DMA6_DestinationSizeGet(void)
{                     
    DMASELECT = 0x5;
    return DMAnDSZ;
}

uint24_t DMA6_SourcePointerGet(void)
{
    DMASELECT = 0x5;
	return DMAnSPTR;
}

uint16_t DMA6_DestinationPointerGet(void)
{
    DMASELECT = 0x5;
	return DMAnDPTR;
}

uint16_t DMA6_SourceCountGet(void)
{
    DMASELECT = 0x5;
    return DMAnSCNT;
}

uint16_t DMA6_DestinationCountGet(void)
{                     
    DMASELECT = 0x5;
    return DMAnDCNT;
}

void DMA6_StartTriggerSet(uint8_t sirq)
{
    DMASELECT = 0x5;
	DMAnSIRQ = sirq;
}

void DMA6_AbortTriggerSet(uint8_t airq)
{
    DMASELECT = 0x5;
	DMAnAIRQ = airq;
}

void DMA6_TransferStart(void)
{
    DMASELECT = 0x5;
	DMAnCON0bits.DGO = 1;
}

void DMA6_TransferWithTriggerStart(void)
{
    DMASELECT = 0x5;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA6_TransferStop(void)
{
    DMASELECT = 0x5;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA6_DMAPrioritySet(uint8_t priority)
{
    uint8_t GIESaveState = INTCON0bits.GIE;
    INTCON0bits.GIE = 0;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA6PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
    INTCON0bits.GIE = GIESaveState;
}

/**
 End of File
*/
