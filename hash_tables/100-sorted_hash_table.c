#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int add_new_node(shash_table_t *ht, const char *key,
	const char *value, unsigned long int index);

/**
 * shash_table_create - creates sorted hash table
 * @size: size
 * Return: pointer or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * insert_sorted - insert node in sorted list
 * @ht: table
 * @node: node
 */
void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (!ht->shead)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	tmp = ht->shead;
	while (tmp && strcmp(node->key, tmp->key) > 0)
		tmp = tmp->snext;

	if (tmp == ht->shead)
	{
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	}
	else if (!tmp)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else
	{
		node->snext = tmp;
		node->sprev = tmp->sprev;
		tmp->sprev->snext = node;
		tmp->sprev = node;
	}
}

/**
 * shash_table_set - set value
 * @ht: table
 * @key: key
 * @value: value
 * Return: 1 or 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node;
	char *v;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			v = strdup(value);
			if (!v)
				return (0);

			free(node->value);
			node->value = v;
			return (1);
		}
		node = node->next;
	}

	return (add_new_node(ht, key, value, index));
}


/**
 * add_new_node - adds a new sorted hash node
 * @ht: table
 * @key: key
 * @value: value
 * @index: array index
 * Return: 1 or 0
 */
int add_new_node(shash_table_t *ht, const char *key,
	const char *value, unsigned long int index)
{
	shash_node_t *new;

	new = malloc(sizeof(shash_node_t));
	if (!new)
		return (0);

	new->key = strdup(key);
	new->value = strdup(value);
	if (!new->key || !new->value)
	{
		free(new->key);
		free(new->value);
		free(new);
		return (0);
	}

	new->next = ht->array[index];
	new->sprev = NULL;
	new->snext = NULL;
	ht->array[index] = new;
	insert_sorted(ht, new);

	return (1);
}

/**
 * shash_table_get - get value
 * @ht: table
 * @key: key
 * Return: value or NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (!ht || !key || *key == '\0')
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
 * shash_table_print - print sorted
 * @ht: table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int comma;

	if (!ht)
		return;

	printf("{");

	node = ht->shead;
	comma = 0;

	while (node)
	{
		if (comma)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma = 1;
		node = node->snext;
	}

	printf("}\n");
}

/**
 * shash_table_print_rev - print reverse
 * @ht: table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int comma;

	if (!ht)
		return;

	printf("{");

	node = ht->stail;
	comma = 0;

	while (node)
	{
		if (comma)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		comma = 1;
		node = node->sprev;
	}

	printf("}\n");
}

/**
 * shash_table_delete - delete table
 * @ht: table
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node, *tmp;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			tmp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = tmp;
		}
	}

	free(ht->array);
	free(ht);
}
