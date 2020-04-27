/**
  DMA6 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    dma6.c

  @Summary
    This is the generated driver implementation file for the DMA6 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for DMA6.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
        Device            :  PIC18F57Q43
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "dma6.h"


/**
  Section: DMA6 APIs
*/

void DMA6_Initialize(void)
{
    //DMA Instance Selection : 0x05
    DMASELECT = 0x05;
    //Source Address : 0x4000
    DMAnSSA = 0x4000;
    //Destination Address : &DAC1DATL
    DMAnDSA = &DAC1DATL;
    //DMODE unchanged; DSTP not cleared; SMR Program Flash; SMODE incremented; SSTP cleared; 
    DMAnCON1 = 0x0B;
    //Source Message Size : 256
    DMAnSSZ = 256;
    //Destination Message Size : 1
    DMAnDSZ = 1;
    //Start Trigger : SIRQ TMR0; 
    DMAnSIRQ = 0x1F;
    //Abort Trigger : AIRQ None; 
    DMAnAIRQ = 0x00;
	
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
	
    //EN enabled; SIRQEN enabled; DGO not in progress; AIRQEN disabled; 
    DMAnCON0 = 0xC0;
	
}

void DMA6_SelectSourceRegion(uint8_t region)
{
    DMASELECT = 0x05;
	DMAnCON1bits.SMR  = region;
}

void DMA6_SetSourceAddress(uint24_t address)
{
    DMASELECT = 0x05;
	DMAnSSA = address;
}

void DMA6_SetDestinationAddress(uint16_t address)
{
    DMASELECT = 0x05;
	DMAnDSA = address;
}

void DMA6_SetSourceSize(uint16_t size)
{
    DMASELECT = 0x05;
	DMAnSSZ= size;
}

void DMA6_SetDestinationSize(uint16_t size)
{                     
    DMASELECT = 0x05;
	DMAnDSZ= size;
}

uint24_t DMA6_GetSourcePointer(void)
{
    DMASELECT = 0x05;
	return DMAnSPTR;
}

uint16_t DMA6_GetDestinationPointer(void)
{
    DMASELECT = 0x05;
	return DMAnDPTR;
}

void DMA6_SetStartTrigger(uint8_t sirq)
{
    DMASELECT = 0x05;
	DMAnSIRQ = sirq;
}

void DMA6_SetAbortTrigger(uint8_t airq)
{
    DMASELECT = 0x05;
	DMAnAIRQ = airq;
}

void DMA6_StartTransfer(void)
{
    DMASELECT = 0x05;
	DMAnCON0bits.DGO = 1;
}

void DMA6_StartTransferWithTrigger(void)
{
    DMASELECT = 0x05;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA6_StopTransfer(void)
{
    DMASELECT = 0x05;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA6_SetDMAPriority(uint8_t priority)
{
    // This function is dependant on the PR1WAY CONFIG bit
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA6PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
}

/**
 End of File
*/
