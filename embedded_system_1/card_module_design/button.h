#ifndef _BUTTON_H_
#define _BUTTON_H_
#include"dio.h"
typedef enum EN_button_states_t {pushed, released}EN_button_states_t;
/*description: this function init the button
*Arguments: port , pin number
*Return: void
*/
void button_init (EN_ports_t port, EN_pins_t pins);



/*description: this function read button state
*Arguments: port , pin number
*Return: the button state
*/
EN_button_states_t button_read (EN_ports_t port, EN_pins_t pins);

#endif