#include "binary_trees.h"

/**
 * binary_tree_size - function that checks if a binary tree is perfect
 *
 * @tree: is a pointer to the root node of the tree to check
 * Return: is NULL, your function must return new node
 */

size_t binary_tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
/**
 * bit_amount - computes the amount of bits in a integer
 * @n: integer
 * Return: amount of bits
 */
unsigned int bit_amount(int n)
{
	unsigned int count = 0;

	while (n)
	{
		count++;
		n >>= 1;
	}
	return (count);
}

/**
 * get_path - helps deciding direction to traverse
 * @n: number of nodes
 * @n_bits: number of bits of n
 * Return: array of bits
 */
unsigned int *get_path(int n, unsigned int n_bits)
{
	unsigned int
		input = n,
		*bits = malloc(sizeof(unsigned int) * n_bits),
		bit = 0;

	for (bit = 0; bit < n_bits; ++bit)
		bits[bit] = (input >> bit) & 1;
	return (bits);
}

/**
 * sort - sorts the tree respecting Max Binary Heap
 * @node: node to start sorting
 */
void sort(heap_t **node)
{
	int tmp;

	if (!((*node)->parent) || (*node)->n <= (*node)->parent->n)
		return;

	tmp = (*node)->n;
	(*node)->n = (*node)->parent->n;
	(*node)->parent->n = tmp;

	*node = (*node)->parent;
	sort(node);
}

/**
 * heap_insert - function that inserts a value into a Max Binary Heap
 *
 * @root: is a double pointer to the root node of the Heap
 * @value: is the value to store in the node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *node, *tmp = *root;
	unsigned int *path, bit_length, i, size;

	if (!(*root))
	{
		node = binary_tree_node(NULL, value);
		if (!node)
			return (NULL);
		*root = node;
		return (node);
	}
	size = binary_tree_size(*root) + 1;

	switch (size)
	{
		case 2:
			node = binary_tree_node(tmp, value);
			(*root)->left = node;
			sort(&node);
			return (node);
		case 3:
			node = binary_tree_node(tmp, value);
			(*root)->right = node;
			sort(&node);
			return (node);
	}

	bit_length = bit_amount(size);
	path = get_path(size, bit_length);
	for (i = bit_length - 2; i; i--)
		tmp = path[i] ? tmp->right : tmp->left;

	node = binary_tree_node(tmp, value);
	if (!path[i])
		tmp->left = node;
	else
		tmp->right = node;
	sort(&node);
	free(path);
	return (node);
}
