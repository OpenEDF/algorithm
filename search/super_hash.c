#include <stdio.h>
#include <stdlib.h>

/* struct  */
typedef struct List{
    int data;
    struct List *next;
}List;

typedef struct{
    int key;
    int listsize; /* the length of link */
    int length;   /* ral Numbers of list */
    List *list;
}SET;

/* define */
#define LIST_INCREMENT  5
#define SIZE_TEST 100
#define SIZE 10
#define HASH_FUNCTION(data) ((data) % SIZE)
const int HASH_KEY[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

/* Function Declaration */
SET *Init_HashTable(void);
void Inser_Hash(SET *hashtable, int data);
void Remove_element(SET *hashtable, int key);
int Search_element(SET *hashtable, int data);
void Display_Hash(SET *hashtable, int size);
void create_array(int *array, int size);
void printArray(int *array, int size);
/* main function */
int main(int argc, char *argv[])
{
    SET *HASH;
    int index = 0;
    int array[SIZE_TEST];

    /* initalization */
    printf("The Initalization function test.\n");
    HASH = Init_HashTable();
    create_array(array, SIZE_TEST);
    printArray(array, SIZE_TEST);

    /* inser  */
    printf("The Inser function test.\n");
    for (int i = 0; i < SIZE_TEST; i++)
        Inser_Hash(HASH, array[i]);
    Display_Hash(HASH, SIZE);

    /* remove  */
    printf("The Remove function test.\n");
    Remove_element(HASH, 11);
    Display_Hash(HASH, SIZE);

    /* search */
    index = Search_element(HASH, 88);
    if(index < 0)
        printf("The data index is not found.\n");
    else
        printf("The data index is %d key %d.\n", HASH_FUNCTION(8), index);

    /* free hash */
    free(HASH);

    return 0;
}

/**
 * @name Init_array
 * @brief Crate and Initaliation a array.
 * @param[in] None.
 * @retval the pointer for hashtable or NULL.
*/
SET *Init_HashTable(void)
{
    SET *hashtable;
    /* create the array and set the 0. */
    hashtable = (SET *)malloc(sizeof(SET) * SIZE);
    if (hashtable == NULL)
        return NULL;
    for (int i = 0; i < SIZE; i++)
    {
        hashtable[i].key = HASH_KEY[i];
        hashtable[i].listsize = 0;
        hashtable[i].length = 0;
    }
    return hashtable;
}

/**
 * @name Inser_Hash
 * @brief Insert the data to the hash table.
 * @param[in][out] hashtable: hash tablie pointer for data to be inserted.
 * @param[in] data: the data to be inserted.
 * @retval None.
*/
void Inser_Hash(SET *hashtable, int data)
{
    int index;
    List *list, *newbase;
    /* calculater the index */
    index = HASH_FUNCTION(data);
    if(hashtable[index].key != index)
        return;

    /* dynamic allocation memory */
    if (hashtable[index].length == 0)
    {
        list = (List *)malloc(sizeof(List) * LIST_INCREMENT);
        if(list == NULL)
            return;

        hashtable[index].length = LIST_INCREMENT;
        hashtable[index].list = list;
        list->data = data;
        hashtable[index].listsize++;
        return;
    }
    /* realloc allocation memory when memory is more less */
    if (hashtable[index].length == hashtable[index].listsize)
    {
        hashtable[index].length += LIST_INCREMENT;
        newbase = (List *)realloc(hashtable[index].list, (hashtable[index].length * sizeof(List)));
        if(newbase == NULL)
            return;

        hashtable[index].list = newbase;
    }
    /*  */
    list = hashtable[index].list + hashtable[index].listsize;
    hashtable[index].listsize++;
    list->data = data;
}
/**
 * @name Remove_element
 * @brief Remove the data to the hash table depend of the key.
 * @param[in][out] hashtable: hash tablie pointer for data to be inserted.
 * @param[in] key: the data to be removed from the key table.
 * @retval None.
*/
void Remove_element(SET *hashtable, int key)
{
    int index;
    /* check hash table */
    if (hashtable == NULL)
        return;
    /* check key is valid */
    index = HASH_FUNCTION(key);
    if((hashtable[index].key = index) && (hashtable[index].listsize > 0))
    {
        /* free memory */
        free(hashtable[index].list);
        hashtable[index].listsize = 0;
        hashtable[index].length = 0;
    }
    else
        printf("The key is error.\n");
}

/**
 * @name Search_element
 * @brief search the data from the hash table.
 * @param[in][out] hashtable: hash tablie pointer for data to be inserted.
 * @param[in] data: the data to be found from the hashtable table.
 * @retval the index of the data.
 *  @arg -1 is indicated no data was found, otherwise indicated data index.
*/
int Search_element(SET *hashtable, int data)
{
    int key;
    /* check the hash table*/
    if (hashtable == NULL)
        return -1;

    /* calculater key */
    key = HASH_FUNCTION(data);
    if((hashtable[key].key = key) && (hashtable[key].listsize > 0))
    {
        /* free memory */
        for(int i = 0; i < hashtable[key].listsize; i++)
        {
            if((hashtable[key].list + i)->data == data)
                return i;
        }
    }
    return -1;
}
/**
 * @name Display_Hash
 * @brief Display the Hash Table key and value.
 * @param[in][out] hashtable: hash tablie pointer for data to be inserted.
 * @param[in] size: the number of elements for hash table key.
 * @retval None.
*/
void Display_Hash(SET *hashtable, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Hash table key:\t%d, length:\t%d, listsize:\t%d.\n", hashtable[i].key, hashtable[i].length, hashtable[i].listsize);
        for (int j = 0; j < hashtable[i].listsize; j++)
        {
            printf("%d  ", (hashtable[i].list + j)->data);
        }
        printf("\n");
    }
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

/* result */
/*
The Initalization function test.
ARRAY: 41 67 34 0 69 24 78 58 62 64 5 45 81 27 61 91 95 42 27 36 91 4 2 53 92 82 21 16 18 95 47 26 71 38 69 12 67 99 35 94 3 11
22 33 73 64 41 11 53 68 47 44 62 57 37 59 23 41 29 78 16 35 90 42 88 6 40 42 64 48 46 5 90 29 70 50 6 1 93 48 29 23 84 54 56 40
66 76 31 8 44 39 26 23 37 38 18 82 29 41

The Inser function test.
Hash table key: 0, length:      10, listsize:   7.
0  90  40  90  70  50  40
Hash table key: 1, length:      15, listsize:   14.
41  81  61  91  91  21  71  11  41  11  41  1  31  41
Hash table key: 2, length:      15, listsize:   11.
62  42  2  92  82  12  22  62  42  42  82
Hash table key: 3, length:      10, listsize:   9.
53  3  33  73  53  23  93  23  23
Hash table key: 4, length:      15, listsize:   11.
34  24  64  4  94  64  44  64  84  54  44
Hash table key: 5, length:      10, listsize:   7.
5  45  95  95  35  35  5
Hash table key: 6, length:      15, listsize:   11.
36  16  26  16  6  46  6  56  66  76  26
Hash table key: 7, length:      10, listsize:   9.
67  27  27  47  67  47  57  37  37
Hash table key: 8, length:      15, listsize:   12.
78  58  18  38  68  78  88  48  48  8  38  18
Hash table key: 9, length:      10, listsize:   9.
69  69  99  59  29  29  29  39  29

The Remove function test.
Hash table key: 0, length:      10, listsize:   7.
0  90  40  90  70  50  40
Hash table key: 1, length:      0, listsize:    0.

Hash table key: 2, length:      15, listsize:   11.
62  42  2  92  82  12  22  62  42  42  82
Hash table key: 3, length:      10, listsize:   9.
53  3  33  73  53  23  93  23  23
Hash table key: 4, length:      15, listsize:   11.
34  24  64  4  94  64  44  64  84  54  44
Hash table key: 5, length:      10, listsize:   7.
5  45  95  95  35  35  5
Hash table key: 6, length:      15, listsize:   11.
36  16  26  16  6  46  6  56  66  76  26
Hash table key: 7, length:      10, listsize:   9.
67  27  27  47  67  47  57  37  37
Hash table key: 8, length:      15, listsize:   12.
78  58  18  38  68  78  88  48  48  8  38  18
Hash table key: 9, length:      10, listsize:   9.
69  69  99  59  29  29  29  39  29

The data index is 8 key 6.
*/
