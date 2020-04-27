/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
        Device            :  PIC18F57Q43
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_MIC_ANA0 aliases
#define channel_MIC_ANA0_TRIS                 TRISAbits.TRISA0
#define channel_MIC_ANA0_LAT                  LATAbits.LATA0
#define channel_MIC_ANA0_PORT                 PORTAbits.RA0
#define channel_MIC_ANA0_WPU                  WPUAbits.WPUA0
#define channel_MIC_ANA0_OD                   ODCONAbits.ODCA0
#define channel_MIC_ANA0_ANS                  ANSELAbits.ANSELA0
#define channel_MIC_ANA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_MIC_ANA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_MIC_ANA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_MIC_ANA0_GetValue()           PORTAbits.RA0
#define channel_MIC_ANA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_MIC_ANA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_MIC_ANA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_MIC_ANA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_MIC_ANA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define channel_MIC_ANA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define channel_MIC_ANA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define channel_MIC_ANA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()              PORTAbits.RA2
#define RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetPullup()             do { WPUAbits.WPUA2 = 1; } while(0)
#define RA2_ResetPullup()           do { WPUAbits.WPUA2 = 0; } while(0)
#define RA2_SetAnalogMode()         do { ANSELAbits.ANSELA2 = 1; } while(0)
#define RA2_SetDigitalMode()        do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISAbits.TRISA5
#define SW1_LAT                  LATAbits.LATA5
#define SW1_PORT                 PORTAbits.RA5
#define SW1_WPU                  WPUAbits.WPUA5
#define SW1_OD                   ODCONAbits.ODCA5
#define SW1_ANS                  ANSELAbits.ANSELA5
#define SW1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SW1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SW1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SW1_GetValue()           PORTAbits.RA5
#define SW1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SW1_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set RA7 procedures
#define RA7_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define RA7_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define RA7_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define RA7_GetValue()              PORTAbits.RA7
#define RA7_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define RA7_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define RA7_SetPullup()             do { WPUAbits.WPUA7 = 1; } while(0)
#define RA7_ResetPullup()           do { WPUAbits.WPUA7 = 0; } while(0)
#define RA7_SetAnalogMode()         do { ANSELAbits.ANSELA7 = 1; } while(0)
#define RA7_SetDigitalMode()        do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set IO_RB2 aliases
#define IO_RB2_TRIS                 TRISBbits.TRISB2
#define IO_RB2_LAT                  LATBbits.LATB2
#define IO_RB2_PORT                 PORTBbits.RB2
#define IO_RB2_WPU                  WPUBbits.WPUB2
#define IO_RB2_OD                   ODCONBbits.ODCB2
#define IO_RB2_ANS                  ANSELBbits.ANSELB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_RB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_RB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_RB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_RB2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set SST26VF064B_WP aliases
#define SST26VF064B_WP_TRIS                 TRISBbits.TRISB3
#define SST26VF064B_WP_LAT                  LATBbits.LATB3
#define SST26VF064B_WP_PORT                 PORTBbits.RB3
#define SST26VF064B_WP_WPU                  WPUBbits.WPUB3
#define SST26VF064B_WP_OD                   ODCONBbits.ODCB3
#define SST26VF064B_WP_ANS                  ANSELBbits.ANSELB3
#define SST26VF064B_WP_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define SST26VF064B_WP_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define SST26VF064B_WP_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define SST26VF064B_WP_GetValue()           PORTBbits.RB3
#define SST26VF064B_WP_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define SST26VF064B_WP_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define SST26VF064B_WP_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define SST26VF064B_WP_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define SST26VF064B_WP_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define SST26VF064B_WP_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define SST26VF064B_WP_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define SST26VF064B_WP_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set SW0 aliases
#define SW0_TRIS                 TRISBbits.TRISB4
#define SW0_LAT                  LATBbits.LATB4
#define SW0_PORT                 PORTBbits.RB4
#define SW0_WPU                  WPUBbits.WPUB4
#define SW0_OD                   ODCONBbits.ODCB4
#define SW0_ANS                  ANSELBbits.ANSELB4
#define SW0_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SW0_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SW0_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SW0_GetValue()           PORTBbits.RB4
#define SW0_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SW0_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SW0_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SW0_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SW0_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define SW0_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define SW0_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define SW0_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()              PORTBbits.RB5
#define RB5_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()             do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()           do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode()         do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RB5_SetDigitalMode()        do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC0 procedures
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()              PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()             do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()           do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetAnalogMode()         do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()        do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RC2_SetPullup()             do { WPUCbits.WPUC2 = 1; } while(0)
#define RC2_ResetPullup()           do { WPUCbits.WPUC2 = 0; } while(0)
#define RC2_SetAnalogMode()         do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RC2_SetDigitalMode()        do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set SST26VF064B_Hold aliases
#define SST26VF064B_Hold_TRIS                 TRISCbits.TRISC7
#define SST26VF064B_Hold_LAT                  LATCbits.LATC7
#define SST26VF064B_Hold_PORT                 PORTCbits.RC7
#define SST26VF064B_Hold_WPU                  WPUCbits.WPUC7
#define SST26VF064B_Hold_OD                   ODCONCbits.ODCC7
#define SST26VF064B_Hold_ANS                  ANSELCbits.ANSELC7
#define SST26VF064B_Hold_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define SST26VF064B_Hold_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define SST26VF064B_Hold_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define SST26VF064B_Hold_GetValue()           PORTCbits.RC7
#define SST26VF064B_Hold_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define SST26VF064B_Hold_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define SST26VF064B_Hold_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define SST26VF064B_Hold_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define SST26VF064B_Hold_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define SST26VF064B_Hold_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define SST26VF064B_Hold_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define SST26VF064B_Hold_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set IO_RD0 aliases
#define IO_RD0_TRIS                 TRISDbits.TRISD0
#define IO_RD0_LAT                  LATDbits.LATD0
#define IO_RD0_PORT                 PORTDbits.RD0
#define IO_RD0_WPU                  WPUDbits.WPUD0
#define IO_RD0_OD                   ODCONDbits.ODCD0
#define IO_RD0_ANS                  ANSELDbits.ANSELD0
#define IO_RD0_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_RD0_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_RD0_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_RD0_GetValue()           PORTDbits.RD0
#define IO_RD0_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_RD0_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_RD0_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define IO_RD0_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define IO_RD0_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define IO_RD0_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define IO_RD0_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define IO_RD0_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set IO_RD1 aliases
#define IO_RD1_TRIS                 TRISDbits.TRISD1
#define IO_RD1_LAT                  LATDbits.LATD1
#define IO_RD1_PORT                 PORTDbits.RD1
#define IO_RD1_WPU                  WPUDbits.WPUD1
#define IO_RD1_OD                   ODCONDbits.ODCD1
#define IO_RD1_ANS                  ANSELDbits.ANSELD1
#define IO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_GetValue()           PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RD1_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define IO_RD1_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define IO_RD1_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define IO_RD1_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define IO_RD1_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set IO_RD2 aliases
#define IO_RD2_TRIS                 TRISDbits.TRISD2
#define IO_RD2_LAT                  LATDbits.LATD2
#define IO_RD2_PORT                 PORTDbits.RD2
#define IO_RD2_WPU                  WPUDbits.WPUD2
#define IO_RD2_OD                   ODCONDbits.ODCD2
#define IO_RD2_ANS                  ANSELDbits.ANSELD2
#define IO_RD2_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_RD2_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_RD2_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_RD2_GetValue()           PORTDbits.RD2
#define IO_RD2_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_RD2_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_RD2_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define IO_RD2_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define IO_RD2_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define IO_RD2_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define IO_RD2_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define IO_RD2_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set IO_RD3 aliases
#define IO_RD3_TRIS                 TRISDbits.TRISD3
#define IO_RD3_LAT                  LATDbits.LATD3
#define IO_RD3_PORT                 PORTDbits.RD3
#define IO_RD3_WPU                  WPUDbits.WPUD3
#define IO_RD3_OD                   ODCONDbits.ODCD3
#define IO_RD3_ANS                  ANSELDbits.ANSELD3
#define IO_RD3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define IO_RD3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define IO_RD3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define IO_RD3_GetValue()           PORTDbits.RD3
#define IO_RD3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define IO_RD3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define IO_RD3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define IO_RD3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define IO_RD3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define IO_RD3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define IO_RD3_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define IO_RD3_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set RD5 procedures
#define RD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define RD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define RD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define RD5_GetValue()              PORTDbits.RD5
#define RD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define RD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define RD5_SetPullup()             do { WPUDbits.WPUD5 = 1; } while(0)
#define RD5_ResetPullup()           do { WPUDbits.WPUD5 = 0; } while(0)
#define RD5_SetAnalogMode()         do { ANSELDbits.ANSELD5 = 1; } while(0)
#define RD5_SetDigitalMode()        do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set SST26VF064B_CS aliases
#define SST26VF064B_CS_TRIS                 TRISDbits.TRISD6
#define SST26VF064B_CS_LAT                  LATDbits.LATD6
#define SST26VF064B_CS_PORT                 PORTDbits.RD6
#define SST26VF064B_CS_WPU                  WPUDbits.WPUD6
#define SST26VF064B_CS_OD                   ODCONDbits.ODCD6
#define SST26VF064B_CS_ANS                  ANSELDbits.ANSELD6
#define SST26VF064B_CS_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define SST26VF064B_CS_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define SST26VF064B_CS_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define SST26VF064B_CS_GetValue()           PORTDbits.RD6
#define SST26VF064B_CS_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define SST26VF064B_CS_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define SST26VF064B_CS_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define SST26VF064B_CS_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define SST26VF064B_CS_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define SST26VF064B_CS_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define SST26VF064B_CS_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define SST26VF064B_CS_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set RF0 procedures
#define RF0_SetHigh()            do { LATFbits.LATF0 = 1; } while(0)
#define RF0_SetLow()             do { LATFbits.LATF0 = 0; } while(0)
#define RF0_Toggle()             do { LATFbits.LATF0 = ~LATFbits.LATF0; } while(0)
#define RF0_GetValue()              PORTFbits.RF0
#define RF0_SetDigitalInput()    do { TRISFbits.TRISF0 = 1; } while(0)
#define RF0_SetDigitalOutput()   do { TRISFbits.TRISF0 = 0; } while(0)
#define RF0_SetPullup()             do { WPUFbits.WPUF0 = 1; } while(0)
#define RF0_ResetPullup()           do { WPUFbits.WPUF0 = 0; } while(0)
#define RF0_SetAnalogMode()         do { ANSELFbits.ANSELF0 = 1; } while(0)
#define RF0_SetDigitalMode()        do { ANSELFbits.ANSELF0 = 0; } while(0)

