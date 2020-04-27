/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
        Device            :  PIC18F57Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB             :  MPLAB X 5.30

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "pin_manager.h"





void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATF = 0x08;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x07;
    TRISF = 0xF6;
    TRISA = 0xFB;
    TRISB = 0xD7;
    TRISC = 0x2B;
    TRISD = 0x90;

    /**
    ANSELx registers
    */
    ANSELD = 0xB0;
    ANSELC = 0x16;
    ANSELB = 0x8B;
    ANSELE = 0x07;
    ANSELF = 0xF6;
    ANSELA = 0x5F;

    /**
    WPUx registers
    */
    WPUD = 0x00;
    WPUF = 0x00;
    WPUE = 0x00;
    WPUB = 0x10;
    WPUA = 0x20;
    WPUC = 0x00;

    /**
    RxyI2C registers
    */
    RB1I2C = 0x00;
    RB2I2C = 0x00;
    RC3I2C = 0x00;
    RC4I2C = 0x00;

    /**
    ODx registers
    */
    ODCONE = 0x00;
    ODCONF = 0x00;
    ODCONA = 0x00;
    ODCONB = 0x20;
    ODCONC = 0x00;
    ODCOND = 0x00;

    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x07;
    SLRCONF = 0xFF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0x0F;
    INLVLF = 0xFF;





   
    
	
    RB5PPS = 0x1A;   //RB5->PWM2_16BIT:PWM21;    
    RC4PPS = 0x32;   //RC4->SPI1:SDO1;    
    RC2PPS = 0x20;   //RC2->UART1:TX1;    
    PWM2ERSPPS = 0x10;   //RC0->PWM2_16BIT:PWM2ERS;    
    RF0PPS = 0x20;   //RF0->UART1:TX1;    
    U1RXPPS = 0x13;   //RC3->UART1:RX1;    
    PWMIN0PPS = 0x10;   //RC0->PWM2_16BIT:PWMIN0;    
    SPI1SCKPPS = 0x16;   //RC6->SPI1:SCK1;    
    RD5PPS = 0x2F;   //RD5->CMP1:C1OUT;    
    CLCIN0PPS = 0x07;   //RA7->CLC2:CLCIN0;    
    T2INPPS = 0x05;   //RA5->TMR2:T2IN;    
    RC6PPS = 0x31;   //RC6->SPI1:SCK1;    
    SPI1SDIPPS = 0x15;   //RC5->SPI1:SDI1;    
    T4INPPS = 0x0C;   //RB4->TMR4:T4IN;    
}
  
void PIN_MANAGER_IOC(void)
{   
}

/**
 End of File
*/