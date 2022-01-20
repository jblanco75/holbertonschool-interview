#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * is_palindrome- prints all elements of a listint_t list
 * @head: pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	size_t i, new;
	int array[2048];
	listint_t *tmp;

	tmp = *head;
	if (tmp == NULL)
		return (1);

	if (tmp != NULL)
	{
		for (new = 0; tmp != NULL; tmp = tmp->next, new++)
			array[new] = tmp->n;
	}
	for (i = 0; i < new / 2; i++)
	{
		if (array[i] != array[new - i - 1])
			return (0);
	}
	return (1);
}
