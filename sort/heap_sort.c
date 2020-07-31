#include "heap_sort.h"

int main(int argc, char *argv[])
{
    int array[100];
    create_array(array, 100);

    /* print the array */
    printf("Before ordering array[] = { ");
    for (int i = 0; i < 100; i++)
        printf("%d ", array[i]);
    printf("}\n");

    Heap_Sort(array, 100);

    /* print the array */
    printf("After ordering array[]  = { ");
    for (int i = 0; i < 100; i++)
        printf("%d ", array[i]);
    printf("}\n");
    return 0;
}

/**
 * @name Max_HeapIfy
 * @brief Sorts the elements of a sequence used by Heap methods.
 * @param[in] [out] sequence: A sequence containing the elements to be sorted.
 * @retval None.
*/
void Max_HeapIfy(int *sequence, int index, int length)
{
    int left, right, largest;

    left = LEFT(index);
    right = RIGHT(index);

    /* on the array the first element is 0*/
    if((left <= length) && (*(sequence + left) > *(sequence + index)))
        largest = left;
    else
        largest = index;

    if((right <= length) && (*(sequence + right) > *(sequence + largest)))
        largest = right;

    if (largest != index)
    {
        swap((sequence + index), (sequence + largest));
        Max_HeapIfy(sequence, largest, length);
    }

}

/**
 * @name swap
 * @brief swap Exchange data between two pointer addresses.
 * @param[in] [out] left and right pointer addresses.
 * @retval None.
*/
void swap(int *left, int *right)
{
    /* usually function  */
    int temp = *left;
    *left = *right;
    *right = temp;
}

/**
 * @name Build_Max_Heap
 * @brief Build the maximum heap structure.
 * @param[in][out] sequence: Data to be sorted.
 * @param[in]  length: The length of the data.
 * @retval None.
*/
void Build_Max_Heap(int *sequence, int length)
{
    for (int i = length >> 1; i >= 0; i--)
        Max_HeapIfy(sequence, i, length);
}

/**
 * @name Heap_Sort
 * @brief Sort the data using a heap algorithm.
 * @param[in][out] sequence: Data to be sorted.
 * @param[in]  length: The length of the data.
 * @retval None.
*/
void Heap_Sort(int *sequence, int length)
{
    Build_Max_Heap(sequence, length);
    for(int i = length - 1; i > 0; i--)
    {
        swap(sequence, sequence + i);
        Max_HeapIfy(sequence, 0, i - 1);
    }
}

/**
 * @name create_array
 * @brief Creating random Numbers.
 * @param[in][out] array: Holds an array of random Numbers.
 * @param[in]  size: The number of the random Numbers.
 * @retval None.
*/
void create_array(int *array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand() % 100;
}

/*
Before ordering array[] = { 41 67 34 0 69 24 78 58 62 64 5 45 81
27 61 91 95 42 27 36 91 4 2 53 92 82 21 16 18 95 47 26 71 38 69
12 67 99 35 94 3 11 22 33 73 64 41 11 53 68 47 44 62 57 37 59 23
 41 29 78 16 35 90 42 88 6 40 42 64 48 46 5 90 29 70 50 6 1 93
48 29 23 84 54 56 40 66 76 31 8 44 39 26 23 37 38 18 82 29 41 }

After ordering array[]  = { 0 1 2 3 4 5 5 6 6 8 11 11 12 16 16 18
 18 21 22 23 23 23 24 26 26 27 27 29 29 29 29 31 33 34 35 35 36 37
 37 38 38 39 40 40 41 41 41 41 42 42 42 44 44 45 46 47 47 48 48 50
 53 53 54 56 57 58 59 61 62 62 64 64 64 66 67 67 68 69 69 70 71 73
 76 78 78 81 82 82 84 88 90 90 91 91 92 93 94 95 95 99 }
*/