#include "binary_trees.h"

/**
 * logarithm - Calculates the logarithm of a number
 * @x: Base
 * @y: Exponent
 *
 * Return: The logarithm of @y in base @x
 */
int logarithm(int x, int y)
{
	int result = 0;

	while (y > 1)
	{
		y /= x;
		result++;
	}
	return (result);
}

/**
 * _height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * @nodes: Pointer to the number of nodes
 *
 * Return: The height of the tree starting at @node
 */
static int _height(const binary_tree_t *tree, size_t *nodes)
{
	int height_l = 0;
	int height_r = 0;

	if (!tree)
		return (0);
	*nodes += 1;
	height_l = tree->left ? 1 + _height(tree->left, nodes) : 0;
	height_r = tree->right ? 1 + _height(tree->right, nodes) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * _binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Is a pointer to the root node of the tree to check
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int _binary_tree_is_avl(const binary_tree_t *tree, int min, int max)
{
	size_t nodes = 0;
	int path_l, path_r;
	size_t res = 0;
	size_t height = 0;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);

	/* The difference between heights of left and right subtrees cannot */
	/* be more than one */
	path_l = tree->left ? 1 + _height(tree->left, &nodes) : 0;
	path_r = tree->right ? 1 + _height(tree->right, &nodes) : 0;
	if (abs(path_l - path_r) > 1)
		return (0);

	/* log2(nodes) = height */
	nodes = 0;
	height = _height(tree, &nodes);
	res = logarithm(2, nodes); /* math not added in compiling */
	if (res != height)
		return (0);

	return (_binary_tree_is_avl(tree->left, min, tree->n - 1) &&
	    _binary_tree_is_avl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Is a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (_binary_tree_is_avl(tree, INT_MIN, INT_MAX));
}
