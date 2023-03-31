#include"balanced_paranthethesis.h"
extern ST_stack_t MY_STACK;


/*
*description:Checks if the parentheses are balanced or not  Checks the following parentheses types {, }, (, ) only
*input arguments:This function takes an expression array max 10 characters
* return: -2 if the neither of paranthethes is used
* return: -1 if the parentheses are not balanced
* return : 0 if the parentheses are balanced
*/
int8_t isBalancedParanthethes(uint8_t* expression)
{
	createEmptyStack(&MY_STACK);
	uint8_t data,top=0;
	uint8_t i;
	uint8_t flag = 0;
	uint8_t flag_1 = 0;
	uint8_t lenght = strlen(expression);
	for (i = 0;i < lenght;i++)
	{
		if (expression[i] == '(' || expression[i] == ')' || expression[i] == '{' || expression[i] == '}')
		{
			flag_1 = 0;
			break;
		}
		else 
		{
			flag_1 = 1;
			continue;
		}			
	}
	if (flag_1 == 1)
		return -2;
	if (lenght > 100)
	{
		return -2;
	}
	else
	{
		for (i = 0;i < lenght;i++)
		{
			if (expression[i] == '{' || expression[i] == '(')
			{
				push(&MY_STACK, expression[i]);
			}
			else if (expression[i] == '}' || expression[i] == ')')
			{
				if(pop(&MY_STACK, &data)==0)
				{
					if (data == '{' && expression[i] != '}')
					{
						flag = 1;
						break;
					}
					else if ((data == '(') && (expression[i] != ')'))
					{
						flag = 1; 
						break;
					}
					else
					{
						flag = 0;
						
					}
				}
				else
				{
					flag = 1;
					break;

				}				
			}
			else
			{
	
				//do nothing		
			}
		}
     }
	if ((flag == 0) && (isEmpty(&MY_STACK)==-2))
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void isBalancedParanthethestest(void)
{
	
	uint8_t counter = 0;
	int8_t error;
	uint8_t string[50];
	while (1)
	{
		counter++;
		printf("test case : %d\n", counter);
		printf("enter the string\n");
		gets(string);
		error = isBalancedParanthethes(string);
		if ( error== 0)
			printf("balanced paranthethesis\n");
		else if (error == -1)
			printf("not balaned paranthethesis\n");
		else
		{
			printf("the is no parenthesis\n");
		}

	}
	
}
