/**
 * TMR1 Generated Driver API Header File
 *
 * @file tmr1.h
 *
 * @defgroup tmr1 TMR1
 *
 * @brief This file contains the API prototypes and other data types for the TMR1 driver.
 *
 * @version TMR1 Driver Version 3.1.4
*/
/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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

#ifndef TMR1_H
#define TMR1_H

#include <stdbool.h>
#include <stdint.h>
#include "timer_interface.h"


/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_Initialize API
 */
#define Timer1_Initialize TMR1_Initialize

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_Start API
 */
#define Timer1_Start TMR1_Start

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_Stop API
 */
#define Timer1_Stop TMR1_Stop

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_Read API
 */
#define Timer1_Read TMR1_Read

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_Write API
 */
#define Timer1_Write TMR1_Write

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_PeriodCountSet API
 */
#define Timer1_PeriodCountSet TMR1_PeriodCountSet

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_OverflowISR API
 */
#define Timer1_OverflowISR TMR1_OverflowISR

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_Reload API
 */
#define Timer1_Reload TMR1_Reload

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_GateCallbackRegister API
 */
#define Timer1_GateCallbackRegister TMR1_GateCallbackRegister

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_GateISR API
 */
#define Timer1_GateISR TMR1_GateISR

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_HasOverflowOccured API
 */
#define Timer1_HasOverflowOccured TMR1_HasOverflowOccured

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_CheckGateValueStatus API
 */
#define Timer1_CheckGateValueStatus TMR1_CheckGateValueStatus

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_StartSinglePulseAcquisition API
 */
#define Timer1_StartSinglePulseAcquisition TMR1_StartSinglePulseAcquisition

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_OverflowCallbackRegister API
 */
#define Timer1_OverflowCallbackRegister TMR1_OverflowCallbackRegister

/**
 * @ingroup tmr1
 * @brief Defines the Custom Name for the \ref TMR1_Tasks API
 */
#define Timer1_Tasks TMR1_Tasks


/**
 * @ingroup tmr1
 * @struct TMR_INTERFACE
 * @brief This is an instance of TMR_INTERFACE for Timer module
 */
extern const struct TMR_INTERFACE Timer1;

/**
 * @ingroup tmr1
 * @brief Initializes the timer module.
 *        This routine must be called before any other timer routines.
 * @param None.
 * @return None.
 */
void TMR1_Initialize(void);

/**
 * @ingroup tmr1
 * @brief Starts the timer.
 * @pre The timer should be initialized with TMR1_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR1_Start(void);

/**
 * @ingroup tmr1
 * @brief Stops the timer.
 * @pre The timer should be initialized with TMR1_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR1_Stop(void);

/**
 * @ingroup tmr1
 * @brief Reads the 16-bit from the TMR1 register.
 *        The Timer should be initialized with TMR1_Initialize() before calling this API.
 * @param None.
 * @return uint16_t - 16-bit data from the TMR1 register.
 */
uint16_t TMR1_Read(void);

/**
 * @ingroup tmr1
 * @brief Writes the 16-bit value to the TMR1 register.
 * @pre The timer should be initialized with TMR1_Initialize() before calling this API.
 * @param size_t timerVal - 16-bit value written to the TMR1 register.
 * @return None.
 */
void TMR1_Write(size_t timerVal);

/**
 * @ingroup tmr1
 * @brief Loads the 8-bit value to the TMR1 register.
 * @pre The timer should be initialized with TMR1_Initialize() before calling this API.
 * @param None.
 * @return None.
 */
void TMR1_Reload(void);

/**
 * @ingroup tmr1
 * @brief Loads the 16-bit value to the timer1ReloadVal variable.
 * @param periodVal - 16-bit value. 
 * @return None.
 */
void TMR1_PeriodCountSet(size_t periodVal);

/**
 * @ingroup tmr1
 * @brief Starts the single pulse acquisition in TMR1 gate operation.
 * @pre This function must be used when the TMR1 gate is enabled.
 * @param None.
 * @return None.
 */
void TMR1_StartSinglePulseAcquisition(void);

/**
 * @ingroup tmr1
 * @brief Reads the TMR1 gate value and returns it.
 * @pre This function must be used when the TMR1 gate is enabled.
 * @param None.
 * @return uint8_t - Gate value status.
 */
uint8_t TMR1_CheckGateValueStatus(void);


/**
 * @ingroup tmr1
 * @brief Setter function for the Timer overflow callback.
 * @param void (* CallbackHandler)(void) - Pointer to the custom callback.
 * @return None.
 */
 void TMR1_OverflowCallbackRegister(void (* CallbackHandler)(void));

/**
 * @ingroup tmr1
 * @brief Performs the tasks to be executed on timer overflow event.
 * @param None.
 * @return None.
 */
void TMR1_Tasks(void);

/**
 * @ingroup tmr1
 * @brief Checks for the timer overflow flag when in Polling mode.
 * @param None.
 * @retval true  - Timer overflow has occured.
 * @retval false - Timer overflow has not occured.
 */
bool TMR1_HasOverflowOccured(void);

/**
 * @ingroup tmr1
 * @brief Timer Gate Interrupt Service Routine (ISR) called by the Interrupt Manager.
 * @param None.
 * @return None.
 */
void TMR1_GateISR(void);

/**
 * @ingroup tmr1
 * @brief Setter function for the Timer gate callback.
 * @param void (* CallbackHandler)(void) - Pointer to the custom callback.
 * @return None.
 */
 void TMR1_GateCallbackRegister(void (* CallbackHandler)(void));

#endif // TMR1_H