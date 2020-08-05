#include <stdio.h>
#include <stdlib.h>

/* struct  */
typedef struct{
    int key;
    int data;
}SET;
/* define */
#define SIZE 10
#define HASH_FUNCTION(data) ((data) % SIZE)

/* Function Declaration */
SET *Init_array(int size);
void Inser_Hash(SET *hashtable, int data);
void Remove_element(SET *hashtable, int key);
int Search_element(SET *hashtable, int data);
void Display_Hash(SET *hashtable, int size);
void create_array(int *array, int size);

/* main function */
int main(int argc, char *argv[])
{
    SET *HASH;
    int array[SIZE] = {88, 80, 85, 83, 84, 82, 81, 89, 87, 86};
    HASH = Init_array(SIZE);
    for (int i = 0; i < SIZE; i++)
        Inser_Hash(HASH, array[i]);
    Display_Hash(HASH, SIZE);

    /* search the data */
    if((Search_element(HASH, 7) + 1) != 0)
        printf("The search index is %d.\n", Search_element(HASH, 7));
    else
        printf("The search is failed\n");

    free(HASH);
    return 0;
}

/**
 * @name Init_array
 * @brief Crate and Initaliation a array.
 * @param[in] key: the number of elements for array.
 * @retval the pointer for hashtable or NULL.
*/
SET *Init_array(int size)
{
    SET *hashtable;
    /* create the array and set the 0. */
    hashtable = (SET *)malloc(sizeof(SET) * size);
    if (hashtable == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
    {
        hashtable[i].key = HASH_FUNCTION(i);
        hashtable[i].data = -1;
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
    /* calculater the index */
    index = HASH_FUNCTION(data);
    if((hashtable[index].key == index) && (hashtable[index].data == -1))
    {
        hashtable[index].data = data;
    }
    else
    {
        printf("Data conflict.\n");
        return;
    }
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
    /* calculater the index */
    index = HASH_FUNCTION(key);
    if((hashtable[index].key == index) || (hashtable[index].data) != -1)
    {
        hashtable[index].data = -1;
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
    int index = -1;
    /* judge the hash is valid */
    if (hashtable == NULL)
        return -1;
    /* calculater the key value via data */
    index = HASH_FUNCTION(data);

    /* if the data exists in the hash table */
    if((hashtable[index].key == index) && (hashtable[index].data == data))
        return index;

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
        printf("Hash table key\t%d, data\t%d.\n", hashtable[i].key, hashtable[i].data);
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