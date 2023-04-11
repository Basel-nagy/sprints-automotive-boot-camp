/*
 * TIMER.h
 *
 * Created: 4/10/2023 2:39:46 AM
 *  Author: basel
 */ 


#ifndef TIMER_H_
#define TIMER_H_
/*including section*/
#include "../../utilities/STD_TYPES.h"
#include "../../utilities/bit_manipulation.h"
#include "../../utilities/MemMap.h"
/*typedefs*/
typedef enum EN_timermode_t {normal,ctc,pwm,phase_correct} EN_timermode_t;


/******************************************    APIs PROTOTYPES      *******************************************************************/
STD_return TIMER_INIT(EN_timermode_t timer_cfg);
STD_return TIMER_START (uint16_t prescaller);
void TIMER_STOP (void);
void TIMER_OVF_INT_ENABLE (void);
void TIMER_OVF_INT_DISABLE (void);
void TIMER_COMP_INT_ENABLE (void);
void TIMER_COMP_INT_DISABLE (void);
void OVF_VALUE (uint8_t value);
void COMP_VALUE (uint8_t value);
STD_return TIMER_OVF_CALLBACK (void (*ptr) (void));
STD_return TIMER_COMP_CALLBACK (void (*ptr) (void));







#endif /* TIMER_H_ */