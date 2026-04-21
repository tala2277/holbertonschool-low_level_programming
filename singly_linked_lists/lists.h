#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct list_s - singly linked list
 * @str: string
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/**
 * print_list - prints all elements of a list_t list
 * @h: pointer to the head
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h);

/**
 * list_len - returns the number of elements in a linked list
 * @h: pointer to the head
 *
 * Return: number of nodes
 */
size_t list_len(const list_t *h);

/**
 * add_node - adds a new node at the beginning
 * @head: pointer to pointer of head
 * @str: string to duplicate
 *
 * Return: new node
 */
list_t *add_node(list_t **head, const char *str);

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: pointer to pointer of the head
 * @str: string to duplicate
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str);

#endif
