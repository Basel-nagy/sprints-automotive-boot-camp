
/****************************************************included sections****************************************************/
#include<stdio.h>
#include"stack.h"

/*******global variables*********/

extern ST_stack_t MY_STACK;
/****************************************************functions implementations********************************************/



/*
*description:Initialize this stack with Zeros and Initialize the top with -1
*input arguments:This function takes a reference to a stacks type
* return: void
*/
void createEmptyStack(ST_stack_t* stack)
{
	uint8_t i;
	for (i = 0;i < 10;i++)
	{
		stack->elements[i] = 0;
	}
	stack->top = -1;
}

/*
*description:Stores the data passed into the stack
*input arguments:This function takes a reference to the stack and data to store
* return: returns -1 if the stack is full and returns 0 otherwise
*/
int8_t push(ST_stack_t* stack, uint8_t data)
{
	if (isFull(&MY_STACK) == 0)
	{
		stack->top=stack->top+1;
		stack->elements[stack->top]=data;
		
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
*description:Stores the data popped from the stack in a data variable
*input arguments:This function takes a reference to the stack
* return: returns -2 if the stack is empty and returns 0 otherwise
*/
int8_t pop(ST_stack_t* stack, uint8_t* data)
{
	if (isEmpty(&MY_STACK) == 0)
	{
		*data=stack->elements[stack->top];
		stack->top=stack->top-1;
		return 0;
	}
	else
	{
		return -2;
	}
}


/*
*description:Prints all stack's data starting from the top
*input arguments:This function takes a reference to the stack
* return:returns -1 if the stack is full
*        returns -2 if the stack is empty
*        returns 0 otherwise
*/
int8_t printStack(ST_stack_t* stack)
{
	if (isEmpty(&MY_STACK) == -2)
	{
		return -2;
	}
	else if (isFull(&MY_STACK) == -1)
	{
		int8_t i;
		for (i = stack->top;i >= 0;i--)
		{
			printf("%c ", stack->elements[i]);
		}
		return -1;
	}
	else
	{
		int8_t i;
		for (i = stack->top;i >= 0;i--)
		{
			printf("%c ", stack->elements[i]);
		}
		return 0;
	}
}


/*
*description:stores its top data into a variable
* input arguments : This function takes a reference to the stack
* return : returns -2 if the stack is empty
*         0 otherwise
*/
int8_t getStackTop(ST_stack_t* stack, uint8_t* topData)
{
	if (isEmpty(&MY_STACK) == 0)
	{
		*topData = stack->top;
		return 0;
	}
	else
	{
		
		return -2;
	}
}


/*
*description:Checks if the stack is full or not
* input arguments : This function takes a reference to the stack
* return : returns -1 if the stack is full
*          0 otherwise
*/
int8_t isFull(ST_stack_t* stack)
{
	if ((stack->top) >= STACK_SIZE-1)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

/*
*description:Checks if the stack is full or not
* input arguments : This function takes a reference to the stack
* return :returns -2 if the stack is empty
*         0 otherwise
*/
int8_t isEmpty(ST_stack_t* stack)
{
	if ((stack->top) == -1)
	{
		return -2;
	}
	else
	{
		return 0;
	}
}
void stacktest(void)
{
	uint8_t data, top;
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
	}
}