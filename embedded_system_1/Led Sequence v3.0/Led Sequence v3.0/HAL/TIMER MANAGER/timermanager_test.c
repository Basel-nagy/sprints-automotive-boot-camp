/*
 * Led Sequence v3.0.c
 *
 * Created: 4/10/2023 2:28:30 AM
 * Author : basel
 */ 

//#include "application/APP.h"
/*#include "../../MCAL/DIO DRIVER/DIO.h"
#include "timer_manager.h"
volatile uint8_t ovr=0;
   ST_timerCFG_t timer_cfg;

void ovr_func(void);
int main(void)
{  
   timer_cfg.mode=normal;
   timer_cfg.interrupt=ENABLE;
   timer_cfg.init_value=246;
   timer_cfg.func_ptr=ovr_func;
   TIMER_MANAGER_CFG(&timer_cfg);
   DIO_INIT(porta,pin0,OUTPUT);
   sei();
   TIMER_MANAGER_STA(1024);
   while(1)
   {
	   
   }
    
}
void ovr_func(void)
{  timer_cfg.init_value=246;
	 TIMER_MANAGER_CFG(&timer_cfg);
	ovr++;
	
	if(ovr==1)
	DIO_WRITE_PIN(porta,pin0,HIGH);
	else if(ovr==2)
	{
		DIO_WRITE_PIN(porta,pin0,LOW);
		ovr=0;
	}
}*/

