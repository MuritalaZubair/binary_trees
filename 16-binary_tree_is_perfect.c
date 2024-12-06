#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: depth of the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t left_depth, right_depth;

    if (!tree)
        return (0);

    left_depth = binary_tree_depth(tree->left);
    right_depth = binary_tree_depth(tree->right);

    return ((left_depth > right_depth ? left_depth : right_depth) + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t left_depth, right_depth;

    if (!tree)
        return (0);

    left_depth = binary_tree_depth(tree->left);
    right_depth = binary_tree_depth(tree->right);

    if (left_depth != right_depth)
        return (0);

    if (!tree->left && !tree->right)
        return (1);

    if (tree->left && tree->right)
        return (binary_tree_is_perfect(tree->left) &&
                binary_tree_is_perfect(tree->right));

    return (0);
}
