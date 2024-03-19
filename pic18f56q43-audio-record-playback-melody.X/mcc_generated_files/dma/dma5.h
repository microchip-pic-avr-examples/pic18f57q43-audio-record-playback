/**
 * DMA5 Generated Driver API Header File.
 * 
 * @file dma5.h
 * 
 * @defgroup  dma5 DMA5
 * 
 * @brief This file contains the API prototypes for the Direct Memory Access (DMA) driver.
 *
 * @version DMA5 Driver Version 2.12.1
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

#ifndef DMA5_H
#define DMA5_H

/**
  Section: Included Files
*/
#include <stdint.h>

/**
 * @ingroup dma5
 * @name Classic API Name Macros
 * Macros used to map the APIs to the deprecated API names:
 */
///@{
#define DMA5_SelectSourceRegion            DMA5_SourceRegionSelect
#define DMA5_SetSourceAddress              DMA5_SourceAddressSet
#define DMA5_SetDestinationAddress         DMA5_DestinationAddressSet
#define DMA5_SetSourceSize                 DMA5_SourceSizeSet
#define DMA5_SetDestinationSize            DMA5_DestinationSizeSet
#define DMA5_GetSourcePointer              DMA5_SourcePointerGet
#define DMA5_GetDestinationPointer         DMA5_DestinationPointerGet
#define DMA5_SetStartTrigger               DMA5_StartTriggerSet
#define DMA5_SetAbortTrigger               DMA5_AbortTriggerSet
#define DMA5_StartTransfer                 DMA5_TransferStart
#define DMA5_StartTransferWithTrigger      DMA5_TransferWithTriggerStart
#define DMA5_StopTransfer                  DMA5_TransferStop
#define DMA5_SetDMAPriority                DMA5_DMAPrioritySet
///@}

/**
 * @ingroup dma5
 * @var uint8_t srcVarName5
 * @brief Source address.
 */
extern uint8_t srcVarName5[1];

/**
 * @ingroup dma5
 * @var uint8_t dstVarName5
 * @brief Destination address.
 */
extern uint8_t dstVarName5[1];

/**
 * @ingroup dma5
 * @brief Initializes the DMA5 module. This is called only once before calling other DMA5 APIs.
 * @param None.
 * @return None. 
 */
void DMA5_Initialize(void);

/**
 * @ingroup dma5
 * @brief Enables the DMA5.
 * @param None.
 * @return None. 
 */
void DMA5_Enable(void);

/**
 * @ingroup dma5
 * @brief Disables the DMA5.
 * @param None.
 * @return None. 
 */
void DMA5_Disable(void);

/**
 * @ingroup dma5
 * @brief Sets the source region.
 * @param [in] region - Desired source region.
 * @return None.
 */
void DMA5_SourceRegionSelect(uint8_t region);

/**
 * @ingroup dma5
 * @brief Sets the source address for the DMA packet.
 * @param [in] address - Desired source address.
 * @return None.
 */
void DMA5_SourceAddressSet(uint24_t address);

/**
 * @ingroup dma5
 * @brief Returns the DMA Source Address.
 * @param None.
 * @return 24-bit DMA Source address.
 */
uint24_t DMA5_SourceAddressGet(void);

/**
 * @ingroup dma5
 * @brief Sets the destination address for the DMA packet.
 * @param [in] address - Desired destination address.
 * @return None.
 */
void DMA5_DestinationAddressSet(uint16_t address);

/**
 * @ingroup dma5
 * @brief Returns the DMA Destination Address.
 * @param None.
 * @return 16-bit DMA Destination address.
 */
uint16_t DMA5_DestinationAddressGet(void);

/**
 * @ingroup dma5
 * @brief Sets the size of the source array.
 * @param [in] size - Size of the source array in bytes.
 * @return None.
 */
void DMA5_SourceSizeSet(uint16_t size);

/**
 * @ingroup dma5
 * @brief Returns the DMA Source Message Size.
 * @param None.
 * @return 16-bit DMA Source message size value.
 */
uint16_t DMA5_SourceSizeGet(void);

/**
 * @ingroup dma5
 * @brief Sets the size of the destination array.
 * @param [in] size - Size of the destination array in bytes.
 * @return None.
 */
void DMA5_DestinationSizeSet(uint16_t size);

/**
 * @ingroup dma5
 * @brief Returns the DMA Destination Message Size.
 * @param None.
 * @return 16-bit DMA Destination message size value.
 */
uint16_t DMA5_DestinationSizeGet(void);

/**
 * @ingroup dma5
 * @brief Returns the current location read by the DMA.
 * @param None.
 * @return Current address pointer to the source.
 */
uint24_t DMA5_SourcePointerGet(void);

/**
 * @ingroup dma5
 * @brief Returns the current location written by the DMA.
 * @param None.
 * @return Current address pointer to the destination.
 */
uint16_t DMA5_DestinationPointerGet(void);

/**
 * @ingroup dma5
 * @brief Returns the DMA Source Count value.
 * @param None.
 * @return Current 16-bit source counter value.
 */
uint16_t DMA5_SourceCountGet(void);

/**
 * @ingroup dma5
 * @brief Returns the DMA Destination Count value.
 * @param None.
 * @return Current 16-bit destination counter value.
 */
uint16_t DMA5_DestinationCountGet(void);

/**
 * @ingroup dma5
 * @brief Sets the Start Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] sirq - Start trigger source.
 * @return None.
 */
void DMA5_StartTriggerSet(uint8_t sirq);

/**
 * @ingroup dma5
 * @brief Sets the Abort Trigger for the DMA. Note that this function does not start the transfer.
 * @param [in] airq - Abort trigger source.
 * @return None.
 */
void DMA5_AbortTriggerSet(uint8_t airq);

/**
 * @ingroup dma5
 * @brief Starts the DMA Transfer.
 * @param None.
 * @return None.
 */
void DMA5_TransferStart(void);

/**
 * @ingroup dma5
 * @brief Starts the DMA transfer based on the requested interrupt source.
 * @param None.
 * @return None.
 */
void DMA5_TransferWithTriggerStart(void);	

/**
 * @ingroup dma5
 * @brief Stops the DMA transfer.
 * @param None.
 * @return None.
 */
void DMA5_TransferStop(void);

/**
 * @ingroup dma5
 * @brief Sets the priority of the arbiter.
 * @param [in] priority - Priority of the DMA.
 * @return None.
 * NOTE: This function is dependent on the PR1WAY CONFIG bit.
 */
void DMA5_DMAPrioritySet(uint8_t priority);

#endif //DMA5_H