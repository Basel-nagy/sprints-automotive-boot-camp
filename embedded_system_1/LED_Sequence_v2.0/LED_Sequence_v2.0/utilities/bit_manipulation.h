/*
 * bit_manipulation.h
 *
 * Created: 4/5/2023 1:25:49 PM
 *  Author: basel
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG&=~(1<<BIT))
#define READ_BIT(REG,BIT) ((REG & (1<<BIT))>>BIT)
#define TOGGLE_BIT(REG,BIT) (REG ^= (1<<BIT))
#endif /* BIT_MANIPULATION_H_ */