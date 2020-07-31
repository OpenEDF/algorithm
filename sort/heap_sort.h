#ifndef __HEAP_SORT__H__
#define __HEAP_SORT__H__
/* heard file ------------------------------------------*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* define ----------------------------------------------*/
/* Note: Arrays count from zero */
#define ROOT(x)   (x - 1)
#define PARENT(x) ((x - 1) >> 1UL)
#define LEFT(x)   (((x + 1) << 1UL) - 1)
#define RIGHT(x)  ((x + 1) << 1UL)

/* function prototypes ----------------------------------*/
void swap(int *left, int *right);
void Max_HeapIfy(int *sequence, int index, int length);
void Build_Max_Heap(int *sequence, int length);
void Heap_Sort(int *sequence, int length);
void create_array(int *array, int size);

#endif  //!__HEAP_SORT__H__