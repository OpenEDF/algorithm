#include <stdio.h>
#include <stdlib.h>

/* Function Declaration */
void printArray(int *array, int size);
int Linear_Search(int *array, int size, int aim);

/* Array size */
#define SIZE 10

/* main function */
int main(int argc, char *argv[])
{
    int index;
    int array[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printArray(array, SIZE);

    /* Find the index of the first element */
    index = Linear_Search(array, SIZE, 6);

    printf("The array[%d] = 6.\n", index);
    return 0;
}

/**
 * @name Linear_Search
 * @brief find the aim elements from array used Linear Search.
 * @param[in][out] array: array to be found the aim elements.
 * @param[in] size : the number of elements for array.
 * @param[in] aim: the aim elements value to be found
 * @retval the index of the aim elements.
*/
int Linear_Search(int *array, int size, int aim)
{
    for(int index = 0; index < size; index++)
    {
        if (array[index] == aim)
            return index;
    }
    return -1;
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