// get/set LED0 aliases
#define LED0_TRIS                 TRISFbits.TRISF3
#define LED0_LAT                  LATFbits.LATF3
#define LED0_PORT                 PORTFbits.RF3
#define LED0_WPU                  WPUFbits.WPUF3
#define LED0_OD                   ODCONFbits.ODCF3
#define LED0_ANS                  ANSELFbits.ANSELF3
#define LED0_SetHigh()            do { LATFbits.LATF3 = 1; } while(0)
#define LED0_SetLow()             do { LATFbits.LATF3 = 0; } while(0)
#define LED0_Toggle()             do { LATFbits.LATF3 = ~LATFbits.LATF3; } while(0)
#define LED0_GetValue()           PORTFbits.RF3
#define LED0_SetDigitalInput()    do { TRISFbits.TRISF3 = 1; } while(0)
#define LED0_SetDigitalOutput()   do { TRISFbits.TRISF3 = 0; } while(0)
#define LED0_SetPullup()          do { WPUFbits.WPUF3 = 1; } while(0)
#define LED0_ResetPullup()        do { WPUFbits.WPUF3 = 0; } while(0)
#define LED0_SetPushPull()        do { ODCONFbits.ODCF3 = 0; } while(0)
#define LED0_SetOpenDrain()       do { ODCONFbits.ODCF3 = 1; } while(0)
#define LED0_SetAnalogMode()      do { ANSELFbits.ANSELF3 = 1; } while(0)
#define LED0_SetDigitalMode()     do { ANSELFbits.ANSELF3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);




#endif // PIN_MANAGER_H
/**
 End of File
*/