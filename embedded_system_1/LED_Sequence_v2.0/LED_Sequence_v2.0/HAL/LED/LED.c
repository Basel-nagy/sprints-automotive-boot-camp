/*
 * LED.c
 *
 * Created: 4/5/2023 1:59:35 PM
 *  Author: basel
 */ 

/************************************************************************/
/* including sections                                                   */
/************************************************************************/
#include "LED.h"

/************************************************************************/
/* functions implementations                                            */
/************************************************************************/
STD_return LED_INIT (LED* led)
{
	STD_return ret_val=ok;
	if(led==NULL)
	{
		ret_val=not_ok;
	}
	else
	{
		DIO_INIT(led->port,led->pin,OUTPUT);
	}
	
	return ret_val;
}
STD_return LED_ON (DIO_PORTS port, DIO_PINS pin)
{
	STD_return ret_val=ok;
	DIO_WRITE_PIN(port,pin,HIGH);
	return ret_val;
}
STD_return LED_OFF (DIO_PORTS port,DIO_PINS pin)
{
	STD_return ret_val=ok;
	DIO_WRITE_PIN(port,pin,LOW);
	return ret_val;
}