/*
 * EXTERNAL_ONTERRUPT.c
 *
 * Created: 4/7/2023 4:30:44 PM
 *  Author: basel
 */ 
/************************************************************************/
/* INCLUDING SECTIONS                                                   */
/************************************************************************/
#include "EXTERNAL_INTERRUPT.h"
/************************************************************************/
/* APIs IMPELEMENTATION                                                */
/************************************************************************/
static void (*callback_int0) (void);
static void (*callback_int1) (void);
static void (*callback_int2) (void);
STD_return EDGE_SELECET (EN_EDGE_t edge,EN_INT_NUM_t ext_int)
{  STD_return ret_val=ok;
	switch(ext_int)
	{
		case int0 : if(edge==rising)
		             {
						 SET_BIT(MCUCR,ISC00);
						 SET_BIT(MCUCR,ISC01);
					 }
					 else if(edge==falling)
					 {
						 CLEAR_BIT(MCUCR,ISC00);
						 SET_BIT(MCUCR,ISC01);
					 }
					 else
					 {
						 ret_val=not_ok;
					 }
					 break;
					 
		case int1 :if(edge==rising)
		{
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		else if(edge==falling)
		{
			CLEAR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		}
		else
		{
			ret_val=not_ok;
		}
		break;
		case int2 : if(edge==rising)
		{
			SET_BIT(MCUCSR,ISC2);
		}
		else if(edge==falling)
		{
			CLEAR_BIT(MCUCSR,ISC2);
		}
		else
		{
			ret_val=not_ok;
		}
		break;
		default: ret_val = not_ok; break;
	}
	return ret_val;
}
STD_return EXT_INTERRUPT_ENABLE (EN_INT_NUM_t ext_int)
{   STD_return ret_val=ok;
	switch(ext_int)
	{
		case int0: SET_BIT(GICR,INT0);break;
		case int1: SET_BIT(GICR,INT1);break;
		case int2: SET_BIT(GICR,INT2);break;
		default: ret_val=not_ok;
	}
	return ret_val;
}
STD_return SETCALLBACK_FUN_INT0(void (*ptr_int0) (void))
{    STD_return ret_val=ok;
	if(ptr_int0==NULL)
	{
		ret_val=not_ok;
	}
	else
	{
		callback_int0=ptr_int0;
		
	}
	return ret_val;
}
STD_return SETCALLBACK_FUN_INT1(void (*ptr_int1) (void))
{
	STD_return ret_val=ok;
	if(ptr_int1==NULL)
	{
		ret_val=not_ok;
	}
	else
	{
		callback_int1=ptr_int1;
		
	}
	return ret_val;
}
STD_return SETCALLBACK_FUN_INT2(void (*ptr_int2) (void))
{
	STD_return ret_val=ok;
	if(ptr_int2==NULL)
	{
		ret_val=not_ok;
	}
	else
	{
		callback_int2=ptr_int2;
		
	}
	return ret_val;
}

ISR(EXT_INT0)
{
	callback_int0();
}
ISR(EXT_INT1)
{
	callback_int1();
}
ISR(EXT_INT2)
{
	callback_int2();
}