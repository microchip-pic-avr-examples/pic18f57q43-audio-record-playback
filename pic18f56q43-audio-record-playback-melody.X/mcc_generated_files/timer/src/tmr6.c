/**
 * TMR6 Generated Driver File
 *
 * @file tmr6.c
 * 
 * @ingroup  tmr6
 * 
 * @brief API implementations for the TMR6 module.
 *
 * @version TMR6 Driver Version 3.0.4
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
#include "../tmr6.h"

const struct TMR_INTERFACE Timer6 = {
    .Initialize = TMR6_Initialize,
    .Start = TMR6_Start,
    .Stop = TMR6_Stop,
    .PeriodCountSet = TMR6_PeriodCountSet,
    .TimeoutCallbackRegister = TMR6_OverflowCallbackRegister,
    .Tasks = NULL
};

static void (*TMR6_OverflowCallback)(void);
static void TMR6_DefaultOverflowCallback(void);

/**
  Section: TMR6 APIs
*/

void TMR6_Initialize(void){

    // Set TMR6 to the options selected in the User Interface
    // TCS MFINTOSC_31.25KHz; 
    T6CLKCON = 0x6;
    // TMODE Software control; TCKSYNC Not Synchronized; TCKPOL Rising Edge; TPSYNC Not Synchronized; 
    T6HLT = 0x0;
    // TRSEL T6CKIPPS pin; 
    T6RST = 0x0;
    // PR 156; 
    T6PR = 0x9C;
    // TMR 0x0; 
    T6TMR = 0x0;

    // Set default overflow callback
    TMR6_OverflowCallbackRegister(TMR6_DefaultOverflowCallback);

    // Clearing IF flag before enabling the interrupt.
    PIR15bits.TMR6IF = 0;
    // Enabling TMR6 interrupt.
    PIE15bits.TMR6IE = 1;
    // TCKPS 1:16; TMRON on; TOUTPS 1:1; 
    //T6CON = 0xC0; MCC generated
    T6CON = 0x40;
}

void TMR6_ModeSet(TMR6_HLT_MODE mode)
{
   // Configure different types HLT mode
    T6HLTbits.T6MODE = mode;
}

void TMR6_ExtResetSourceSet(TMR6_HLT_EXT_RESET_SOURCE reset)
{
    //Configure different types of HLT external reset source
    T6RSTbits.T6RSEL = reset;
}

void TMR6_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T6CONbits.TMR6ON = 1;
}

void TMR6_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T6CONbits.TMR6ON = 0;
}

uint8_t TMR6_Read(void)
{
    uint8_t readVal;
    readVal = TMR6;
    return readVal;
}

void TMR6_Write(uint8_t timerVal)
{
    // Write to the Timer6 register
    TMR6 = timerVal;;
}

void TMR6_PeriodCountSet(size_t periodVal)
{
   PR6 = (uint8_t) periodVal;
}

void TMR6_ISR(void)
{
    // clear the TMR6 interrupt flag
     PIR15bits.TMR6IF = 0;

    // ticker function call;
    // ticker is 1 -> Callback function gets called everytime this ISR executes
    TMR6_OverflowCallback();
}

void TMR6_OverflowCallbackRegister(void (* InterruptHandler)(void))
{
   TMR6_OverflowCallback = InterruptHandler;
}

static void TMR6_DefaultOverflowCallback(void)
{
    // add your TMR6 interrupt custom code
    // or set custom function using TMR6_OverflowCallbackRegister()
}

