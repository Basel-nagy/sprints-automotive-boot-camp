/*including section*/
#include"sort.h"
static uint8_t n = 0;
/*functions impelementation*/


/* Description:
 * - This function takes a reference to an array of integers
 * - Sorts the array in ascending order
 * - Using the insertion sort algorithm
 * Return:
 * - returns -1 if the array is empty
 * - returns -2 if the array size is 0 or >10
 * - returns 0 if sorting is done without errors
 */
int8_t insertionSort(int32_t* array, uint8_t arraySize)
{   
	int8_t i=0,j=0;
	uint8_t flag = 0;
	if (arraySize>10 || arraySize==0)
	{
		return -2;
	}
	for (i = 0;i < arraySize;i++)
	{
		if (0 != array[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		return -1;
	}
	else
	{
		int32_t temp;
		for (i = 0;i < arraySize;i++)
		{ 
			temp = array[i];
			for (j = i - 1;j >= 0 && temp < array[j];j--)
			{
				array[j + 1] = array[j];
			}
			array[j+1] = temp;
		}
		
	}
	return 0;
	
}



/* Description:
 * - This function takes a reference to an array of integers
 * - Prints all array elements
 * Return:
 * - Nothing to return
 */
void printArray(int32_t* array, uint8_t arraySize)
{
	uint8_t i;
	for (i = 0;i < arraySize;i++)
	{
		printf("%d ", array[i]);
	}
}

/*
* description : test sorting of the array
* input:void
* return: void
*/
void sortingarraytest(void)
{
	uint8_t i = 0;
	int32_t error, element;
	uint8_t size = 0;
	int32_t array[10]={0};
	while (1)
	{
		
		printf("Test case : %d\n", i);
		i++;
		printf("enter the size of the array: ");
		scanf("%d", &size);
		printf("enter the arrays elements : ");
		getchar() != '\n';
		for (element = 0;element < size;element++)
		{
			
				scanf("%d", &array[element]);
	
			
		}
		
			
		error=insertionSort(array, size);
		if (error == -1)
			printf("array is empty\n");
		else if (error == -2)
		{
			printf("array size is larger than 10\n");
		}
		else {
			printArray(array, size);
			printf("\n");
		}
		for (element = 0;element < 10;element++)
		{
			array[element] = 0;
		}
	}
	
}