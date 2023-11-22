/**
 * DMA4 Generated Driver API Header File.
 * 
 * @file dma4.h
 * 
 * @defgroup  dma4 DMA4
 * 
 * @brief This file contains the API prototypes for the Direct Memory Access (DMA) driver.
 *
 * @version DMA4 Driver Version 2.12.1
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

#ifndef DMA4_H
#define DMA4_H

/**
  Section: Included Files
*/
#include <stdint.h>

/**
 * @ingroup dma4
 * @name Classic API Name Macros
 * Macros used to map the APIs to the deprecated API names:
 */
///@{
#define DMA4_SelectSourceRegion            DMA4_SourceRegionSelect
#define DMA4_SetSourceAddress              DMA4_SourceAddressSet
#define DMA4_SetDestinationAddress         DMA4_DestinationAddressSet
#define DMA4_SetSourceSize                 DMA4_SourceSizeSet
#define DMA4_SetDestinationSize            DMA4_DestinationSizeSet
#define DMA4_GetSourcePointer              DMA4_SourcePointerGet
#define DMA4_GetDestinationPointer         DMA4_DestinationPointerGet
#define DMA4_SetStartTrigger               DMA4_StartTriggerSet
#define DMA4_SetAbortTrigger               DMA4_AbortTriggerSet
#define DMA4_StartTransfer                 DMA4_TransferStart
#define DMA4_StartTransferWithTrigger      DMA4_TransferWithTriggerStart
#define DMA4_StopTransfer                  DMA4_TransferStop
#define DMA4_SetDMAPriority                DMA4_DMAPrioritySet
///@}

/**
 * @ingroup dma4
 * @var uint8_t srcVarName4
 * @brief Source address.
 */
extern uint8_t srcVarName4[1];

/**
 * @ingroup dma4
 * @brief Initializes the DMA4 module. This is called only once before calling other DMA4 APIs.
 * @param None.
 * @return None. 
 */
void DMA4_Initialize(void);

/**
 * @ingroup dma4
 * @brief Enables the DMA4.
 * @param None.
 * @return None. 
 */
void DMA4_Enable(void);

/**
 * @ingroup dma4
 * @brief Disables the DMA4.
 * @param None.
 * @return None. 
 */
void DMA4_Disable(void);

/**
 * @ingroup dma4
 * @brief Sets the source region.
 * @param [in] region - Desired source region.
 * @return None.
 */
void DMA4_SourceRegionSelect(uint8_t region);

/**
 * @ingroup dma4
 * @brief Sets the source address for the DMA packet.
 * @param [in] address - Desired source address.
 * @return None.
 */
void DMA4_SourceAddressSet(uint24_t address);

/**
 * @ingroup dma4
 * @brief Returns the DMA Source Address.
 * @param None.
 * @return 24-bit DMA Source address.
 */
uint24_t DMA4_SourceAddressGet(void);

/**
 * @ingroup dma4
 * @brief Sets the destination address for the DMA packet.
 * @param [in] address - Desired destination address.
 * @return None.
 */
void DMA4_DestinationAddressSet(uint16_t address);

/**
 * @ingroup dma4
 * @brief Returns the DMA Destination Address.
 * @param None.
 * @return 16-bit DMA Destination address.
 */
uint16_t DMA4_DestinationAddressGet(void);

/**
 * @ingroup dma4
 * @brief Sets the size of the source array.
 * @param [in] size - Size of the source array in bytes.
 * @return None.
 */
void DMA4_SourceSizeSet(uint16_t size);

/**
 * @ingroup dma4
 * @brief Returns the DMA Source Message Size.
 * @param None.
 * @return 16-bit DMA Source message size value.
 */
uint16_t DMA4_SourceSizeGet(void);

/**
 * @ingroup dma4
 * @brief Sets the size of the destination array.
 * @param [in] size - Size of the destination array in bytes.
 * @return None.
 */
void DMA4_DestinationSizeSet(uint16_t size);

/**
 * @ingroup dma4
 * @brief Returns the DMA Destination Message Size.
 * @param None.
 * @return 16-bit DMA Destination message size value.
 */
uint16_t DMA4_DestinationSizeGet(void);

/**
 * @ingroup dma4
 * @brief Returns the current location read by the DMA.
 * @param None.
 * @return Current address pointer to the source.
 */
uint24_t DMA4_SourcePointerGet(void);

/**
 * @ingroup dma4
 * @brief Returns the current location written by the DMA.
 * @param None.
 * @return Current address pointer to the destination.
 */
uint16_t DMA4_DestinationPointerGet(void);

/**
 * @ingroup dma4
 * @brief Returns the DMA Source Count value.
 * @param None.
 * @return Current 16-bit source counter value.
 */
uint16_t DMA4_SourceCountGet(void);

/**
 * @ingroup dma4
 * @brief Returns the DMA Destination Count value.
 * @param None.
 * @return Current 16-bit destination counter value.
 */
uint16_t DMA4_DestinationCountGet(void);

/**
 * @ingroup dma4
 * @brief Sets the Start Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] sirq - Start trigger source.
 * @return None.
 */
void DMA4_StartTriggerSet(uint8_t sirq);

/**
 * @ingroup dma4
 * @brief Sets the Abort Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] airq - Abort trigger source.
 * @return None.
 */
void DMA4_AbortTriggerSet(uint8_t airq);

/**
 * @ingroup dma4
 * @brief Starts the DMA Transfer.
 * @param None.
 * @return None.
 */
void DMA4_TransferStart(void);

/**
 * @ingroup dma4
 * @brief Starts the DMA transfer based on the requested interrupt source.
 * @param None.
 * @return None.
 */
void DMA4_TransferWithTriggerStart(void);	

/**
 * @ingroup dma4
 * @brief Stops the DMA transfer.
 * @param None.
 * @return None.
 */
void DMA4_TransferStop(void);

/**
 * @ingroup dma4
 * @brief Sets the priority of the arbiter.
 * @param [in] priority - Priority of the DMA.
 * @return None.
 * NOTE: This function is dependent on the PR1WAY CONFIG bit.
 */
void DMA4_DMAPrioritySet(uint8_t priority);

#endif //DMA4_H