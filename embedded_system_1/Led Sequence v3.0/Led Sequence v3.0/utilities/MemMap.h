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
/************************************************************************/
/* EXTERNAL INTERRUPTS REGISTERS                                        */
/************************************************************************/
#define MCUCR *((volatile uint8_t*)(0x55))
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define MCUCSR *((volatile uint8_t*)(0x54))
#define ISC2 6
#define GICR *((volatile uint8_t*)(0x5B))
#define INT1 7
#define INT0 6
#define INT2 5
#define GIFR *((volatile uint8_t*)(0x5A))
#define INTF1 7
#define INTF0 6
#define INTF2 5
/************************************************************************/
/* timer0 registers                                                     */
/************************************************************************/
#define TCNT0 *((volatile uint8_t*)(0x52))
#define OCR0 *((volatile  uint8_t*)(0x5C))
#define TCCR0 *((volatile uint8_t*)(0x53))
#define CS00 0
#define CS01 1
#define CS02 2
#define WGM01 3
#define WGM00 6
#define TIMSK *((volatile uint8_t*)(0x59))
#define TOIE0 0
#define OCIE0 1
#define TIFR *((volatile  uint8_t*)(0x58))
#define TOV0 0
#define OCF0 1

/************************************************************************/
/* interrupts                                                           */
/************************************************************************/
//interrupt functions
#define sei() __asm__ __volatile__("sei" ::: "memory")
#define cli() __asm__ __volatile__("cli" ::: "memory")

//interrupt vectors

#define EXT_INT0 __vector_1
#define EXT_INT1 __vector_2
#define EXT_INT2 __vector_3
#define TIMER2_COMP __vector_4
#define TIMER2_OVF __vector_5
#define TIMER1_CAPT __vector_6
#define TIMER1_COMPA __vector_7
#define TIMER1_COMPB __vector_8
#define TIMER1_OVF __vector_9
#define TIMER0_COMP __vector_10
#define TIMER0_OVF __vector_11
#define SPI_STC __vector_12
#define USART_RXC __vector_13
#define USART_UDRE __vector_14
#define USART_TXC __vector_15
#define ADC __vector_16
#define EE_RDY __vector_17
#define ANA_COMP __vector_18
#define TWI __vector_19
#define SPM_RDY __vector_20

#define ISR(INT_VECT) void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)



#endif /* MEMMAP_H_ */