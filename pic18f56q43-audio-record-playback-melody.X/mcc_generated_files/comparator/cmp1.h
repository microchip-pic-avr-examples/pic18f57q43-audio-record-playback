/**
 * CMP1 Generated Driver API Header File.
 * 
 * @file cmp1.h
 * 
 * @defgroup cmp1 CMP1
 * 
 * @brief This file contains the API prototypes for the CMP1 module.
 *
 * @version CMP1 Driver Version 2.13.1
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

#ifndef CMP1_H
#define CMP1_H

#include <stdint.h>
#include <stdbool.h>



/**
 * @ingroup cmp1
 * @brief Initializes the CMP1 module. This is called only once during system initialization, and before calling other CMP1 APIs.
 * @param None.
 * @return None.
 */
void CMP1_Initialize(void);

/**
 * @ingroup cmp1
 * @brief Enables the CMP1 module.
 * @param None.
 * @return None.
 */
void CMP1_Enable(void);

/**
 * @ingroup cmp1
 * @brief Disables the CMP1 module.
 * @param None.
 * @return None.
 */
void CMP1_Disable(void);

/**
 * @ingroup cmp1
 * @brief Returns the CMP1 output status.
 * @pre CMP1_Initialize() is already called.
 * @param None.
 * @retval True - CMP1 output is high.
 * @retval False - CMP1 output is low.
 */
bool CMP1_GetOutputStatus(void); 

/**
 * @ingroup cmp1
 * @brief Implements the Interrupt Service Routine (ISR) for the CMP interrupt.
 * @param None.
 * @return None.
 */
void CMP1_ISR(void);

/**
 * @ingroup cmp1
 * @brief Setter function for comparator interrupt callback.
 * @param CallbackHandler - Pointer to the custom callback
 * @return None.
 */
void CMP1_InterruptCallbackRegister(void(*callbackHandler)(void));

#endif // CMP1_H
