/*
 * main.c
 *
 *  Created on: Apr 3, 2024
 *      Author: Ahmad
 */

#include "stdio.h"
#define EX_1 0
#define EX_2 0
#define EX_3 0
#define EX_4 0
#define EX_5 0
#define EX_6 0
#define EX_7 1
#define Frist_Solution 1
#define Second_Solution 0

void try_modify(int x,char text[])
{
	x++;
	text[0]--;
}


int main(void)
{
#if EX_1
#if Frist_Solution
	int number=0;
	printf("please enter number to check it: ");
	fflush(stdin);fflush(stdout);
	scanf(" %d",&number);
    if((number%2) ==0)
    {
    	printf("number is even");
    }
    else
    {
    	printf("number is odd");
    }
#endif
#if Second_Solution
    int number=0;
    printf("please enter number to check it: ");
    fflush(stdin);fflush(stdout);
    scanf(" %d",&number);
    ((number%2) ==0) ? printf("number is even"):printf("number is odd");
#endif
#endif
#if EX_2
    #if Frist_Solution
 	char letter;
	printf("please enter letter to check it: ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&letter);
    if(letter=="a" || letter=="A" || letter =="I" || letter =="i" || letter=="E" || letter=="e" || letter =="O" || letter =="o" || letter =="u" || letter =="U"  )
    {
    	printf("letter %c is vowel",letter);
    }
    else
    {
    	printf("letter %c is consonant",letter);
    }

   #endif
   #if Second_Solution
    char letter;
    printf("please enter letter to check it: ");
    fflush(stdin);fflush(stdout);
    scanf("%c",&letter);
    (letter=="a" || letter=="A" || letter =="I" || letter =="i" || letter=="E" || letter=="e" || letter =="O" || letter =="o" || letter =="u" || letter =="U") ? printf("letter %c is vowel",&letter):printf("letter %c is consonant",&letter);
  #endif
#endif
#if EX_7
    int v=5;
    char name[5]="Good";
    printf("v = %d , name= %s\n",v,name);
    try_modify(v,name);
    printf("v = %d , name= %s",v,name);

#endif
}




