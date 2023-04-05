/*
 * app.c
 *
 * Created: 4/5/2023 5:44:38 PM
 *  Author: basel
 */ 
#include "app.h"
#define led1 pin0
#define led2 pin1
#define led3 pin2
#define led4 pin3
#define button_1 pin4
static uint8_t flag=0;
/************************************************************************/
/* functions implementations                                            */
/************************************************************************/
STD_return APP_INIT(void)
{   DIO_WRITE_PIN(porta,pin4,OUTPUT);
	STD_return ret_val=ok;
	LED led_1={porta,led1};
	LED led_2={porta,led2};
	LED led_3={porta,led3};
	LED led_4={porta,led4};
	BUTTON button={porta,button_1};
	ret_val|=LED_INIT(&led_1);
	ret_val|=LED_INIT(&led_2);
	ret_val|=LED_INIT(&led_3);
	ret_val|=LED_INIT(&led_4);
	ret_val|=BUTTON_INIT(&button);
		
		return ret_val;
}
void APP_START(void)
{
	EN_BUTTON_STATE_t state;
	
	BUTTON_READ(porta,pin4,&state);
	if(flag==0 && state==RELEASED)
	{
		flag=1;
	}
	else if(flag==1 && state==PUSHED)
	{	
		flag=2;		
	}
	else if(flag==2 && state==RELEASED)
	{
		LED_ON(porta,led1);
		flag=3;
	}
	else if(flag==3 && state==PUSHED)
	{
		flag=4;
	}
	else if(flag==4 && state==RELEASED)
	{
		LED_ON(porta,led2);
		flag=5;
	}
	else if(flag==5 && state==PUSHED)
	{
		flag=6;
	}
	else if(flag==6 && state==RELEASED)
	{	
		LED_ON(porta,led3);
		flag=7;
	}
	else if(flag==7 && state==PUSHED)
	{
		flag=8;
	}
	else if(flag==8 && state==RELEASED)
	{
		LED_ON(porta,led4);
		flag=9;
	}
	else if(flag==9 && state==PUSHED)
	{
		flag=10;
	}
	else if(flag==10 && state==RELEASED)
	{
		LED_OFF(porta,led1);
		flag=11;
	}
	else if(flag==11 && state==PUSHED)
	{
		flag=12;
	}
	else if(flag==12 && state==RELEASED)
	{
		LED_OFF(porta,led2);
		flag=13;
	}
	else if(flag==13 && state==PUSHED)
	{
		flag=14;
	}
	else if(flag==14 && state==RELEASED)
	{
		LED_OFF(porta,led3);
		flag=15;
	}
	else if(flag==15 && state==PUSHED)
	{
		flag=16;
	}
	else if(flag==16 && state==RELEASED)
	{
		LED_OFF(porta,led4);
		flag=0;
	}
	
	
}