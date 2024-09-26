#include "lists.h"

/**
 * check_cycle - Checks for a loop in a linked list
 * @list: address of linked list
 * Return: 1 is there is a loop, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *f = list;

	for (; f && list && f->next; list = list->next)
	{
		f = f->next->next;
                if (list == f)
			return (1);
	}
	return (0);
}
