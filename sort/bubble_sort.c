#include <stdio.h>
#include <stdint.h>
#include <time.h>

typedef enum
{
    OK = 1,
    ERROR = -1
}FunctionStatus;

FunctionStatus Bubble_Sort(int *sequence, int length);

int main(int argc, char *argv[])
{
    int nums;
    clock_t start, stop;
    double usetime;

    int array[] = {5, 8, 9, 6, 0, 1, 3, 4, 7, 2};
    nums = sizeof(array) / sizeof(array[0]);

    printf("Before ordering array[] = { ");
    for (int i = 0; i < nums; i++)
        printf("%d ", array[i]);
    printf("}\n");

    start = clock();
    /*start execution function*/

    Bubble_Sort(array, nums);

    /*stop execution function*/
    stop = clock();
    usetime = (double)(stop - start)/CLK_TCK;

    /* print the array */
    printf("After orderingarray[]   = { ");
    for (int i = 0; i < nums; i++)
        printf("%d ", array[i]);
    printf("}\n");
    printf("The Algorithm execution time is %fS.\n", usetime);
    return 0;
}

/**
 * @name Bubble_Sort
 * @brief Sorts the elements of a sequence used by Bubble methods.
 * @param[in][out] sequence: A sequence containing the elements to be sorted.
 * @param[in] length: the number of elements for sequence.
 * @retval Function operation status.
 *  OK, operation successful.
 *  ERROR, operation failed.
 * TODO: None.
 * BUG: None.
*/
FunctionStatus Bubble_Sort(int *sequence, int length)
{
    int temp;
    /* judge the sequence is valid ang the length*/
    if ((sequence == NULL) || (length < 2))
        return ERROR;

    /* bubble sort */
    length--;
    for (int outside = length; outside > 0; outside--)
    {
        for (int inside = 0; inside < outside; inside++)
        {
            if (sequence[inside] > sequence[inside + 1])
            {
                /* swap place */
                temp = sequence[inside];
                sequence[inside] = sequence[inside + 1];
                sequence[inside + 1] = temp;
            }
        }
    }
    return OK;
}