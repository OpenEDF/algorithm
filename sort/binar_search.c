#include <stdio.h>
#include <stdlib.h>

/* Function Declaration */
void printArray(int *array, int size);
int Binary_Search(int *array, int low, int high, int aim);

/* Array size */
#define SIZE 10
#define AIM 5
/* main function */
int main(int argc, char *argv[])
{
    int index;
    int array[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printArray(array, SIZE);

    /* Suppose the array is an ordered sequence. */

    /* Find the index of the first element */
    index = Binary_Search(array, 0, SIZE, AIM);

    printf("The array[%d] = %d.\n", index, AIM);
    return 0;
}

/**
 * @name Binary_Search
 * @brief find the aim elements from array used Binary Search.
 * @param[in][out] array: array to be found the aim elements.
 * @param[in] high : High interval position for array.
 * @param[in] low : Low interval position for array..
 * @param[in] aim: the aim elements value to be found
 * @retval the index of the aim elements.
 * TODO: ARRAY IS THE SORTED.
*/
int Binary_Search(int *array, int low, int high, int aim)
{
    int middle;
    /* check the input arguments */
    if (low >= high) return -1;

    /* serach the index for array */
    middle = (low + high) >> 1;
    if (aim == array[middle])
        return middle;
    else if (aim < array[middle])
        /* search the left half */
        return Binary_Search(array, low, middle - 1, aim); /* Recursive */
    else
        /* search the right half */
        return Binary_Search(array, middle + 1, high, aim); /* Recursive */
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
