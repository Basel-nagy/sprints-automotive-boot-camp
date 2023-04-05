/*
 * Led_Sequence_v1.0.c
 *
 * Created: 4/5/2023 1:23:16 PM
 * Author : basel
 */ 
#include "APPLICATION/app.h"


int main(void)
{   
   if(APP_INIT()==ok)
   {
	   while (1)
	   {
		   APP_START();
		   
	   } 
   }
   else
   {
	   //close the program
   }

   
   
}

