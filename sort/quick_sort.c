#include <stdio.h>
#include <stdlib.h>

/* Function Declaration */
void printArray(int *array, int size);
void create_array(int *array, int size);
void swap(int *left, int *right);
int Partition(int *array, int sub_start, int sub_end);
void Quick_Sort(int *array, int start, int end);

/* Array size */
#define SIZE 100

/* main function */
int main(int argc, char *argv[])
{
    int array[SIZE];
    create_array(array, SIZE);
   // int array[SIZE] = {0, 5, 6, 7, 8, 3, 2, 4, 1, 9};
    printArray(array, SIZE);

    Quick_Sort(array, 0, SIZE - 1);

    printArray(array, SIZE);
    return 0;
}

/**
 * @name Quick_Sort
 * @brief Sorts the elements of a sequence used by Quick methods.
 * @param[in][out] array: A sequence containing the elements to be sorted.
 * @param[in] start: The beginning index of the first element.
 * @param[in] end: The end index of the last element.
 * @retval None.
*/
void Quick_Sort(int *array, int start, int end)
{
    int temp;
    if(start < end)
    {
        temp = Partition(array, start, end);
        Quick_Sort(array, start, temp - 1);
        Quick_Sort(array, temp + 1, end);
    }
}

/**
 * @name Partition
 * @brief sequence of partitions.
 * @param[in][out] array: A sequence containing the elements to be sorted.
 * @param[in] sub_start: The beginning index of the first element.
 * @param[in] sub_end: The end index of the last element.
 * @retval  .
*/
int Partition(int *array, int sub_start, int sub_end)
{
    int pivot = array[sub_end];
    int index = sub_start - 1;

    for(int j = sub_start; j <= sub_end - 1; j++)
    {
        if (array[j] <= pivot)
        {
            index++;
            swap(&array[index], &array[j]);
        }
    }
    /* swap */
    swap(&array[index + 1], &array[sub_end]);
    return index + 1;
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