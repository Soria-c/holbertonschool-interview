#include "binary_trees.h"

/**
 * heapify_down - Restore the min heap
 * @root: Is a pointer to the heap from which to extract the value
 *
 * Return: Nothing
 */
void heapify_down(binary_tree_t **root)
{
	binary_tree_t *node = *root, *child = NULL;
	int tmp = 0;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = node->left->n > node->right->n ?
				node->left : node->right;
		if (node->n > child->n)
			break;
		tmp = node->n;
		node->n = child->n;
		child->n = tmp;
		node = child;
	}
}

/**
 * height - get height
 * @root:   Pointer to root
 *
 * Return:  size
 */
int height(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + height(root->left) + height(root->right));
}

/**
 * itoa - Convert a number to a specific base
 * @val: Number to convert
 * @base: Base to convert
 *
 * Return: String with number converted
 */
char *itoa(int val, int base)
{
	static char buf[32] = {0};
	int i = 30;

	for (; val && i ; --i, val /= base)
		buf[i] = "0123456789abcdef"[val % base];
	return (&buf[i + 1]);
}


/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Is a double pointer to the root node of the heap
 *
 * Return: Value of the extracted node, otherwise 0 on failure
 */
int heap_extract(heap_t **root)
{
	heap_t *current = NULL;
	int len = 0, i = 0, value = 0;
	char *str = NULL;

	if (!root || !*root)
		return (0);
	current = *root;
	value = (*root)->n;
	len = height(current);
	if (len == 1)
	{
		free(*root);
		*root = NULL;
		return (value);
	}
	str = itoa(len, 2);
	for (i = 1; str[i]; i++)
		current = str[i] == '1' ? current->right : current->left;
	(*root)->n = current->n;
	if (current->parent->left == current)
		current->parent->left = NULL;
	else
		current->parent->right = NULL;
	free(current);
	heapify_down(root);
	return (value);
}
