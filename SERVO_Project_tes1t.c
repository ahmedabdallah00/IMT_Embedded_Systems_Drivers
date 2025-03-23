#include <stdio.h>
#include <stdlib.h>
#include <pic16f877A.h>
#include <time.h>
#include <xc.h>

#pragma config FOSC=XT
#pragma config WDTE=OFF
#pragma config FOSC=OFF
#pragma config FOSC=OFF
#define _XTAL_FREQ= 6000000

void main() {
    TRISB=0x00;
    TRISA=0xFF;
    ADCON1=7;
    PORTB.B0=0;
    while(1)
    {
        PORTB.B0=1;
        __delay_MS(1000);
        PORTB.B0=0;
        __delay_ms(20);
        __delay_ms(1000);
        PORTB.B0=1;
        __delay_ms(1500);
        PORTB.B0=0;
        __delay_ms(20);
        __delay_ms(1000);
        PORTB.B0=1;
        __delay_ms(2000);
        PORTB.B0=0;
        __delay_ms(20);
        __delay_ms(1000);
        
    }
    
}

