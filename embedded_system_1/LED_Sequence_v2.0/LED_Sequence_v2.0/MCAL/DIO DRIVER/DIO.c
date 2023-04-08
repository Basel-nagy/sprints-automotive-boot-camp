/*
 * DIO.c
 *
 * Created: 4/5/2023 1:32:00 PM
 *  Author: basel
 */ 
/************************************************************************/
/* including sections                                                   */
/************************************************************************/
#include "DIO.h"

/************************************************************************/
/* functions implementations                                            */
/************************************************************************/
STD_return DIO_INIT (DIO_PORTS port, DIO_PINS pin, PIN_DIRECTION direction)
{
	STD_return ret_val=ok;
	switch(port)
	{
		case porta: if(direction==OUTPUT)
		            {
						SET_BIT(DDRA,pin);
					}
					else if(direction==INPUT)
					{
						CLEAR_BIT(DDRA,pin);
					}
					else
					{
						ret_val=not_ok;
					}
					break;
	   case portb: if(direction==OUTPUT)
	                {
		                 SET_BIT(DDRB,pin);
	                }
	                else if(direction==INPUT)
	                {
		                CLEAR_BIT(DDRB,pin);
	                }
	                else
	                {
		             ret_val=not_ok;
	                }
	                break;
	 case portc: if(direction==OUTPUT)
					{
						SET_BIT(DDRC,pin);
					}
					else if(direction==INPUT)
					{
						CLEAR_BIT(DDRC,pin);
					}
					else
					{
						ret_val=not_ok;
					}
					break;
		case portd: if(direction==OUTPUT)
					{
						SET_BIT(DDRD,pin);
					}
					else if(direction==INPUT)
					{
						CLEAR_BIT(DDRD,pin);
					}
					else
					{
						ret_val=not_ok;
					}
					break;
	}
	return ret_val;
}
STD_return DIO_WRITE_PIN (DIO_PORTS port, DIO_PINS pin, PIN_STATE state)
{
	STD_return ret_val=ok;
	switch(port)
	{
		case porta: if(state==HIGH)
		{
			SET_BIT(PORTA,pin);
		}
		else if(state==LOW)
		{
			CLEAR_BIT(PORTA,pin);
		}
		else
		{
			ret_val=not_ok;
		}
		break;
		case portb: if(state==HIGH)
		{
			SET_BIT(PORTB,pin);
		}
		else if(state==LOW)
		{
			CLEAR_BIT(PORTB,pin);
		}
		else
		{
			ret_val=not_ok;
		}
		break;
		case portc: if(state==HIGH)
		{
			SET_BIT(PORTC,pin);
		}
		else if(state==LOW)
		{
			CLEAR_BIT(PORTC,pin);
		}
		else
		{
			ret_val=not_ok;
		}
		break;
		case portd: if(state==HIGH)
		{
			SET_BIT(PORTD,pin);
		}
		else if(state==LOW)
		{
			CLEAR_BIT(PORTD,pin);
		}
		else
		{
			ret_val=not_ok;
		}
		break;
	}
	return ret_val;
}
STD_return DIO_READ_PIN (DIO_PORTS port, DIO_PINS pin, uint8_t* value)
{
	STD_return ret_val=ok;
	switch(port)
	{
		case porta: *value=READ_BIT(PINA,pin);break;
		case portb: *value=READ_BIT(PINB,pin);break;
		case portc: *value=READ_BIT(PINC,pin);break;
		case portd: *value=READ_BIT(PIND,pin);break;
		default: ret_val=not_ok;
	}
	return ret_val;
}