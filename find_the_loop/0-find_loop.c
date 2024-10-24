#include "lists.h"

/**
 * find_listint_loop - checks if there is a loop or not.
 * @head: Address of the head.
 * Return: address where the loop starts, NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *l, *l2;

	if (!head)
		return (NULL);
	l = l2 = head;
	while (l && l2 && l2->next)
	{
		l = l->next, l2 = l2->next->next;
		if (l == l2)
			break;
	}
	if (l != l2)
		return (NULL);
	for (; ; head = head->next)
	{
		for (; l->next != l2; l = l->next)
		{
			if (l->next == head)
				break;
		}
		if (l->next == head)
			break;
		l = l2;
	}
	return (l->next);
}
