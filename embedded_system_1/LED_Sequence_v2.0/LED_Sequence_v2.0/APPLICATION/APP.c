/*
 * APP.c
 *
 * Created: 4/7/2023 4:29:34 PM
 *  Author: basel
 */ 
#include "APP.h"
static volatile uint8_t state=0;
static ST_EXT_INT_HANDLER_t handler;
STD_return APP_INIT(void)
{    STD_return ret_val=ok;
	LED LED1={porta,led1};
    LED LED2={porta,led2};
    LED LED3={porta,led3};
    LED LED4={porta,led4};
	ret_val |=LED_INIT(&LED1);
	ret_val |=LED_INIT(&LED2);
	ret_val |=LED_INIT(&LED3);
	ret_val |=LED_INIT(&LED4);
	handler.ext_int=int0;
	handler.edge_select=rising;
	handler.function_ptr=interrupt_func;
	ret_val |=EXT_INT_HANDLER(&handler);
	sei();
	return ret_val;
}
void APP_START(void)
{
	if(state==state_1)
	{
		LED_ON(porta,led1);
	}
	else if(state==state_2)
	{
		LED_ON(porta,led2);
	}
	else if(state==state_3)
	{
		LED_ON(porta,led3);
	}
	else if(state==state_4)
	{
		LED_ON(porta,led4);
	}
	else if(state==state_5)
	{
		LED_OFF(porta,led1);
	}
	else if(state==state_6)
	{
		LED_OFF(porta,led2);
	}
	else if(state==state_7)
	{
		LED_OFF(porta,led3);
	}
	else if(state==state_8)
	{
		LED_OFF(porta,led4);
	}
}


void interrupt_func(void)
{   
	if(state==state_8)
	{
		state=1;
	}
	else
	{
		state++;
	}
}