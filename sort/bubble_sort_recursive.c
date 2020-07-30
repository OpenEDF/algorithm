#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef enum
{
    OK = 1,
    ERROR = -1
}FunctionStatus;

FunctionStatus Bubble_Sort_recur(int *sequence, int length);

int main(int argc, char *argv[])
{
    int nums;
    int array[] = {5, 8, 9, 6, 0, 1, 3, 4, 7, 2};
    nums = sizeof(array) / sizeof(array[0]);

    printf("Before ordering array[] = { ");
    for (int i = 0; i < nums; i++)
        printf("%d ", array[i]);
    printf("}\n");

    Bubble_Sort_recur(array, nums);

    /* print the array */
    printf("After orderingarray[]   = { ");
    for (int i = 0; i < nums; i++)
        printf("%d ", array[i]);
    printf("}\n");
    return 0;
}

/**
 * @name Bubble_Sort_recur
 * @brief Sorts the elements of a sequence used by Bubble methods impletement the
 *        recursive.
 * @param[in][out] sequence: A sequence containing the elements to be sorted.
 * @param[in] length: the number of elements for sequence.
 * @retval Function operation status.
 *  OK, operation successful.
 *  ERROR, operation failed.
 * TODO: None.
 * BUG: None.
*/
FunctionStatus Bubble_Sort_recur(int *sequence, int length)
{
    int temp;
    /* judge the sequence is valid ang the length*/
    if ((sequence == NULL) || (length < 2))
        return ERROR;

    /* bubble sort */
    for (int inside = 0; inside < length - 1; inside++)
    {
        if (sequence[inside] > sequence[inside + 1])
        {
            /* swap place */
            temp = sequence[inside];
            sequence[inside] = sequence[inside + 1];
            sequence[inside + 1] = temp;
        }
    }
    Bubble_Sort_recur(sequence, length - 1);
    return OK;
}