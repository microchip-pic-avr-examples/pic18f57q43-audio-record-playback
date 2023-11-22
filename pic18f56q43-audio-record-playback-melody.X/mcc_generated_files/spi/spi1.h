/**
 * SPI1 Generated Driver API Header File
 *
 * @file spi1.h
 *
 * @defgroup spi1 SPI1
 *
 * @brief Contains the API Prototypes for the SPI1 driver.
 *
 * @version SPI1 Driver Version 2.0.1
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

#ifndef SPI1_H
#define SPI1_H

/**
 * Section: Included Files
 */ 

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "spi_interface.h"

/**
 * @ingroup spi1
 * @typedef enum spi1_modes_t
 * @brief Enumeration of the different configurations supported by the driver. A configuration is specified as parameter to SPI1_Open()
 *        and is used by the function to set SPI parameters as specified by the configuration.
 */
typedef enum 
{
    SPI1_DEFAULT
} spi1_modes_t;
             
extern const struct SPI_INTERFACE SPI1;

/**
 * @ingroup spi1
 * @brief Initializes the SPI module.
 * @param None.
 * @return None.
 */
void SPI1_Initialize(void);

/**
 * @ingroup spi1
 * @brief Sets the index of Configuration to use in the transfer.
 * @param uint8_t spiConfigIndex - Configuration index. See SPI1_configuration_name_t for configuration list.
 * @retval True  - SPI is open.
 * @retval False - SPI is not open.
 */
bool SPI1_Open(uint8_t spiConfigIndex);

/**
 * @ingroup spi1
 * @brief Closes the SPI for communication.
 * @param None.
 * @return None.
 */
void SPI1_Close(void);

/**
 * @ingroup spi1
 * @brief Exchanges one byte over SPI. Blocks until done.
 * @param uint8_t byteData - The byte to transfer.
 * @return uint8_t - Received data byte.
 */
uint8_t SPI1_ByteExchange(uint8_t byteData);

/**
 * @ingroup spi1
 * @brief Exchanges a buffer over SPI. Blocks if using polled driver.
 * @param[inout] void * bufferData The buffer to transfer. Received data is returned here.
 * @param[in] size_t bufferSize The size of buffer to transfer.
 * @return None.
 */
void SPI1_BufferExchange(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi1
 * @brief Writes a buffer over SPI. Blocks if using polled driver.
 * @param[in] void * bufferData The buffer to transfer.
 * @param[in] size_t bufferSize The size of buffer to transfer.
 * @return None.
 */
void SPI1_BufferWrite(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi1
 * @brief Reads a buffer over SPI. Blocks if using polled driver.
 * @param[out] void * bufferData Received data is written here.
 * @param[in] size_t bufferSize The size of buffer to transfer.
 * @return None.
 */
void SPI1_BufferRead(void * bufferData, size_t bufferSize);

/**
 * @ingroup spi1
 * @brief Writes a data byte to SPI.
 * @param uint8_t byteData The byte to transfer.
 * @return None.
 */
void SPI1_ByteWrite(uint8_t byteData);

/**
 * @ingroup spi1
 * @brief Gets the received data byte from SPI.
 * @param None.
 * @return uint8_t - The received data byte.
 */
uint8_t SPI1_ByteRead(void);

uint8_t __attribute__((deprecated)) SPI1_ExchangeByte(uint8_t data);
void __attribute__((deprecated)) SPI1_ExchangeBlock(void *block, size_t blockSize);
void __attribute__((deprecated)) SPI1_WriteBlock(void *block, size_t blockSize);
void __attribute__((deprecated)) SPI1_ReadBlock(void *block, size_t blockSize);
void __attribute__((deprecated)) SPI1_WriteByte(uint8_t byte);
uint8_t __attribute__((deprecated)) SPI1_ReadByte(void);

#endif //SPI1_H
