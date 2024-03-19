/**
 * CLC2 Generated Driver API Header File.
 * 
 * @file clc2.h
 * 
 * @defgroup  clc2 CLC2
 * 
 * @brief This file contains the API prototypes for the CLC2 driver.
 *
 * @version CLC2 Driver Version 1.1.0
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

#ifndef CLC2_H
 #define CLC2_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#define CLC2_Initialize  CLC2_Initialize
#define CLC2_Enable CLC2_Enable
#define CLC2_Disable CLC2_Disable
#define CLC2_ISR CLC2_ISR
#define CLC2_OutputStatusGet CLC2_OutputStatusGet
#define CLC2_CLCI_SetInterruptHandler CLC2_CLCI_SetInterruptHandler


/**
 * @ingroup clc2
 * @brief  Initializes the CLC2. This routine configures the CLC2 specific control registers.
 * @param None.
 * @return None.
 */
void CLC2_Initialize(void);

/**
 * @ingroup clc2
 * @brief Enables the CLC2 module.     
 * @param None.
 * @return None.
 */
void CLC2_Enable(void);

/**
 * @ingroup clc2
 * @brief Disables the CLC2 module.     
 * @param None.
 * @return None.
 */
void CLC2_Disable(void);


/**
 * @ingroup clc2
 * @brief Implements the Interrupt Service Routine (ISR) for the CLC interrupt events.
 * @pre CLC2_Initialize() is already called.
 * @param None.
 * @return None.
 */
void CLC2_ISR(void);
/**
 * @ingroup clc
 * @brief Sets the callback function for the interrupt event.
 * @param *InterruptHandler - Callback function for the interrupt event.
 * @return None.
*/
void CLC2_CLCI_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup clc2
 * @brief Returns the output pin status of the CLC module.
 * @param  None.
 * @retval True - Output is 1.
 * @retval False - Output is 0.
 */
bool CLC2_OutputStatusGet(void); 

#endif  // CLC2_H
/**
 End of File
*/

