/*
 * LED_Sequence_v2.0.c
 *
 * Created: 4/7/2023 4:25:40 PM
 * Author : basel
 */ 

/*#include "../../HAL/EXTERNAL_INTERRUPT_MANAGER/EXTERNAL_INT_MANAGER.h"

void bb(void);
int main(void)
{   
	ST_EXT_INT_HANDLER_t handler;
	handler.ext_int=int0;
	handler.edge_select=falling;
	handler.function_ptr=bb;
	EXT_INT_HANDLER(&handler);
	DDRA |=1<<0;
	sei();
    while (1) 
    {
    }
}

void bb(void)
{
	PORTA ^=1<<0;
}*/