/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.1.0
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

#include "../pins.h"


void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x0;
    LATD = 0x0;
    LATE = 0x0;
    LATF = 0x8;

    /**
    TRISx registers MCC GENERATED
    TRISA = 0xFB;
    TRISB = 0xD7;
    TRISC = 0x6B;
    TRISD = 0x90;
    TRISE = 0xF;
    TRISF = 0xF6;
    */
    
    
    TRISA = 0xFB;
    TRISB = 0xD7;
    TRISC = 0x2B;
    TRISD = 0x90;
    TRISE = 0x7;
    TRISF = 0xF6;

    /**
    ANSELx registers
    
    ANSELA = 0x5F;
    ANSELB = 0xCB;
    ANSELC = 0x17;
    ANSELD = 0xB0;
    ANSELE = 0x7;
    ANSELF = 0xF6;
    */
    ANSELA = 0x5F;
    ANSELB = 0x8B;
    ANSELC = 0x16;
    ANSELD = 0xB0;
    ANSELE = 0x7;
    ANSELF = 0xF6;
    
    /**
    WPUx registers
    */
    WPUA = 0x20;
    WPUB = 0x10;
    WPUC = 0x0;
    WPUD = 0x0;
    WPUE = 0x0;
    WPUF = 0x0;

    /**
    ODx registers
    */
    ODCONA = 0x0;
    ODCONB = 0x20;
    ODCONC = 0x0;
    ODCOND = 0x0;
    ODCONE = 0x0;
    ODCONF = 0x0;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x7;
    SLRCONF = 0xFF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0xF;
    INLVLF = 0xFF;

   /**
    RxyI2C | RxyFEAT registers   
    */
    RB1I2C = 0x0;
    RB2I2C = 0x0;
    RC3I2C = 0x0;
    RC4I2C = 0x0;
    /**
    PPS registers
    */
    U1RXPPS = 0x13; //RC3->UART1:RX1;
    T4INPPS = 0xC; //RB4->TMR4:T4IN;
    T2INPPS = 0x5; //RA5->TMR2:T2IN;
    CLCIN0PPS = 0x7; //RA7->CLC1:CLCIN0;
    SPI1SDIPPS = 0x15; //RC5->SPI1:SDI1;
    RC2PPS = 0x20;  //RC2->UART1:TX1;
    RF0PPS = 0x20;  //RF0->UART1:TX1;
    RD5PPS = 0x2F;  //RD5->CMP1:C1OUT;
    RC4PPS = 0x32;  //RC4->SPI1:SDO1;
    RB5PPS = 0x1A;  //RB5->PWM2_16BIT:PWM21;
    SPI1SCKPPS = 0x16;  //RC6->SPI1:SCK1;
    RC6PPS = 0x31;  //RC6->SPI1:SCK1;

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;


}
  
void PIN_MANAGER_IOC(void)
{
}
/**
 End of File
*/