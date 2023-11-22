/**
 * TMR4 Generated Driver File
 *
 * @file tmr4.c
 * 
 * @ingroup  tmr4
 * 
 * @brief API implementations for the TMR4 module.
 *
 * @version TMR4 Driver Version 3.0.4
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
#include "../tmr4.h"

const struct TMR_INTERFACE Timer4 = {
    .Initialize = TMR4_Initialize,
    .Start = TMR4_Start,
    .Stop = TMR4_Stop,
    .PeriodCountSet = TMR4_PeriodCountSet,
    .TimeoutCallbackRegister = TMR4_OverflowCallbackRegister,
    .Tasks = TMR4_Tasks
};

static void (*TMR4_OverflowCallback)(void);
static void TMR4_DefaultOverflowCallback(void);

/**
  Section: TMR4 APIs
*/

void TMR4_Initialize(void){

    // Set TMR4 to the options selected in the User Interface
    // TCS MFINTOSC_31.25KHz; 
    T4CLKCON = 0x6;
    // TMODE Starts on rising/falling edge on TMR4_ers; TCKSYNC Not Synchronized; TCKPOL Rising Edge; TPSYNC Not Synchronized; 
    T4HLT = 0x13;
    // TRSEL T4CKIPPS pin; 
    T4RST = 0x0;
    // PR 234; 
    T4PR = 0xEA;
    // TMR 0x0; 
    T4TMR = 0x0;

    // Set default overflow callback
    TMR4_OverflowCallbackRegister(TMR4_DefaultOverflowCallback);

    // Clearing IF flag.
    PIR11bits.TMR4IF = 0;
    // TCKPS 1:4; TMRON on; TOUTPS 1:1; 
    T4CON = 0xA0;
}

void TMR4_ModeSet(TMR4_HLT_MODE mode)
{
   // Configure different types HLT mode
    T4HLTbits.T4MODE = mode;
}

void TMR4_ExtResetSourceSet(TMR4_HLT_EXT_RESET_SOURCE reset)
{
    //Configure different types of HLT external reset source
    T4RSTbits.T4RSEL = reset;
}

void TMR4_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T4CONbits.TMR4ON = 1;
}

void TMR4_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T4CONbits.TMR4ON = 0;
}

uint8_t TMR4_Read(void)
{
    uint8_t readVal;
    readVal = TMR4;
    return readVal;
}

void TMR4_Write(uint8_t timerVal)
{
    // Write to the Timer4 register
    TMR4 = timerVal;;
}

void TMR4_PeriodCountSet(size_t periodVal)
{
   PR4 = (uint8_t) periodVal;
}

void TMR4_OverflowCallbackRegister(void (* InterruptHandler)(void))
{
   TMR4_OverflowCallback = InterruptHandler;
}

static void TMR4_DefaultOverflowCallback(void)
{
    // add your TMR4 interrupt custom code
    // or set custom function using TMR4_OverflowCallbackRegister()
}

void TMR4_Tasks(void)
{
    if(PIR11bits.TMR4IF)
    {
        // Clearing IF flag.
        PIR11bits.TMR4IF = 0;
       TMR4_OverflowCallback();
    }
}

