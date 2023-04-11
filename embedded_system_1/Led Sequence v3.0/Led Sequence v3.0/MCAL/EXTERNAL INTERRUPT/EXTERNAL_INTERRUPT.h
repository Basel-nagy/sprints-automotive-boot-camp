/*
 * EXTERNAL_INTERRUPT.h
 *
 * Created: 4/7/2023 4:30:18 PM
 *  Author: basel
 */ 


#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_
#include "../../utilities/STD_TYPES.h"
#include "../../utilities/bit_manipulation.h"
#include "../../utilities/MemMap.h"
/************************************************************************/
/* typedefs                                                             */
/************************************************************************/
typedef enum EN_INT_NUM_t {int0, int1, int2} EN_INT_NUM_t;
typedef enum EN_EDGE_t {rising,falling} EN_EDGE_t;
	
	
/******************************************    APIs PROTOTYPES      *******************************************************************/
STD_return EDGE_SELECET (EN_EDGE_t edge,EN_INT_NUM_t ext_int);
STD_return EXT_INTERRUPT_ENABLE (EN_INT_NUM_t ext_int);
STD_return SETCALLBACK_FUN_INT0(void (*ptr_int0) (void));
STD_return SETCALLBACK_FUN_INT1(void (*ptr_int1) (void));
STD_return SETCALLBACK_FUN_INT2(void (*ptr_int2) (void));





#endif /* EXTERNAL_INTERRUPT_H_ */