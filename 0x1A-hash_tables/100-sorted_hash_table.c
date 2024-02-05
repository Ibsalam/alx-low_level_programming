#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *shash_table = NULL;

    shash_table = malloc(sizeof(shash_table_t));
    if (shash_table == NULL)
        return (NULL);

    shash_table->size = size;
    shash_table->array = calloc(size, sizeof(shash_node_t *));
    if (shash_table->array == NULL)
    {
        free(shash_table);
        return (NULL);
    }
    shash_table->shead = NULL;
    shash_table->stail = NULL;

    return (shash_table);
}

/**
 * shash_table_set - Adds an element to the sorted hash table
 * @ht: The sorted hash table to add or update the key/value to
 * @key: The key
 * @value: The value associated with the key
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node = NULL, *current = NULL, *prev = NULL;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
        return (0);

    index = key_index((const unsigned char *)key, ht->size);

    current = ht->shead;
    while (current && strcmp(current->key, key) < 0)
    {
        prev = current;
        current = current->snext;
    }

    if (current && strcmp(current->key, key) == 0)
    {
        free(current->value);
        current->value = strdup(value);
        if (current->value == NULL)
            return (0);
        return (1);
    }

    new_node = malloc(sizeof(shash_node_t));
    if (new_node == NULL)
        return (0);

    new_node->key = strdup(key);
    if (new_node->key == NULL)
    {
        free(new_node);
        return (0);
    }

    new_node->value = strdup(value);
    if (new_node->value == NULL)
    {
        free(new_node->key);
        free(new_node);
        return (0);
    }

    new_node->snext = current;
    if (prev)
        prev->snext = new_node;
    else
        ht->shead = new_node;

    if (current == NULL)
        ht->stail = new_node;

    if (ht->array[index] == NULL)
        ht->array[index] = new_node;

    return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key from the sorted hash table
 * @ht: The sorted hash table to look into
 * @key: The key you are looking for
 *
 * Return: The value associated with the element, or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    shash_node_t *node;
    unsigned long int index;

    if (ht == NULL || key == NULL || *key == '\0')
        return (NULL);

    index = key_index((const unsigned char *)key, ht->size);

    node = ht->array[index];

    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return (node->value);
        node = node->next;
    }

    return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table
 * @ht: The sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
    shash_node_t *node;
    int first = 1;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->shead;
    while (node)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        first = 0;
        node = node->snext;
    }
    printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order
 * @ht: The sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    shash_node_t *node;
    int first = 1;

    if (ht == NULL)
        return;

    printf("{");
    node = ht->stail;
    while (node)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", node->key, node->value);
        first = 0;
        node = node->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
    shash_node_t *node, *tmp;

    if (ht == NULL)
        return;

    node = ht->shead;
    while (node)
    {
        tmp = node->snext;
        free(node->key);
        free(node->value);
        free(node);
        node = tmp;
    }

    free(ht->array);
    free(ht);
}
