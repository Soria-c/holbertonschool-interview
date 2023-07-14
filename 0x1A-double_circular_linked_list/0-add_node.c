#include "list.h"

/**
 * new_node - Create a new node
 * @list: The list to modify
 * @str:  The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *new_node(List *list, char *str)
{
	list = malloc(sizeof(List));
	if (!list)
		return (NULL);
	list->str = strdup(str);
	if (!(list->str))
		return (NULL);
	list->next = list;
	list->prev = list;
	return (list);
}

/**
 * insert_node - Insert the new node into a double linked circular list
 * @list: The list to modify
 * @str:  The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *insert_node(List **list, char *str)
{
	List *tmp = *list, *node = NULL;

	if (!list ||  !str)
		return (NULL);

	node = new_node(tmp, str);
	if (node == NULL)
		return (NULL);
	if (!(*list))
		return ((*list) = node);

	node->next = (*list);
	tmp->prev->next = node;
	node->prev = tmp->prev;
	tmp->prev = node;
	return (node);
}

/**
 * add_node_end - Add a new node to the end
 * of a double circular linked list
 * @list: The list to modify
 * @str:  The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	return (insert_node(&(*list), str));
}

/**
 * add_node_begin - Add a new node to the beginning
 * of a double circular linked list
 * @list: The list to modify
 * @str:  The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	(*list) = insert_node(&(*list), str);
	return ((*list));
}
