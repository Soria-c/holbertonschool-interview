#include "lists.h"

/**
 * insert_node- adds a new node at its right position
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node;
	listint_t *tmp;

	if (!head)
		return (NULL);
	node = malloc(sizeof(listint_t));
	if (!node)
		return (NULL);
	node->n = number;

	if (!(*head) || node->n < (*head)->n)
	{
		node->next = (*head);
		(*head) = node;
	}
	else
	{
		tmp = (*head);
		for (; tmp->next && tmp->next->n < node->n; tmp = tmp->next)
			;
		node->next = tmp->next;
		tmp->next = node;
	}
	return (node);
}
