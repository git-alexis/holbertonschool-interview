#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_tree_height(heap_t *tree)
{
    size_t size_left = 0, size_right = 0;

    if (tree == NULL)
    {
        return (0);
    }
    else
    {
        size_left = binary_tree_height(tree->left) + 1;
        size_right = binary_tree_height(tree->right) + 1;
    }

    if (size_left >= size_right)
    {
        return (size_left);
    }
    else
    {
        return (size_right);
    }
}

/**
 * binary_tree_size - Measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of tree or 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
    {
        return (0);
    }

    return (1 + binary_tree_size(tree->left) +
        binary_tree_size(tree->right));
}

/**
 * find_node_for_top - finds the node that goes to the top
 *
 * @root: The root node
 *
 * Return: Newly inserted node
 */
heap_t *find_node_for_top(heap_t *root)
{
    if (!root)
    {
        return (NULL);
    }

    if (!root->left && !root->right)
    {
        return (root);
    }

    if (binary_tree_height(root->left) > binary_tree_height(root->right))
    {
        return (find_node_for_top(root->left));
    }

    if (binary_tree_size(root->left) > binary_tree_size(root->right))
    {
        return (find_node_for_top(root->right));
    }

    return (find_node_for_top(root->right));
}

/**
 * node_climb - moves a node up the tree
 *
 * @root: pointer to binary heap
 */
void node_climb(heap_t *root)
{
    heap_t *largest = NULL;
    int temp_value;

    if (!root)
    {
        return;
    }

    if (root->right)
    {
        if (root->right->n > root->left->n)
        {
            largest = root->right;
        }
        else
        {
            largest = root->left;
        }
    }
    else if (root->left)
    {
        largest = root->left;
    }

    if (largest && largest->n > root->n)
    {
        temp_value = largest->n;
        largest->n = root->n;
        root->n = temp_value;
        node_climb(largest);
    }
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 *
 * @root: Double pointer to root node
 *
 * Return: Value stored in the root node
 */
int heap_extract(heap_t **root)
{
    heap_t *last_node = NULL;
    int root_value;

    if (!root || !*root)
    {
        return (0);
    }

    root_value = (*root)->n;
    last_node = find_node_for_top(*root);

    if ((*root) == last_node)
    {
        free(*root);
        *root = NULL;
        return (root_value);
    }

    if (last_node->parent->right)
    {
        last_node->parent->right = NULL;
    }
    else
    {
        last_node->parent->left = NULL;
    }

    (*root)->n = last_node->n;

    node_climb(*root);

    free(last_node);

    return (root_value);
}
