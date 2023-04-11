/*
 * main.c
 *
 * Created: 4/11/2023 2:24:01 AM
 *  Author: basel
 */ 
#include "APPLICATION/APP.h"
int main()
{
	if(APP_INIT()==ok)
	{
		while(1)
		{
			APP_START();
		}
		
	}
	else
	{
		//end the program
	}
}