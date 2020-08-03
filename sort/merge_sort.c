#include <stdio.h>
#include <stdlib.h>

/* Function Declaration */
void printArray(int *array, int size);
void Merge(int *sequence, int start, int middle, int end);
void Merge_Sort(int *sequence, int start, int end);
void create_array(int *array, int size);

/* Array size */
#define SIZE 10
/* main function */
int main(int argc, char *argv[])
{
    int array[SIZE];
    create_array(array, SIZE);
    printArray(array, SIZE);

    Merge_Sort(array, 0, SIZE - 1);

    printArray(array, SIZE);
    return 0;
}

/**
 * @name Merge_Sort
 * @brief Sorts the elements of a sequence used by Insertion methods.
 * @param[in][out] sequence: A sequence containing the elements to be sorted.
 * @param[in] start: the start index elements for sequence.
 * @param[in] end: the end index elements for sequence.
 * @retval None.
*/
void Merge_Sort(int *sequence, int start, int end)
{
    int middle;
    /* redivide */
    if (end > start)
    {
        middle = (start + end) / 2;
        Merge_Sort(sequence, start, middle);
        Merge_Sort(sequence, middle + 1, end);
        Merge(sequence, start, middle, end);
    }
}

/**
 * @name Merge
 * @brief Sorts the elements of a sequence used by merge methods.
 * @param[in][out] sequence: A sequence containing the elements to be sorted.
 * @param[in] start: start index for sequence.
 * @param[in] middle: middle index for sequence.
 * @param[in] end: end index for sequence.
 * @retval None.
 * BUG: malloc dynamic memory allocation need check address in
*/
void Merge(int *sequence, int start, int middle, int end)
{
    int i, j, k;
    int l_size = middle - start + 1;
    int r_size = end - middle;

    /* bug check pointer valid */
    int *l_array = (int *)malloc(l_size * sizeof(int));
    int *r_array = (int *)malloc(r_size * sizeof(int));

    /* store the data to array */
    for (i = 0; i < l_size; i++)
        l_array[i] = sequence[start + i];
    for (j = 0; j < r_size; j++)
        r_array[j] = sequence[middle + j + 1];

    /* sore */
    i = j = 0;
    k = start;
    while (i < l_size && j < r_size)
    {
        if(l_array[i] <= r_array[j])
            sequence[k++] = l_array[i++];
        else
            sequence[k++] = r_array[j++];
    }

    /* restore array elements */
    if(i < l_size)
	{
		while(i < l_size)
            sequence[k++] = l_array[i++];
    }

	if(j < r_size)
	{
		while(j < r_size)
			sequence[k++] = r_array[j++];
	}
    /* free memory */
    free(l_array);
    free(r_array);
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

/* result */
/*
ARRAY: 41 67 34 0 69 24 78 58 62 64
ARRAY: 0 24 34 41 58 62 64 67 69 78
*/