#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "stdio.h"
#include "stdlib.h"

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;


int heap_extract(heap_t **root);
size_t binary_tree_size(const binary_tree_t *tree);
void heapify(int *array, size_t size);
size_t binary_tree_height(heap_t *tree);
heap_t *push_to_top(heap_t *root);
void heapify_down(heap_t *root);


#endif /* BINARY_TREE_H */
