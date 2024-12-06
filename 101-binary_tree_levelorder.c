#include "binary_trees.h"

/**
 * binary_tree_height_aux - Calculates the height of a binary tree
 * @tree: Pointer to the root of the tree
 * Return: Height of the tree
 */
size_t binary_tree_height_aux(const binary_tree_t *tree)
{
	size_t hleft = 0, hright = 0;

	if (!tree)
		return (0);
	if (tree->left)
		hleft = 1 + binary_tree_height_aux(tree->left);
	if (tree->right)
		hright = 1 + binary_tree_height_aux(tree->right);

	return (hleft > hright ? hleft : hright);
}

/**
 * print_level_order - Traverses the tree at a specific level
 * @tree: Pointer to the root of the tree
 * @level: Level of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void print_level_order(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level_order(tree->left, level - 1, func);
		print_level_order(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height = 0, level = 1;

	if (!tree || !func)
		return;

	height = binary_tree_height_aux(tree) + 1;

	while (level <= height)
	{
		print_level_order(tree, level, func);
		level++;
	}
}
