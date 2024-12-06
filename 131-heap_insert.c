#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 *
 * @root: Double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 * Return: Pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    size_t size;
    heap_t *new, *parent;

    if (!root)
        return (NULL);

    if (*root == NULL)
    {
        new = binary_tree_node(NULL, value);
        *root = new;
        return (new);
    }

    size = bts(*root);
    parent = heap_nf(*root, (size - 1) / 2);
    new = binary_tree_node(parent, value);
    if (size % 2 == 1)
        parent->left = new;
    else
        parent->right = new;

    if (new == NULL)
        return (NULL);

    heapify_up(new);

    return (new);
}

/**
 * bts - Measures the size of the binary tree.
 *
 * @tree: Pointer to the root of the tree.
 * Return: The size of the tree.
 */
size_t bts(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + bts(tree->left) + bts(tree->right));
}

/**
 * heap_nf - Finds the node at a specific index.
 *
 * @root: Pointer to the root node of the heap.
 * @number: The index of the node to find.
 * Return: Pointer to the node at the given index.
 */
heap_t *heap_nf(heap_t *root, size_t number)
{
    size_t parentn, dir;

    if (number == 0)
        return (root);

    parentn = (number - 1) / 2;
    dir = (number - 1) % 2;

    if (dir == 0)
        return (heap_nf(root, parentn)->left);
    return (heap_nf(root, parentn)->right);
}

/**
 * heapify_up - Rebalances the heap by moving the new node up if needed.
 *
 * @new: Pointer to the new node.
 */
void heapify_up(heap_t *new)
{
    heap_t *parent;
    int tmp;

    while (new->parent && new->n > new->parent->n)
    {
        parent = new->parent;
        tmp = new->n;
        new->n = parent->n;
        parent->n = tmp;
        new = parent;
    }
}
