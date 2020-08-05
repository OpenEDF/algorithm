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