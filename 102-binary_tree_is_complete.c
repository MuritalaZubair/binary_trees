#include "binary_trees.h"

/**
 * count_nodes - Counts the nodes in a binary tree
 * @root: Pointer to the root node of the tree
 * Return: Number of nodes
 */
int count_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @root: Pointer to the root node of the tree
 * @index: Index of the current node
 * @n: Total number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int is_complete(binary_tree_t *root, int index, int n)
{
	if (!root)
		return (1);

	if (index >= n)
		return (0);

	return (is_complete(root->left, 2 * index + 1, n) &&
		is_complete(root->right, 2 * index + 2, n));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count;

	if (!tree)
		return (0);

	node_count = count_nodes((binary_tree_t *)tree);
	return (is_complete((binary_tree_t *)tree, 0, node_count));
}
