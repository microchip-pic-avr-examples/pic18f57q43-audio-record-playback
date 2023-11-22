/**
 * CLC1 Generated Driver API Header File.
 * 
 * @file clc1.h
 * 
 * @defgroup  clc1 CLC1
 * 
 * @brief This file contains the API prototypes for the CLC1 driver.
 *
 * @version CLC1 Driver Version 1.1.0
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

#ifndef CLC1_H
 #define CLC1_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define CLC1_Initialize  CLC1_Initialize
#define CLC1_Enable CLC1_Enable
#define CLC1_Disable CLC1_Disable
#define CLC1_ISR CLC1_ISR
#define CLC1_OutputStatusGet CLC1_OutputStatusGet
#define CLC1_CLCI_SetInterruptHandler CLC1_CLCI_SetInterruptHandler


/**
 * @ingroup clc1
 * @brief  Initializes the CLC1. This routine configures the CLC1 specific control registers.
 * @param None.
 * @return None.
 */
void CLC1_Initialize(void);

/**
 * @ingroup clc1
 * @brief Enables the CLC1 module.     
 * @param None.
 * @return None.
 */
void CLC1_Enable(void);

/**
 * @ingroup clc1
 * @brief Disables the CLC1 module.     
 * @param None.
 * @return None.
 */
void CLC1_Disable(void);


/**
 * @ingroup clc1
 * @brief Implements the Interrupt Service Routine (ISR) for the CLC interrupt events.
 * @pre CLC1_Initialize() is already called.
 * @param None.
 * @return None.
 */
void CLC1_ISR(void);
/**
 * @ingroup clc
 * @brief Sets the callback function for the interrupt event.
 * @param *InterruptHandler - Callback function for the interrupt event.
 * @return None.
*/
void CLC1_CLCI_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup clc1
 * @brief Returns the output pin status of the CLC module.
 * @param  None.
 * @retval True - Output is 1.
 * @retval False - Output is 0.
 */
bool CLC1_OutputStatusGet(void); 

#endif  // CLC1_H
/**
 End of File
*/

