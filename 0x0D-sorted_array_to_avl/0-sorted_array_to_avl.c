#include "binary_trees.h"

/**
 * create_node - create a node
 *
 * @parent: Pointer to the parent node
 * @n: Value of the node
 *
 * Return: Pointer to the new node
 */
avl_t *create_node(avl_t *parent, int n)
{
	avl_t *new_node = NULL;

	new_node = malloc(sizeof(avl_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * insert_node - create a node
 *
 * @parent: Pointer to the parent node
 * @start: Start idx of the "new" array
 * @end: End idx of the "new" array
 * @array: Array of the integers
 *
 * Return: Void
 */
void insert_node(avl_t *parent, int start, int end, int *array)
{
	avl_t *new_node = NULL;
	int middle = ((end - start) / 2) + start;

	if (end - start <= 1)
		return;

	new_node = create_node(parent, array[middle]);

	if (new_node->n < parent->n)
		parent->left = new_node;
	else if (new_node->n > parent->n)
		parent->right = new_node;

	insert_node(new_node, start, middle, array);
	insert_node(new_node, middle, end, array);
}

/**
 * sorted_array_to_avl - Create an AVL binary tree from a sorted array
 *
 * @array: Pointer to the parent node
 * @size: Value of the node
 *
 * Return: Pointer to the AVL binary tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int middle = (size - 1) / 2;
	avl_t *tree = NULL;

	if (!array)
		return (NULL);

	tree = create_node(NULL, array[middle]);
	insert_node(tree, -1, middle, array);
	insert_node(tree, middle, size, array);

	return (tree);
}
