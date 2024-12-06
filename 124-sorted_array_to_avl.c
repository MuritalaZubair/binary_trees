#include "binary_trees.h"

/**
 * sorted_array_to_avl_revursive - Recursive function to convert sorted array
 * into an AVL tree
 *
 * @array: pointer to the sorted array
 * @first_index: starting index of the current subarray
 * @final_index: ending index of the current subarray
 * Return: pointer to the root node of the AVL tree
 */
avl_t *sorted_array_to_avl_revursive(int *array, int first_index, int final_index)
{
    avl_t *root;
    int half;

    if (final_index < first_index)
        return (NULL);

    half = (final_index + first_index) / 2;
    
    /* Create the root node with the middle element */
    root = binary_tree_node(NULL, array[half]);
    if (!root)
        return (NULL);
    
    /* Recursively build the left and right subtrees */
    root->left = sorted_array_to_avl_revursive(array, first_index, half - 1);
    root->right = sorted_array_to_avl_revursive(array, half + 1, final_index);
    
    /* Set parent pointers for left and right children */
    if (root->left)
        root->left->parent = root;
    if (root->right)
        root->right->parent = root;

    return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: pointer to the first element of the sorted array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size < 1)
        return (NULL);

    return (sorted_array_to_avl_revursive(array, 0, size - 1));
}
