/*
 * timertest.c
 *
 * Created: 4/11/2023 1:20:42 AM
 *  Author: basel
 */ 
/*#include"TIMER.h"
#include "../DIO DRIVER/DIO.h"
volatile uint8_t ovr=0;
void ovr_func(void);
int main()
{ EN_timermode_t timer_config=ctc;
	TIMER_INIT(&timer_config);
	TIMER_COMP_INT_ENABLE();
	COMP_VALUE(19);
	DIO_INIT(porta,pin0,OUTPUT);
	sei();
	TIMER_START(1024);
	TIMER_COMP_CALLBACK(ovr_func);
	while(1)
	{
		
	}
	
}
void ovr_func(void)
{ ovr++;
	
	if(ovr==1)
	DIO_WRITE_PIN(porta,pin0,HIGH);
	else if(ovr==2)
	{
			DIO_WRITE_PIN(porta,pin0,LOW);
   ovr=0;
	}
}*/