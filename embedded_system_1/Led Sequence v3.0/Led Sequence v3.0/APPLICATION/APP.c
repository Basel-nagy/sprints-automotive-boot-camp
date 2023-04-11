/*
 * APP.c
 *
 * Created: 4/7/2023 4:29:34 PM
 *  Author: basel
 */ 
#include "APP.h"
static volatile uint8_t ovf=0;
static volatile EN_states_t state=0;
static volatile EN_blink_state_t blink_state=BLINK_1;
static ST_EXT_INT_HANDLER_t hanlder_1;
static ST_EXT_INT_HANDLER_t hanlder_2;
static ST_timerCFG_t timer;
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
	hanlder_1.ext_int=int0;
	hanlder_1.edge_select=rising;
	hanlder_1.function_ptr=INT0_func;
	hanlder_2.ext_int=int1;
	hanlder_2.edge_select=rising;
	hanlder_2.function_ptr=INT1_func;
	ret_val|=EXT_INT_HANDLER(&hanlder_1);
	ret_val|=EXT_INT_HANDLER(&hanlder_2);
	timer.mode=ctc;
	timer.interrupt=ENABLE;
	timer.init_value=97;
	timer.func_ptr=timer_comp;
	ret_val|=TIMER_MANAGER_CFG (&timer);
	sei();
	return ret_val;
}
void APP_START(void)
{/************************************************************************/
/* state_1                                                                     */
/************************************************************************/
	if(state==state_1)
	{
		if(blink_state==BLINK_1)
		{
			while(blink_state==BLINK_1 && state==state_1)
			{
				if(ovf<ms_100)
				{
					LED_ON(porta,led1);
				}
				else if(ovf>=ms_100)
				{
					LED_OFF(porta,led1);
				}
			}
		}
		else if(blink_state==BLINK_2)
		{
			while(blink_state==BLINK_2 && state==state_1)
			{
				if(ovf<ms_200)
				{
					LED_ON(porta,led1);
				}
				else if(ovf>=ms_200)
				{
					LED_OFF(porta,led1);
				}
			}
		}
		else if(blink_state==BLINK_3)
		{
			while(blink_state==BLINK_3 && state==state_1)
			{
				if(ovf<ms_300)
				{
					LED_ON(porta,led1);
				}
				else if(ovf>=ms_300)
				{
					LED_OFF(porta,led1);
				}
			}
		}
		else if(blink_state==BLINK_4)
		{
			while(blink_state==BLINK_4 && state==state_1)
			{
				if(ovf<ms_500)
				{
					LED_ON(porta,led1);
				}
				else if(ovf>=ms_500)
				{
					LED_OFF(porta,led1);
				}
			}
		}
		else if(blink_state==BLINK_5)
		{
			while(blink_state==BLINK_5 && state==state_1)
			{
				if(ovf<ms_800)
				{
					LED_ON(porta,led1);
				}
				else if(ovf>=ms_800)
				{
					LED_OFF(porta,led1);
				}
			}
		}
	}
	/************************************************************************/
	/*       state_2                                                               */
	/************************************************************************/
	else if(state==state_2)
	{
		if(blink_state==BLINK_1)
		{
			while(blink_state==BLINK_1 && state==state_2)
			{
				if(ovf<ms_100)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
				}
				else if(ovf>=ms_100)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
				}
			}
		}
		else if(blink_state==BLINK_2)
		{
			while(blink_state==BLINK_2 && state==state_2)
			{
				if(ovf<ms_200)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
				}
				else if(ovf>=ms_200)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
				}
			}
		}
		else if(blink_state==BLINK_3)
		{
			while(blink_state==BLINK_3 && state==state_2)
			{
				if(ovf<ms_300)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
				}
				else if(ovf>=ms_300)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
				}
			}
		}
		else if(blink_state==BLINK_4)
		{
			while(blink_state==BLINK_4 && state==state_2)
			{
				if(ovf<ms_500)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
				}
				else if(ovf>=ms_500)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
				}
			}
		}
		else if(blink_state==BLINK_5)
		{
			while(blink_state==BLINK_5 && state==state_2)
			{
				if(ovf<ms_800)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
				}
				else if(ovf>=ms_800)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
				}
			}
		}
	}
	/************************************************************************/
	/*     state_3                                                                 */
	/************************************************************************/
	else if(state==state_3)
	{
		if(blink_state==BLINK_1)
		{
			while(blink_state==BLINK_1 && state==state_3)
			{
				if(ovf<ms_100)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
					LED_ON(porta,led3);
				}
				else if(ovf>=ms_100)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
				}
			}
		}
		else if(blink_state==BLINK_2)
		{
			while(blink_state==BLINK_2 && state==state_3)
			{
				if(ovf<ms_200)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
					LED_ON(porta,led3);

				}
				else if(ovf>=ms_200)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);

				}
			}
		}
		else if(blink_state==BLINK_3)
		{
			while(blink_state==BLINK_3 && state==state_3)
			{
				if(ovf<ms_300)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
					LED_ON(porta,led3);
				}
				else if(ovf>=ms_300)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
				}
			}
		}
		else if(blink_state==BLINK_4)
		{
			while(blink_state==BLINK_4 && state==state_3)
			{
				if(ovf<ms_500)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
					LED_ON(porta,led3);
				}
				else if(ovf>=ms_500)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
				}
			}
		}
		else if(blink_state==BLINK_5)
		{
			while(blink_state==BLINK_5 && state==state_3)
			{
				if(ovf<ms_800)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
					LED_ON(porta,led3);
				}
				else if(ovf>=ms_800)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
				}
			}
		}
	}
	/************************************************************************/
	/* state_4                                                                     */
	/************************************************************************/
	else if(state==state_4)
	{
		if(blink_state==BLINK_1)
		{
			while(blink_state==BLINK_1 && state==state_4)
			{
				if(ovf<ms_100)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_100)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_2)
		{
			while(blink_state==BLINK_2 && state==state_4)
			{
				if(ovf<ms_200)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
					LED_ON(porta,led3);
					LED_ON(porta,led4);

				}
				else if(ovf>=ms_200)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);

				}
			}
		}
		else if(blink_state==BLINK_3)
		{
			while(blink_state==BLINK_3 && state==state_4)
			{
				if(ovf<ms_300)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_300)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_4)
		{
			while(blink_state==BLINK_4 && state==state_4)
			{
				if(ovf<ms_500)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_500)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_5)
		{
			while(blink_state==BLINK_5 && state==state_4)
			{
				if(ovf<ms_800)
				{
					LED_ON(porta,led1);
					LED_ON(porta,led2);
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_800)
				{
					LED_OFF(porta,led1);
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
	}
	/************************************************************************/
	/* state_5                                                                 */
	/************************************************************************/
	else if(state==state_5)
	{  LED_OFF(porta,led1);
		if(blink_state==BLINK_1)
		{
			while(blink_state==BLINK_1 && state==state_5)
			{
				if(ovf<ms_100)
				{	
					LED_ON(porta,led2);
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_100)
				{
					
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_2)
		{
			while(blink_state==BLINK_2 && state==state_5)
			{
				if(ovf<ms_200)
				{
					LED_ON(porta,led2);
					LED_ON(porta,led3);
					LED_ON(porta,led4);

				}
				else if(ovf>=ms_200)
				{
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);

				}
			}
		}
		else if(blink_state==BLINK_3)
		{
			while(blink_state==BLINK_3 && state==state_5)
			{
				if(ovf<ms_300)
				{
					LED_ON(porta,led2);
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_300)
				{
					
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_4)
		{
			while(blink_state==BLINK_4 && state==state_5)
			{
				if(ovf<ms_500)
				{
					LED_ON(porta,led2);
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_500)
				{
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_5)
		{
			while(blink_state==BLINK_5 && state==state_5)
			{
				if(ovf<ms_800)
				{
					LED_ON(porta,led2);
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_800)
				{
					LED_OFF(porta,led2);
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
	}
	/************************************************************************/
	/* state_6                                                            */
	/************************************************************************/
	else if(state==state_6)
	{  LED_OFF(porta,led2);
		if(blink_state==BLINK_1)
		{
			while(blink_state==BLINK_1 && state==state_6)
			{
				if(ovf<ms_100)
				{
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_100)
				{
					
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_2)
		{
			while(blink_state==BLINK_2 && state==state_6)
			{
				if(ovf<ms_200)
				{
					LED_ON(porta,led3);
					LED_ON(porta,led4);

				}
				else if(ovf>=ms_200)
				{
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);

				}
			}
		}
		else if(blink_state==BLINK_3)
		{
			while(blink_state==BLINK_3 && state==state_6)
			{
				if(ovf<ms_300)
				{
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_300)
				{
					
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_4)
		{
			while(blink_state==BLINK_4 && state==state_6)
			{
				if(ovf<ms_500)
				{
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_500)
				{
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_5)
		{
			while(blink_state==BLINK_5 && state==state_6)
			{
				if(ovf<ms_800)
				{
					LED_ON(porta,led3);
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_800)
				{
					LED_OFF(porta,led3);
					LED_OFF(porta,led4);
				}
			}
		}
	}
	/************************************************************************/
	/* state_7                                                                */
	/************************************************************************/
	else if(state==state_7)
	{  LED_OFF(porta,led3);
		if(blink_state==BLINK_1)
		{
			while(blink_state==BLINK_1 && state==state_7)
			{
				if(ovf<ms_100)
				{
					
					
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_100)
				{
					
					
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_2)
		{
			while(blink_state==BLINK_2 && state==state_7)
			{
				if(ovf<ms_200)
				{
					
					LED_ON(porta,led4);

				}
				else if(ovf>=ms_200)
				{
					
					LED_OFF(porta,led4);

				}
			}
		}
		else if(blink_state==BLINK_3)
		{
			while(blink_state==BLINK_3 && state==state_7)
			{
				if(ovf<ms_300)
				{
					
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_300)
				{
					
					
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_4)
		{
			while(blink_state==BLINK_4 && state==state_7)
			{
				if(ovf<ms_500)
				{
					
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_500)
				{
					
					LED_OFF(porta,led4);
				}
			}
		}
		else if(blink_state==BLINK_5)
		{
			while(blink_state==BLINK_5 && state==state_7)
			{
				if(ovf<ms_800)
				{
					
					LED_ON(porta,led4);
				}
				else if(ovf>=ms_800)
				{
					
					LED_OFF(porta,led4);
				}
			}
		}
	}
	/************************************************************************/
	/* state_8                                                             */
	/************************************************************************/
	else if(state==state_8)
	{  
		LED_OFF(porta,led4);
	}
	else
	{
		//do nothing
	}
}
void INT0_func(void)
{   if(state==0)
	{
		TIMER_MANAGER_STA(1024);
		state=state_1;	
	}
	else if(state==state_8)
	{
		state=state_1;		
	}
	else
	{
		state++;
	}
	ovf=0;
}
void INT1_func(void)
{
	if(blink_state==BLINK_5)
	{
		blink_state=BLINK_1;
	}
	else
	{
		blink_state++;
	}
	ovf=0;
}
void timer_comp(void)
{
	ovf++;
	if(ovf==ms_1000)
	{
		ovf=0;
	}	
	else
	{
		//do nothing
	}
}

