#include "lists.h"

/**
 * is_palindrome - Checks if a linked list is palindrome
 * @head: address of linked list
 * Return: 1 if it is palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	if (!head || !(*head))
		return (1);
	if (!(*head)->next)
		return (1);
	return (r(head, *head));
}

/**
 * r -  Checks if a linekd list is palindrome
 * @head: address of linked list
 * @node: address of a node
 * Return: 1 if palindrome, 0 otherwise
 */
int r(listint_t **head, listint_t *node)
{
	if (node->next && (!r(head, node->next) || ((*head)->n != node->n)))
		return (0);
	(*head) = (*head)->next;
	return (1);
}
