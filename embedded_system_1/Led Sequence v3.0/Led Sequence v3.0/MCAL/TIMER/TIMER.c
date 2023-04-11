/*
 * TIMER.c
 *
 * Created: 4/10/2023 2:39:35 AM
 *  Author: basel
 */ 
/*including section*/
#include"TIMER.h"
/*functions impelementation*/
static void (*timer_ovf_callbackptr)(void);
static void (*timer_comp_callbackptr)(void);
STD_return TIMER_INIT(EN_timermode_t timer_cfg)
{
	STD_return ret_val=ok;
	switch(timer_cfg)
	{
		case normal: CLEAR_BIT(TCCR0,WGM00); CLEAR_BIT(TCCR0,WGM01);break;
		case ctc:SET_BIT(TCCR0,WGM01);CLEAR_BIT(TCCR0,WGM00);break;
		case pwm:SET_BIT(TCCR0,WGM01);SET_BIT(TCCR0,WGM00);break;
		case phase_correct:SET_BIT(TCCR0,WGM00);CLEAR_BIT(TCCR0,WGM01);break;
		default: ret_val=not_ok;
	}
	return ret_val;
}
STD_return TIMER_START (uint16_t prescaller)
{
	STD_return ret_val=ok;
	if(prescaller==1)
	{
		TCCR0|=1<<0;
	}
	else if(prescaller==8)
	{
		TCCR0 |=2<<0;
	}
	else if(prescaller==64)
	{
		TCCR0 |=3<<0;
	}
	else if(prescaller==256)
	{
		TCCR0 |=4<<0;
	}
	else if(prescaller==1024)
	{
		TCCR0 |=5<<0;
	}
	else
	{
		ret_val=not_ok;
	}
	return ret_val;
}
void TIMER_STOP (void)
{
	CLEAR_BIT(TCCR0,CS02);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS00);	
}
void TIMER_OVF_INT_ENABLE (void)
{
	SET_BIT(TIMSK,TOIE0);
}
void TIMER_OVF_INT_DISABLE (void)
{
	CLEAR_BIT(TIMSK,TOIE0);
}
void TIMER_COMP_INT_ENABLE (void)
{
	SET_BIT(TIMSK,OCIE0);
}
void TIMER_COMP_INT_DISABLE (void)
{
	CLEAR_BIT(TIMSK,OCIE0);
}
void OVF_VALUE (uint8_t value)
{
	TCNT0=value;
}
void COMP_VALUE (uint8_t value)
{
	OCR0=value;
}
STD_return TIMER_OVF_CALLBACK (void (*ptr) (void))
{    STD_return ret_val=ok;
	if(ptr==NULL)
	{
		ret_val=not_ok;
	}
	else
	{
		timer_ovf_callbackptr=ptr;
	}
	return ret_val;
}
STD_return TIMER_COMP_CALLBACK (void (*ptr) (void))
{
	 STD_return ret_val=ok;
	 if(ptr==NULL)
	 {
		 ret_val=not_ok;
	 }
	 else
	 {
		 timer_comp_callbackptr=ptr;
	 }
	 return ret_val;
}
ISR(TIMER0_OVF)
{
	timer_ovf_callbackptr();
}
ISR(TIMER0_COMP)
{
	timer_comp_callbackptr();
}