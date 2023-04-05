/*
 * DIO.h
 *
 * Created: 4/5/2023 1:31:48 PM
 *  Author: basel
 */ 


#ifndef DIO_H_
#define DIO_H_
/************************************************************************/
/* including sections                                                   */
/************************************************************************/
#include "../../UTILITIES/MemMap.h"
#include "../../UTILITIES/STD_TYPES.h"
#include "../../UTILITIES/bit_manipulation.h"
/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef enum DIO_PORTS
{
	porta, portb, portc, portd
} DIO_PORTS;
typedef enum DIO_PINS
{
	pin0, pin1, pin2, pin3, pin4, pin5, pin6, pin7
} DIO_PINS;
typedef enum PIN_DIRECTION
{
	INPUT,
	OUTPUT
} PIN_DIRECTION;

typedef enum PIN_STATE
{
	LOW,
	HIGH
} PIN_STATE;

/******************************************    APIs PROTOTYPES      *******************************************************************/

STD_return DIO_INIT (DIO_PORTS port, DIO_PINS pin, PIN_DIRECTION direction);
STD_return DIO_WRITE_PIN (DIO_PORTS port, DIO_PINS pin, PIN_STATE state);
STD_return DIO_READ_PIN (DIO_PORTS port, DIO_PINS pin, uint8_t* vale);





#endif /* DIO_H_ */