#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns length of string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s && s[i])
		i++;
	return (i);
}

/**
 * _strcpy - copies string
 * @dest: destination
 * @src: source
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - creates new dog
 * @name: dog name
 * @age: dog age
 * @owner: dog owner
 * Return: pointer to new dog or NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *n, *o;

	if (name == 0 || owner == 0)
		return (0);

	d = malloc(sizeof(dog_t));
	if (d == 0)
		return (0);

	n = malloc(_strlen(name) + 1);
	if (n == 0)
	{
		free(d);
		return (0);
	}

	o = malloc(_strlen(owner) + 1);
	if (o == 0)
	{
		free(n);
		free(d);
		return (0);
	}

	_strcpy(n, name);
	_strcpy(o, owner);

	d->name = n;
	d->age = age;
	d->owner = o;

	return (d);
}
