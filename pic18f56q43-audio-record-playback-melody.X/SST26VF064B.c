/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifdef __XC
#include <xc.h>
#endif
#include "SST26VF064B.h"
#include "mcc_generated_files/spi/spi1.h"
#include "mcc_generated_files/system/system.h"


void SST26VF064B_CS_Low(){
    SST26VF064B_CS_SetLow();
}

void SST26VF064B_CS_High(){
    SST26VF064B_CS_SetHigh();
}

void SST26VF064B_WP_Low(){
    SST26VF064B_WP_SetLow();
}

void SST26VF064B_WP_High(){
    SST26VF064B_WP_SetHigh();
}

void SST26VF064B_Hold( bool state )
{
    if( state )
        SST26VF064B_Hold_SetHigh();
    else
        SST26VF064B_Hold_SetLow();
}

void SST26VF064B_Command( SST26VF064B_cmd_t command )
{
    SPI1_ExchangeByte(command);
    
    
    return;
}

uint8_t SST26VF064B_Busy()
{
    uint8_t temp;

    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_RDSR );
    temp = SST26VF064B_SPI_ReadByte( 0 );
    SST26VF064B_CS_High();
    temp &= STATUS_BUSY;
    return temp;
}

uint8_t SST26VF064B_SPI_ReadByte( uint8_t value )
{
    value = SPI1_ExchangeByte( 0 );

    return value;
}

void SST26VF064B_SPI_WriteByte( uint8_t value )
{
    SPI1_ExchangeByte( value );

    return;
}

void SST26VF064B_SPI_ReadBuffer( uint8_t *buffer, uint16_t count )
{
    while( count-- )
    {   
        *( buffer++ ) = SPI1_ExchangeByte( 0x00 );
    }
    
    return;
}

void SST26VF064B_SPI_WriteBuffer( uint8_t *buffer, uint16_t count )
{
    while( count-- )
    {
        SPI1_ExchangeByte( *( buffer++ ) );          
    }

    return;
}

void SST26VF064B_Reset( void )
{
    while( SST26VF064B_Busy() );

    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_RSTEN );
    SST26VF064B_CS_High();
    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_RST );
    SST26VF064B_CS_High();

    return;
}

void SST26VF064B_WriteAddress( uint32_t address )
{    
    uint8_t addr_hi = address >> 16;
    uint8_t addr_mi = ( address & 0x00FF00 ) >> 8;
    uint8_t addr_lo = ( address & 0x0000FF );

    SPI1_ExchangeByte( addr_hi );
    SPI1_ExchangeByte( addr_mi );
    SPI1_ExchangeByte( addr_lo );
    
    return;
}

void SST26VF064B_SectorErase( uint32_t address )
{
    while( SST26VF064B_Busy() );

    SST26VF064B_WriteEnable();
    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_SE );
    SST26VF064B_WriteAddress( address );
    SST26VF064B_CS_High();

}

void SST26VF064B_BlockErase( uint32_t address )
{
    while( SST26VF064B_Busy() );

    SST26VF064B_WriteEnable();
    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_BE );
    SST26VF064B_WriteAddress( address );
    SST26VF064B_CS_High();

}

void SST26VF064B_ChipErase( void )
{
    while( SST26VF064B_Busy() );

    SST26VF064B_WriteEnable();
    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_CE );
    SST26VF064B_CS_High();
    return;
}

void SST26VF064B_Lock_BPR( void )
{
    while( SST26VF064B_Busy() );

    SST26VF064B_WriteEnable();
    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_LBPR );
    SST26VF064B_CS_High();

    return;
}

void SST26VF064B_GlobalBlockUnlock( void )
{
    while( SST26VF064B_Busy() );

    SST26VF064B_WriteEnable();
    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_ULBPR );
    SST26VF064B_CS_High();

    return;
}

void SST26VF064B_WriteEnable( void )
{
    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_WREN );
    SST26VF064B_CS_High();

    return;
}

void SST26VF064B_WriteDisable( void )
{
    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_WRDI );
    SST26VF064B_CS_High();
}

void SST26VF064B_WriteSuspend( void )
{
    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_WRSU );
    SST26VF064B_CS_High();
}

void SST26VF064B_WriteResume( void )
{
    SST26VF064B_CS_Low();
    SST26VF064B_Command( CMD_WRRE );
    SST26VF064B_CS_High();
}

void SST26VF064B_PageProgram_Cmd( void )
{
    SST26VF064B_Command( CMD_PP );
}

void SST26VF064B_Read_Cmd( void )
{
    SST26VF064B_Command( CMD_READ );
}

void SST26VF064B_JEDECID_Cmd( void )
{
    SST26VF064B_Command( CMD_JEDECID );
}

// Additional functions added

void SST26VF064B_GetDeviceInfo( SST26VF064B_info_t* info )
{
    // while( SST26VF064B_Busy() ); // Removed to prevent system hang at startup
    
    SST26VF064B_CS_Low();
    SST26VF064B_JEDECID_Cmd();
    SST26VF064B_SPI_ReadBuffer( (uint8_t*)info, 3 );
    SST26VF064B_CS_High();
}

bool SST26VF064B_Initialize()
{
    SST26VF064B_CS_High();
    SST26VF064B_WP_High();
    SST26VF064B_Hold(1);
    
    // SPI1_Initialize();   // Should have already been called by MCC
    SST26VF064B_info_t deviceInfo;
    SST26VF064B_GetDeviceInfo( &deviceInfo );
    
    // Verify JECEC-ID of SST26VF064B
    if(deviceInfo.manu_id == 0xBF && deviceInfo.device_type == 0x26 && deviceInfo.device_id == 0x43)    
        return true;
    
    return false;
}





