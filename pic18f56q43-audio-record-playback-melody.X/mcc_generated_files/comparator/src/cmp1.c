/**
 * CMP1 Generated Driver File.
 * 
 * @file cmp1.c
 * 
 * @ingroup cmp1
 * 
 * @brief This file contains the API implementation for the CMP1 driver.
 *
 * @version CMP1 Driver Version 2.13.1
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

#include <xc.h>
#include "../cmp1.h"

static void (*CMP1_InterruptHandler)(void);
static void CMP1_DefaultInterruptCallback(void);


void CMP1_Initialize(void) 
{
    // CHYS disabled; CON enabled; CPOL not inverted; CSYNC asynchronous; 
    CM1CON0 = 0x80;

    // CINTN no_intFlag; CINTP no_intFlag; 
    CM1CON1 = 0x0;
    
    // CNCH CIN3-; 
    CM1NCH = 0x3;
    
    // CPCH DACOUT; 
    CM1PCH = 0x5;    

    CMP1_InterruptCallbackRegister(CMP1_DefaultInterruptCallback);
}

void CMP1_Enable(void) 
{
    CM1CON0bits.C1EN = 1;
}

void CMP1_Disable(void) 
{
    CM1CON0bits.C1EN = 0;
}

bool CMP1_GetOutputStatus(void) 
{
    return CM1CON0bits.C1OUT; /* Note : As per datasheet, CxOUT bit in CMOUT register (if relevant) 
                                                   is mirror copy of CMxCON0.OUT */
}

void CMP1_ISR(void) 
{
    // Clear the CMP1 interrupt flag
    PIR1bits.C1IF = 0;

    if(CMP1_InterruptHandler)
    {
      CMP1_InterruptHandler();
    }
}

void CMP1_InterruptCallbackRegister(void(*callbackHandler)(void))
{
    if(NULL != callbackHandler)
    {
      CMP1_InterruptHandler = callbackHandler;
    }
}

static void CMP1_DefaultInterruptCallback(void)
{
    //Add your interrupt code here or
    //Use CMP1_InterruptCallbackRegister function to use Custom ISR

}