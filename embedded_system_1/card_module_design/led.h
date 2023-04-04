#ifndef _LED_H_
#define _LED_H_
#include "dio.h"
typedef struct ST_led_t
{
	EN_ports_t led_port;
	EN_pins_t led_pin;
} ST_led_t;



/*description: this function init the led
*Arguments: pointer to struct led
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t led_init (ST_led_t led);

/*description: this function turn on the led
*Arguments: pointer to struct led
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t led_on (ST_led_t led);

/*description: this function turn off the led
*Arguments: pointer to struct led
*Return: ok if function fine, Not_ok if something wrong happens
*/
EN_error_t led_off (ST_led_t led);

#endif