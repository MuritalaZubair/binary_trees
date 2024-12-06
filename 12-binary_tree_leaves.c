#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the leaves
 * 
 * Return: The number of leaves in the binary tree. 
 * If tree is NULL, return 0. 
 * A leaf is a node that has no children (both left and right are NULL).
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t count_leaves = 0;

    if (!tree)
        return (0);

    if (!(tree->left) && !(tree->right))
        return (1);

    count_leaves += binary_tree_leaves(tree->left);
    count_leaves += binary_tree_leaves(tree->right);

    return (count_leaves);
}
