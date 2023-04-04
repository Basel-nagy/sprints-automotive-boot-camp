#ifndef _CAR_CONTRO_H_
#define _CAR_CONTRO_H_
typedef enum EN_carmoving_t {forword, backword, reverse_right, reverse_left , stop}EN_carmoving;

/*description: this function init the car control
*Arguments: void
*Return: void
*/
void car_init(void);

/*description: this function move the car forword
*Arguments: speed
*Return: void
*/
void car_forword (uint8_t speed);

/*description: this function rotates the car to the right
*Arguments: speed
*Return: void
*/
void car_rotated_right (uint8_t speed);

/*description: this function moves the car forward
*Arguments: void
*Return: void
*/
void car_stop (void);

#endif