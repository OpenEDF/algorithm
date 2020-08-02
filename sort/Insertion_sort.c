#include <stdio.h>

/* Function Declaration */
void Insertion_Sort(int *sequence, int length);

int main(int argc, char *argv[])
{
    int nums = 10;
    int array[10] = {5, 2, 4, 6, 1, 3, 25, 96, 255, 3};
    printf("array: ");
    for (int i = 0; i < 10; i++)
        printf(" %d", array[i]);
    printf("\n");

    Insertion_Sort(array, nums);

    printf("array: ");
    for (int i = 0; i < 10; i++)
        printf(" %d", array[i]);
    printf("\n");

    return 0;
}

/**
 * @name Insertion_Sort
 * @brief Sorts the elements of a sequence used by Insertion methods.
 * @param[in][out] sequence: A sequence containing the elements to be sorted.
 * @param[in] length: the number of elements for sequence.
 * @retval None.
*/
void Insertion_Sort(int *sequence, int length)
{
    int key, index_f;
    /* extract the key */
    for (int index = 1; index < length; index++)
    {
        key = sequence[index];
        /* insertion the key to the sequence[0, index - 1] */
        index_f = index - 1;
        while((index_f >= 0) && (sequence[index_f] > key))
        {
            sequence[index_f + 1] = sequence[index_f];
            index_f--;
        }
        sequence[index_f + 1] = key;
    }
}