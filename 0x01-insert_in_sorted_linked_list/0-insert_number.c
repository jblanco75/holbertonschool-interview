#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: head of the linked list
 * @number: number to be inserted
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *tmp;
	listint_t *new = malloc(sizeof(listint_t));

	tmp = *head;

	if (!new)
		return (NULL);

	new->n = number;
	new->next = NULL;

	if (!*head || tmp->n >= number)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		while (tmp->next != NULL && tmp->next->n <= number)
		{
			tmp = tmp->next;
		}
		if (tmp->next != NULL)
		{
			new->next = tmp->next;
		}
		tmp->next = new;
	}
	return (new);
}
