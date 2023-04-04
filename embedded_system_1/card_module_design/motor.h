#ifndef _MOTOR_H_
#define _MOTOR_H_
#include"dio.h"
typedef struct ST_motor_t
{
	EN_ports_t port;
	EN_pins_t pin_number_1;
	EN_pins_t pin_number_2;
}
/*description: this function init the motor
*Arguments: pointer to struct motor
*Return: void
*/
void motor_init (ST_motor_t motor);

/*description: this function control the speed of the motor
*Arguments: speed
*Return: void
*/
void motor_speed(uint8_t speed);




/*description: this function stops the motors
*Arguments: void
*Return: void
*/
void motor_stop(void);

/*description: this function rotates the motor to the right
*Arguments: pointer to struct motor, speed
*Return: void
*/
void motor_reverse_right(uint8_t speed, ST_motor_t motor);

/*description: this function rotate the motor to the left
*Arguments: pointer to struct motor,speed
*Return: void
*/
void motor_reverse_left(uint8_t speed, ST_motor_t motor);

#endif