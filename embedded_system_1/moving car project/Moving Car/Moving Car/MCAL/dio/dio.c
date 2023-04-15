/*
 * dio.c
 *
 * Created: 4/14/2023 12:27:35 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 
#include <avr/io.h>
#include "dio.h"


#define DIO_MAX_PINS	8
#define DIO_MAX_PORTS	4

#define  DATA_DIRECTION_PORTA	DDRA
#define  DATA_DIRECTION_PORTB	DDRB
#define  DATA_DIRECTION_PORTC	DDRC
#define  DATA_DIRECTION_PORTD	DDRD


#define  WR_PORT_A					PORTA
#define  WR_PORT_B					PORTB
#define  WR_PORT_C					PORTC
#define  WR_PORT_D					PORTD




#define  RE_PORT_A					PINA
#define  RE_PORT_B					PINB
#define  RE_PORT_C					PINC
#define  RE_PORT_D					PIND


u8_en_dioErrors DIO_init (en_dioPortsType port, en_dioPinsType pin, u8_en_dioDirType direction)
{
	
	if (pin < DIO_MAX_PINS)
	{
		if (port == porta)
		{
			DATA_DIRECTION_PORTA |= direction << pin;
			return DIO_E_OK;
		}
		else if (port == portb)
		{
			DATA_DIRECTION_PORTB |= direction << pin;
			return DIO_E_OK;
		}
		else if (port == portc)
		{
			DATA_DIRECTION_PORTC |= direction << pin;
			return DIO_E_OK;
		}
		else if (port == portd)
		{
			DATA_DIRECTION_PORTD |= direction << pin;
			return DIO_E_OK;
		}
		else
		{
			return DIO_InvalidPort;
		}
		
	}
	else{
		return DIO_InvalidPin;
	}
}
u8_en_dioErrors DIO_writePIN (en_dioPortsType port, en_dioPinsType pin, u8_en_dioLevelType state)
{
	if (pin < DIO_MAX_PINS)
	{
		if (port == porta)
		{
			if (state == STD_HIGH)
			{
				WR_PORT_A |= (1U << pin);
			}
			else{
				WR_PORT_A &= ~(1U << pin);
			}
			return DIO_E_OK;
		}
		else if (port == portb)
		{
			if (state == STD_HIGH)
			{
				WR_PORT_B |= (1U << pin);
			}
			else{
				WR_PORT_B &= ~(1U << pin);
			}
			return DIO_E_OK;
		}
		else if (port == portc)
		{
			if (state == STD_HIGH)
			{
				WR_PORT_C |= (1U << pin);
			}
			else{
				WR_PORT_C &= ~(1U << pin);
			}
			return DIO_E_OK;
		}
		else if (port == portd)
		{
			if (state == STD_HIGH)
			{
				WR_PORT_D |= (1U << pin);
			}
			else{
				WR_PORT_D &= ~(1U << pin);
			}
			return DIO_E_OK;
		}
		else
		{
			return DIO_InvalidPort;
		}
		
	}
	else{
		return DIO_InvalidPin;
	}
}
u8_en_dioErrors DIO_readPIN (en_dioPortsType port, en_dioPinsType pin, uint8_t* value)
{
	if (pin < DIO_MAX_PINS)
	{
		if (port == porta)
		{
			*value = ((RE_PORT_A & (1U<<pin))>>pin);
			return DIO_E_OK;
		}
		else if (port == portb)
		{
			*value = ((RE_PORT_B & (1U<<pin))>>pin);
			return DIO_E_OK;
		}
		else if (port == portc)
		{
			*value = ((RE_PORT_C & (1U<<pin))>>pin);
			return DIO_E_OK;
		}
		else if (port == portd)
		{
			*value = ((RE_PORT_D & (1U<<pin))>>pin);
			return DIO_E_OK;
		}
		else
		{
			return DIO_InvalidPort;
		}
		
	}
	else{
		return DIO_InvalidPin;
	}
}