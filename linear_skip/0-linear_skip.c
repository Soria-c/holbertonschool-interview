#include "search.h"

/**
 * skiplist_last_node - Get the last node of a skiplist
 *
 * @node: Pointer to any node of a skiplist..
 *
 * Return: Pointer on the last node of the skiplist
 * or NULL if node doesn't exist;
 */
skiplist_t *skiplist_last_node(skiplist_t *node)
{
	skiplist_t *last_node = node;

	if (!last_node)
		return (NULL);

	while (last_node->next)
		last_node = last_node->express ? last_node->express : last_node->next;

	return (last_node);
}

/**
 * linear_skip - Linear search in a skip list
 *
 * @list: Pointer to the head of the skip list to search in.
 *
 * @value: Value to search on the skip list
 *
 * Return: Pointer on the first node where value is located or NULL if fails
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *curr = NULL, *prev = NULL;
	char *between_msg = "Value found between indexes [%ld] and [%ld]\n";
	char *check_msg = "Value checked at index [%ld] = [%d]\n";
	int express_flag = 1;

	if (!list || (value < list->n))
		return (NULL);

	curr = list, prev = list;

	while (curr)
	{
		if (curr->n == value)
			return (curr);

		if ((value < curr->n) || ((value > curr->n) && !curr->next))
			break;

		prev = curr;
		curr = (curr->express && express_flag) ? curr->express : curr->next;
		printf(check_msg, curr->index, curr->n);

		if ((value > curr->n) && !curr->express && express_flag)
		{
			printf(between_msg, curr->index, skiplist_last_node(curr)->index);
			prev = curr;
			printf(check_msg, curr->index, curr->n);
			express_flag = 0;
		}

		if ((value < curr->n) && express_flag)
		{
			printf(between_msg, prev->index, curr->index);
			curr = prev;
			printf(check_msg, curr->index, curr->n);
			express_flag = 0;
		}
	}

	return (NULL);
}
