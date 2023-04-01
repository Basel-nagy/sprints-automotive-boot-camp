#include"LCS.h"




/* Description:
 * - This function takes a reference to an array,
 * - array size, and
 * - reference to store the size of the LCS
 * - Using the insertion sort algorithm
 * - The function will search for the LCS in the array and
 * - stores its size
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns -3 if there is no LCS,
 * (i.e all array elements are not consecutive at all)
 * - returns 0 otherwise
 */
int8_t lcsGetSize(int32_t* array, uint8_t arraySize, uint8_t* sizeofLCS)
{
	uint8_t counter = 0;
	uint8_t counter_max = 0;
	uint8_t i;
	int8_t error;
	int8_t flag = 0;
	error = insertionSort(array, arraySize);
	if (error == -1)
	{
		return -1;
	}
	else if (error == -2)
	{
		return -2;
	}
	else if (error == 0)
	{

		for (i = 0;i < arraySize;i++)
		{
			//counter = 1;
			if ((array[i+1] - array[i]) == 1)
			{
				flag = 1;
				counter++;
			}
			else
			{
				if (counter > counter_max)
				{
					counter_max = counter;
					*sizeofLCS = counter_max+1;
				}
				counter = 0;
			}
			   //-10 0 1 2 3 4 5 7 8 9
		}
	}
	if (flag == 0)
	{
		return -3;
	}
	else
	{
		return 0;
	}
	
}


/*
* testing the lcsgetsize function
*/
void lcsGetSizetest(void)
{
	uint8_t value;
	int8_t error;
	int8_t element;
	int8_t size,i=0;
	int array[10] ={0};
	while (1)
	{

		printf("Test case : %d\n", i);
		i++;
		printf("enter the size of the array: ");
		scanf("%d", &size);
		printf("enter the arrays elements : ");
		for (element = 0;element < size;element++)
		{
			scanf("%d", &array[element]);
		}
		error = lcsGetSize(array, size, &value);
		if (error == -1)
		{
			printf("the array is empty\n");
		}
		else if (error == -2)
		{
			printf("the array size is 0 or >10\n");
		}
		else if (error == -3)
		{
			printf("there is no LCS\n");
		}
		else
			printf("%d\n", value);
		for (element = 0;element < 10;element++)
		{
			array[element] = 0;
		}
	}
	

}