/*
 * button.c
 *
 * Created: 4/5/2023 2:14:14 PM
 *  Author: basel
 */ 
#include "button.h"
/************************************************************************/
/* functions implementations                                            */
/************************************************************************/
STD_return BUTTON_INIT (BUTTON*  button)
{   STD_return ret_val=ok;
	if(button==NULL)
	{
		ret_val=not_ok;
	}
	else
	{
		DIO_INIT(button->port,button->pin,INPUT);
	}
	
	return ret_val;
}
STD_return BUTTON_READ (DIO_PORTS port, DIO_PINS pin, EN_BUTTON_STATE_t* value)
{
	 STD_return ret_val=ok;
	 DIO_READ_PIN(port,pin,value);
	 return ret_val;
}