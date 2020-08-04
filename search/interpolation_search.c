#include <stdio.h>
#include <stdlib.h>

/* Function Declaration */
void printArray(int *array, int size);
int Interpolation_Search(int *array, int low, int high, int aim);

/* Array size */
#define SIZE 10
#define AIM 4
/* main function */
int main(int argc, char *argv[])
{
    int index;
    int array[SIZE] = {0, 1, 4, 5, 5, 5, 6, 7, 8, 9};
    printArray(array, SIZE);

    /* Suppose the array is an ordered sequence. */

    /* Find the index of the first element */
    index = Interpolation_Search(array, 0, SIZE - 1, AIM);

    printf("The array[%d] = %d.\n", index, AIM);
    return 0;
}

/**
 * @name Interpolation_Search
 * @brief find the aim elements from array used Interpolation Search.
 * @param[in][out] array: array to be found the aim elements.
 * @param[in] high : High interval position for array.
 * @param[in] low : Low interval position for array..
 * @param[in] aim: the aim elements value to be found
 * @retval the index of the aim elements.
 * TODO: ARRAY IS THE SORTED.
*/
int Interpolation_Search(int *array, int low, int high, int aim)
{
    int middle;
    /* Judge operational effectiveness  */
    if ((low == high) || (array[low] == array[high]))
        return -1;

    /* calaulater the middle elements index */
    middle = low + (((high - low) / (array[high] - array[low])) * (aim -array[low]));

    /* judge the middle elements is match aim return */
    if (aim == array[middle])
        return middle;

    /* recursive called the Interpolation_Search for left */
    if (aim > array[middle])
        return Interpolation_Search(array, middle + 1, high, aim);

    /* recursive called the Interpolation_Search for right */
    if (aim < array[middle])
        return Interpolation_Search(array, low, middle - 1, aim);
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
