#include "c8051F300.h"
#include <stdio.h>    
#include <float.h>


#define MAX_STEPS 7

sbit ENTRADA = P0^3;

sbit LED     = P0^2;

int contador = 0;

unsigned char entrada_old = 0; 
unsigned char entrada     = 0;
unsigned char power[MAX_STEPS] = {0,1,2,3,5,7,10};
unsigned char cnt         = 0;
unsigned char flag_int    = 0;

extern void Init_Device();

//--------------------------------------------------------------------------------------------
//TRATAMIENTO DE LAS INTERRUPCIONES
//--------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------
void int_timer0() interrupt 1   
{
   //actualizamos en pasos de 10.
   contador++;
   if (contador>9)
   {
      contador = 0;
      flag_int = 1;
   }

   if (contador<power[cnt])
   {
      LED = 1;
   }
   else
   {
      LED = 0;
   }
   
} 
 	
//----------------------------------------------------------------------------------------------------
void main (void) {

    Init_Device();

	while(1)
	{
	
		 entrada_old = (unsigned char)entrada;
		 entrada     = (unsigned char)ENTRADA;
	 
		 //cada pulsación, da más power
		 if((entrada==0)&&(entrada_old!=entrada)&&flag_int==1)
		 {
	         cnt++;
			 flag_int = 0;
			 if (cnt > MAX_STEPS-1)
			 	cnt = 0;
			 
		 }
	
	};


}//fin main

