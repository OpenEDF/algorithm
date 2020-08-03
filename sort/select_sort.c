#include <stdio.h>
#include <stdlib.h>
/* Function Declaration */
void printArray(int *array, int size);
void create_array(int *array, int size);
void swap(int *left, int *right);
void Selection_Sort(int *array, int length);
/* Array size */
#define SIZE 10

/* main function */
int main(int argc, char *argv[])
{
    int array[SIZE];
    create_array(array, SIZE);
    printArray(array, SIZE);

    Selection_Sort(array, SIZE);

    printArray(array, SIZE);
    return 0;
}

/**
 * @name selection_Sort
 * @brief Sorts the elements of a sequence used by Insertion methods.
 * @param[in][out] array: A sequence containing the elements to be sorted.
 * @param[in] length:  All the number of all elements for sequence.
 * @retval None.
*/
void Selection_Sort(int *array, int length)
{
    int smallest;

    /* sore */
    for (int index = 0; index < length - 1; index++)
    {
        smallest = index;
        for (int index_in = index + 1; index_in < length; index_in++)
        {
            if (array[index_in] < array[smallest])
                smallest = index_in;
            /* swap the smallest element to the forward */
            swap(&array[index], &array[smallest]);
        }
    }
}

/**
 * @name printArray
 * @brief print the elements for a array.
 * @param[in][out] array: array to be printed.
 * @param[in] size : the number of elements for array.
 * @retval None.
*/
void printArray(int *array, int size)
{
    int i;
    printf("ARRAY: ");
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
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

/**
 * @name swap
 * @brief swap Exchange data between two pointer addresses.
 * @param[in] [out] left and right pointer addresses.
 * @retval None.
*/
void swap(int *left, int *right)
{
    int temp = *left;
    *left = *right;
    *right = temp;
}

/* result */
/*
ARRAY: 41 67 34 0 69 24 78 58 62 64
ARRAY: 0 24 34 41 58 64 62 67 69 78
*/