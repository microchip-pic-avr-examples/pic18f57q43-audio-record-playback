/**
 * DMA6 Generated Driver API Header File.
 * 
 * @file dma6.h
 * 
 * @defgroup  dma6 DMA6
 * 
 * @brief This file contains the API prototypes for the Direct Memory Access (DMA) driver.
 *
 * @version DMA6 Driver Version 2.12.1
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

#ifndef DMA6_H
#define DMA6_H

/**
  Section: Included Files
*/
#include <stdint.h>

/**
 * @ingroup dma6
 * @name Classic API Name Macros
 * Macros used to map the APIs to the deprecated API names:
 */
///@{
#define DMA6_SelectSourceRegion            DMA6_SourceRegionSelect
#define DMA6_SetSourceAddress              DMA6_SourceAddressSet
#define DMA6_SetDestinationAddress         DMA6_DestinationAddressSet
#define DMA6_SetSourceSize                 DMA6_SourceSizeSet
#define DMA6_SetDestinationSize            DMA6_DestinationSizeSet
#define DMA6_GetSourcePointer              DMA6_SourcePointerGet
#define DMA6_GetDestinationPointer         DMA6_DestinationPointerGet
#define DMA6_SetStartTrigger               DMA6_StartTriggerSet
#define DMA6_SetAbortTrigger               DMA6_AbortTriggerSet
#define DMA6_StartTransfer                 DMA6_TransferStart
#define DMA6_StartTransferWithTrigger      DMA6_TransferWithTriggerStart
#define DMA6_StopTransfer                  DMA6_TransferStop
#define DMA6_SetDMAPriority                DMA6_DMAPrioritySet
///@}

/**
 * @ingroup dma6
 * @brief Initializes the DMA6 module. This is called only once before calling other DMA6 APIs.
 * @param None.
 * @return None. 
 */
void DMA6_Initialize(void);

/**
 * @ingroup dma6
 * @brief Enables the DMA6.
 * @param None.
 * @return None. 
 */
void DMA6_Enable(void);

/**
 * @ingroup dma6
 * @brief Disables the DMA6.
 * @param None.
 * @return None. 
 */
void DMA6_Disable(void);

/**
 * @ingroup dma6
 * @brief Sets the source region.
 * @param [in] region - Desired source region.
 * @return None.
 */
void DMA6_SourceRegionSelect(uint8_t region);

/**
 * @ingroup dma6
 * @brief Sets the source address for the DMA packet.
 * @param [in] address - Desired source address.
 * @return None.
 */
void DMA6_SourceAddressSet(uint24_t address);

/**
 * @ingroup dma6
 * @brief Returns the DMA Source Address.
 * @param None.
 * @return 24-bit DMA Source address.
 */
uint24_t DMA6_SourceAddressGet(void);

/**
 * @ingroup dma6
 * @brief Sets the destination address for the DMA packet.
 * @param [in] address - Desired destination address.
 * @return None.
 */
void DMA6_DestinationAddressSet(uint16_t address);

/**
 * @ingroup dma6
 * @brief Returns the DMA Destination Address.
 * @param None.
 * @return 16-bit DMA Destination address.
 */
uint16_t DMA6_DestinationAddressGet(void);

/**
 * @ingroup dma6
 * @brief Sets the size of the source array.
 * @param [in] size - Size of the source array in bytes.
 * @return None.
 */
void DMA6_SourceSizeSet(uint16_t size);

/**
 * @ingroup dma6
 * @brief Returns the DMA Source Message Size.
 * @param None.
 * @return 16-bit DMA Source message size value.
 */
uint16_t DMA6_SourceSizeGet(void);

/**
 * @ingroup dma6
 * @brief Sets the size of the destination array.
 * @param [in] size - Size of the destination array in bytes.
 * @return None.
 */
void DMA6_DestinationSizeSet(uint16_t size);

/**
 * @ingroup dma6
 * @brief Returns the DMA Destination Message Size.
 * @param None.
 * @return 16-bit DMA Destination message size value.
 */
uint16_t DMA6_DestinationSizeGet(void);

/**
 * @ingroup dma6
 * @brief Returns the current location read by the DMA.
 * @param None.
 * @return Current address pointer to the source.
 */
uint24_t DMA6_SourcePointerGet(void);

/**
 * @ingroup dma6
 * @brief Returns the current location written by the DMA.
 * @param None.
 * @return Current address pointer to the destination.
 */
uint16_t DMA6_DestinationPointerGet(void);

/**
 * @ingroup dma6
 * @brief Returns the DMA Source Count value.
 * @param None.
 * @return Current 16-bit source counter value.
 */
uint16_t DMA6_SourceCountGet(void);

/**
 * @ingroup dma6
 * @brief Returns the DMA Destination Count value.
 * @param None.
 * @return Current 16-bit destination counter value.
 */
uint16_t DMA6_DestinationCountGet(void);

/**
 * @ingroup dma6
 * @brief Sets the Start Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] sirq - Start trigger source.
 * @return None.
 */
void DMA6_StartTriggerSet(uint8_t sirq);

/**
 * @ingroup dma6
 * @brief Sets the Abort Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] airq - Abort trigger source.
 * @return None.
 */
void DMA6_AbortTriggerSet(uint8_t airq);

/**
 * @ingroup dma6
 * @brief Starts the DMA Transfer.
 * @param None.
 * @return None.
 */
void DMA6_TransferStart(void);

/**
 * @ingroup dma6
 * @brief Starts the DMA transfer based on the requested interrupt source.
 * @param None.
 * @return None.
 */
void DMA6_TransferWithTriggerStart(void);	

/**
 * @ingroup dma6
 * @brief Stops the DMA transfer.
 * @param None.
 * @return None.
 */
void DMA6_TransferStop(void);

/**
 * @ingroup dma6
 * @brief Sets the priority of the arbiter.
 * @param [in] priority - Priority of the DMA.
 * @return None.
 * NOTE: This function is dependent on the PR1WAY CONFIG bit.
 */
void DMA6_DMAPrioritySet(uint8_t priority);

#endif //DMA6_H