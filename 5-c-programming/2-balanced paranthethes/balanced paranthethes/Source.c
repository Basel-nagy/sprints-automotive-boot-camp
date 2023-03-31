#include<stdio.h>
#include"balanced_paranthethesis.h"
ST_stack_t MY_STACK;
int main()
{
	createEmptyStack(&MY_STACK);
	uint8_t exp[50] = { "x+y" };
	if (isBalancedParanthethes(exp) == 0)
		printf("balanced paranthethesis");
	else if (isBalancedParanthethes(exp) == -1)
		printf("not balaned paranthethesis");
	else
	{
		printf("the is no parenthesis");
	}
	/*uint8_t data, top;
	createEmptyStack(&MY_STACK);
	push(&MY_STACK, 'a');
	push(&MY_STACK, 'b');
	push(&MY_STACK, 'c');
	push(&MY_STACK, 'd');
	push(&MY_STACK, 'e');
	printStack(&MY_STACK);
	pop(&MY_STACK, &data);
	getStackTop(&MY_STACK, &top);
	printf("\n%d\n", top);
	printStack(&MY_STACK);
	push(&MY_STACK, '1');
	push(&MY_STACK, '2');
	push(&MY_STACK, '3');
	push(&MY_STACK, '4');
	push(&MY_STACK, '5');
	push(&MY_STACK, '6');
	push(&MY_STACK, '7');
	getStackTop(&MY_STACK, &top);
	printf("\n%d\n", top);
	printStack(&MY_STACK);
	pop(&MY_STACK, &data);
	pop(&MY_STACK, &data);
	pop(&MY_STACK, &data);
	pop(&MY_STACK, &data);
	getStackTop(&MY_STACK, &top);
	printf("\n%d\n", top);
	printStack(&MY_STACK);
	pop(&MY_STACK, &data);
	pop(&MY_STACK, &data);
	pop(&MY_STACK, &data);
	pop(&MY_STACK, &data);
	pop(&MY_STACK, &data);
	pop(&MY_STACK, &data);
	pop(&MY_STACK, &data);
	if (getStackTop(&MY_STACK, &top) == -2)
		printf("\nstack is empty\n");
	if (printStack(&MY_STACK) == -2)
	{
		printf("stack is empty");
	}
	else
	{
		printStack(&MY_STACK);
	}*/

	

	

	
	
	
}