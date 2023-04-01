#ifndef _SORT_H_
#define _SORT_H_
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
/*typedef*/
typedef signed long int32_t;
typedef unsigned char uint8_t;
typedef signed char int8_t;


/*functions prototypes*/
int8_t insertionSort(int32_t* array, uint8_t arraySize);
void printArray(int32_t* array, uint8_t arraySize);
void sortingarraytest(void);
#endif
