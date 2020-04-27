 /**
   CMP1 Generated Driver File
 
   @Company
     Microchip Technology Inc.
 
   @File Name
     cmp1.c
 
   @Summary
     This is the generated driver implementation file for the CMP1 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs
 
   @Description
     This source file provides implementations for driver APIs for CMP1.
     Generation Information :
         Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
         Device            :  PIC18F57Q43
         Driver Version    :  2.11
     The generated drivers are tested against the following:
         Compiler          :  XC8 2.10 and above or later
         MPLAB             :  MPLAB X 5.30
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
#include "cmp1.h"
/**
  Section: CMP1 APIs
*/

void CMP1_Initialize(void)
{

	// C1HYS disabled; C1EN enabled; C1POL not inverted; C1SYNC asynchronous;                          
    CM1CON0 = 0x80;
	
	// C1INTN no_intFlag; C1INTP no_intFlag;                          
    CM1CON1 = 0x00;
	
	// NCH CIN3-;                          
    CM1NCH = 0x03;
	
	// PCH DACOUT;                          
    CM1PCH = 0x05;
	
}

bool CMP1_GetOutputStatus(void)
{
	return (CM1CON0bits.C1OUT);
}


/**
 End of File
*/
