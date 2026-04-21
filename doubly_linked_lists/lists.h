#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 */
typedef struct dlistint_s
{
	int n;
	struct dlistint_s *prev;
	struct dlistint_s *next;
} dlistint_t;

/**
 * print_dlistint - prints all elements of a dlistint_t list
 * @h: pointer to the head of the list
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h);

/**
 * dlistint_len - returns the number of elements in a linked list
 * @h: pointer to the head of the list
 *
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h);

/**
 * add_dnodeint - adds a new node at the beginning
 * @head: pointer to pointer of the head
 * @n: integer value
 *
 * Return: new node
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n);

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to pointer of the head of the list
 * @n: integer to store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Return: nothing
 */
void free_dlistint(dlistint_t *head);

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node, starting from 0
 *
 * Return: nth node, or NULL if node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index);

/**
 * sum_dlistint - returns the sum of all the data of a dlistint_t list
 * @head: pointer to the head of the list
 *
 * Return: sum of all the data, or 0 if the list is empty
 */
int sum_dlistint(dlistint_t *head);

#endif
