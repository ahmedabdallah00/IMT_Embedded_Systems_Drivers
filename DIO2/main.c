/*
 * main.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Ahmad
 */
#include "stdio.h"
#include <avr/io.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#define EX1 0
#define EX2 0
#define EX3 0
#define SEGMENT7_EX1 0
#define comman_cathode 1
#define EX4 1

int main(void)
{
    DDRA=0xff; // PA -> OUTPT
    int number[]={
    		0b11111100,//0
			0b00001100,//1
			0b11011010,//2
			0b11110010,//3
			0b01100110,//4
			0b10110110,//5
			0b10111110,//6
			0b11100010,//7
			0b11111110,//8
			0b11111100,//9

                     };

    int number_hex[]={
        		0b11111100,//0
    			0b00001100,//1
    			0b11011010,//2
    			0b11110010,//3
    			0b01100110,//4
    			0b10110110,//5
    			0b10111110,//6
    			0b11100010,//7
    			0b11111110,//8
    			0b11111100,//9
                0b11101110,//A 10
				0b00111110,//B(samll)  11
				0b10011100,//C 12
				0b11111100,//D 13
				0b10011110,//E 14
				0b10001110,//F 15
                         };


	while(1)
	{

#if EX4
		SET_BIT(DDRA,0);// PA0 -> output
		CLR_BIT(DDRB,0);// PB0 -> input
		SET_BIT(PORTB,0);// connect pin PB0 to pull up resistor in microchip
		while(1)
		{
			if(GET_BIT(PINB,0)==0)
			{
				SET_BIT(PORTA,0);
			}
			else
			{
				CLR_BIT(PORTA,0);
			}
		}
#endif

#if SEGMENT7_EX1
#if comman_cathode
		for(int i=0;i<9;i++)
		{
			PORTA= number[i];
			_delay_ms(2000);
		}
//common anode
#else
		for(int i=0;i<9;i++)
		{
			PORTA= ~ (number[i]);
			_delay_ms(2000);
		}

#endif
#endif

//snake
#if EX1

		 for(int i=0;i<8;i++)
		 {

			SET_BIT(PORTA,i);
			_delay_ms(2000);

		 }

		 for(int i=0;i<8;i++)
		 {

			CLR_BIT(PORTA,i);
			_delay_ms(2000);

		 }
#endif

//flower
#if EX2
		 int k=7;
		 for(int i=0;i<k;i++)
		 {
			SET_BIT(PORTA,i);
			SET_BIT(PORTA,k);
			_delay_ms(2000);
			k--;
		 }
         k=k+4;
		 for(int i=0;i<k;i++)
		 {
			CLR_BIT(PORTA,i);
			CLR_BIT(PORTA,k);
			_delay_ms(2000);
			k--;
		 }
#endif



//ping pong
#if EX3
		 int k=7;
		 for(int i=0;i<k;i++)
		 {

			SET_BIT(PORTA,i);
			SET_BIT(PORTA,k);
			_delay_ms(2000);
			CLR_BIT(PORTA,i);
			CLR_BIT(PORTA,k);
			k--;

		 }

		 for(int i=3;i!=7;i++)
		 {

			SET_BIT(PORTA,i);
			SET_BIT(PORTA,k);
			_delay_ms(2000);
			CLR_BIT(PORTA,i);
			CLR_BIT(PORTA,k);
			k--;
		 }
#endif
	}
}
