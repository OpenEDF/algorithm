#include <stdio.h>
#include <stdlib.h>

/* Function Declaration */
void printArray(int *array, int size);
void create_array(int *array, int size);
void swap(int *left, int *right);
void Counting_Sort(int *array, int length);

/* Array size */
#define SIZE 10

/* main function */
int main(int argc, char *argv[])
{
    int array[SIZE];
    create_array(array, SIZE);

    printArray(array, SIZE);

    Counting_Sort(array, SIZE);
    printArray(array, SIZE);
    return 0;
}

/**
 * @name Binary_Search
 * @brief find the aim elements from array used Binary Search.
 * @param[in][out] array: array to be found the aim elements.
 * @param[in] length : the number of elements for array.
 * @retval None.
*/
void Counting_Sort(int *array, int length)
{
    int *temp_array;
    int count, j = 0;
    /* calculater the maximum element */
    int max = array[0];
    for (int i = 1; i < length; i++)
    {
        if(array[i] > max)
            max = array[i];
    }
    /* create the maximum + 1 size array and set to the 0 */
    if (NULL == (temp_array = malloc((max + 1) * sizeof(int))))
        return;
    max++;
    for(int i = 0; i < max; i++)
        temp_array[i] = 0;

    /* store the count of each element in the array index */
    for (int i = 0; i < length; i++)
        temp_array[array[i]]++;

    /* store the element to array */
    for (int i = 0; i < max; i++)
    {
        count = temp_array[i];
        while(count--)
            array[j++] = i;
    }
    /* free memory */
    free(temp_array);
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
        array[i] = rand() % 10;
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
ARRAY: 1 7 4 0 9 4 8 8 2 4
ARRAY: 0 1 2 4 4 4 7 8 8 9
*/