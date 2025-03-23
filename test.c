/*
 * File:   SERVO_Project_test.c
 * Author: DELL
 *
 * Created on May 15, 2023, 11:37 PM
 */
#include <stdio.h>
#include <stdlib.h>
#include <pic16f877A.h>
#include <time.h>
#include <xc.h>
#pragma config FOSC=XT
#pragma config WDTE=OFF
#pragma config PWRTE=OFF
#pragma config CP=OFF
#define _XTAL_FREQ= 6000000

void main() {
    TRISB=0x00;
    TRISA=0xFF;
    ADCON1=7;
    PORTB.B0=0;
    while(1)
    {
        if(PORTA.A0=1)
        {
            PORTB.B0=1;
            __delay_ms(1250);
            PORTB.B0=0;
            __delay_ms(1250);
            
        }
        if(PORTA.A1=1)
        {
            PORTB.B0=1;
            __delay_ms(1500);
            PORTB.B0=0;
            __delay_ms(1500);
            
        }
        if(PORTA.A2=1)
        {
            PORTB.B0=1;
            __delay_ms(1750);
            PORTB.B0=0;
            __delay_ms(1750);
            
        }
        
    }
    
}


