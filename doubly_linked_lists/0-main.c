#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

int main(void)
{
	dlistint_t *head;
	dlistint_t *new;
	dlistint_t hello = {8, NULL, NULL};
	size_t n;

	head = &hello;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
	{
		printf("Error\n");
		return (1);
	}
	new->n = 9;
	head->prev = new;
	new->next = head;
	new->prev = NULL;
	head = new;
	n = print_dlistint(head);
	printf("-> %lu elements\n", n);
	free(new);
	return (0);
}
