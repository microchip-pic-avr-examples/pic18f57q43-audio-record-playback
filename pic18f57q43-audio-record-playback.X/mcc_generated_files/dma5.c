/**
  DMA5 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    dma5.c

  @Summary
    This is the generated driver implementation file for the DMA5 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This source file provides APIs for DMA5.
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
#include "dma5.h"


/**
  Section: DMA5 APIs
*/

void DMA5_Initialize(void)
{
    //DMA Instance Selection : 0x04
    DMASELECT = 0x04;
    //Source Address : SrcVarName4
    DMAnSSA = 0x0B00; //&SrcVarName4;
    //Destination Address : &DstVarName4
    DMAnDSA= 0x2500; //&DstVarName4;
    //DMODE incremented; DSTP not cleared; SMR GPR; SMODE incremented; SSTP not cleared; 
    DMAnCON1 = 0x42;
    //Source Message Size : 512
    DMAnSSZ = 512;
    //Destination Message Size : 256
    DMAnDSZ = 256;
    //Start Trigger : SIRQ None; 
    DMAnSIRQ = 0x00;
    //Abort Trigger : AIRQ None; 
    DMAnAIRQ = 0x00;
	
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
	
    //EN enabled; SIRQEN disabled; DGO not in progress; AIRQEN disabled; 
    DMAnCON0 = 0x80;
	
}

void DMA5_SelectSourceRegion(uint8_t region)
{
    DMASELECT = 0x04;
	DMAnCON1bits.SMR  = region;
}

void DMA5_SetSourceAddress(uint24_t address)
{
    DMASELECT = 0x04;
	DMAnSSA = address;
}

void DMA5_SetDestinationAddress(uint16_t address)
{
    DMASELECT = 0x04;
	DMAnDSA = address;
}

void DMA5_SetSourceSize(uint16_t size)
{
    DMASELECT = 0x04;
	DMAnSSZ= size;
}

void DMA5_SetDestinationSize(uint16_t size)
{                     
    DMASELECT = 0x04;
	DMAnDSZ= size;
}

uint24_t DMA5_GetSourcePointer(void)
{
    DMASELECT = 0x04;
	return DMAnSPTR;
}

uint16_t DMA5_GetDestinationPointer(void)
{
    DMASELECT = 0x04;
	return DMAnDPTR;
}

void DMA5_SetStartTrigger(uint8_t sirq)
{
    DMASELECT = 0x04;
	DMAnSIRQ = sirq;
}

void DMA5_SetAbortTrigger(uint8_t airq)
{
    DMASELECT = 0x04;
	DMAnAIRQ = airq;
}

void DMA5_StartTransfer(void)
{
    DMASELECT = 0x04;
	DMAnCON0bits.DGO = 1;
}

void DMA5_StartTransferWithTrigger(void)
{
    DMASELECT = 0x04;
	DMAnCON0bits.SIRQEN = 1;
}

void DMA5_StopTransfer(void)
{
    DMASELECT = 0x04;
	DMAnCON0bits.SIRQEN = 0; 
	DMAnCON0bits.DGO = 0;
}

void DMA5_SetDMAPriority(uint8_t priority)
{
    // This function is dependant on the PR1WAY CONFIG bit
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 0;
	DMA5PR = priority;
	PRLOCK = 0x55;
	PRLOCK = 0xAA;
	PRLOCKbits.PRLOCKED = 1;
}

/**
 End of File
*/
