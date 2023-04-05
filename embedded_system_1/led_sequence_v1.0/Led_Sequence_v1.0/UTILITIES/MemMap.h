/*
 * MemMap.h
 *
 * Created: 4/5/2023 1:26:03 PM
 *  Author: basel
 */ 


#ifndef MEMMAP_H_
#define MEMMAP_H_
/************************************************************************/
/* DIO REGISTERS                                                        */
/************************************************************************/
//PORTA REGISTERS
#define DDRA  *((volatile uint8_t*)(0x3A))
#define PORTA *((volatile uint8_t*)(0x3B))
#define PINA  *((volatile uint8_t*)(0x39))

//PORTB REGISTERS
#define DDRB  *((volatile uint8_t*)(0x37))
#define PORTB *((volatile uint8_t*)(0x38))
#define PINB  *((volatile uint8_t*)(0x36))

//PORTC REGISTERS
#define DDRC  *((volatile uint8_t*)(0x34))
#define PORTC *((volatile uint8_t*)(0x35))
#define PINC  *((volatile uint8_t*)(0x33))

//PORTD REGISTERS
#define DDRD  *((volatile uint8_t*)(0x31))
#define PORTD *((volatile uint8_t*)(0x32))
#define PIND  *((volatile uint8_t*)(0x30))




#endif /* MEMMAP_H_ */