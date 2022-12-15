#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>

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

/* Binary Search Tree */
typedef struct binary_tree_s bst_t;

/*AVL Tree */
typedef struct binary_tree_s avl_t;

/*Max Binary Heap */
typedef struct binary_tree_s heap_t;

/* binary_tree_print.c*/
void binary_tree_print(const binary_tree_t *);

/* 0-binary_tree_node.c */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/* 1-binary_tree_insert_left.c*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

/* 2-binary_tree_insert_right.c */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/* 3-binary_tree_delete.c */
void binary_tree_delete(binary_tree_t *tree);

/* 4-binary_tree_is_leaf.c */
int binary_tree_is_leaf(const binary_tree_t *node);

/* 5-binary_tree_is_root.c */
int binary_tree_is_root(const binary_tree_t *node);

/* 6-binary_tree_preorder.c */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/*7-binary_tree_inorder.c */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/* 8-binary_tree_postorder.c */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/* 9-binary_tree_height.c */
size_t binary_tree_height(const binary_tree_t *tree);

/* 10-binary_tree_depth.c */
size_t binary_tree_depth(const binary_tree_t *tree);
void node_height_2(const binary_tree_t *tree, size_t n, size_t *height);

/* 11-binary_tree_size.c */
size_t binary_tree_size(const binary_tree_t *tree);

/* 12-binary_tree_leaves.c */
size_t binary_tree_leaves(const binary_tree_t *tree);

/* 13-binary_tree_nodes.c */
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);

/* 14-binary_tree_balance.c */
int binary_tree_balance(const binary_tree_t *tree);
void node_height(const binary_tree_t *tree, int n, int *height);

/* 15-binary_tree_is_full.c */
int binary_tree_is_full(const binary_tree_t *tree);

/* 16-binary_tree_is_perfect.c */
int binary_tree_is_perfect(const binary_tree_t *tree);
void tree_stats(const binary_tree_t *tree, size_t n,
	size_t *leaves, size_t *height);

/* 17-binary_tree_sibling.c */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/* 18-binary_tree_uncle.c */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/* 100-binary_trees_ancestor.c */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);

/* 102-binary_tree_is_complete.c */
int binary_tree_is_complete(const binary_tree_t *tree);

/* 103-binary_tree_rotate_left.c */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/* 104-binary_tree_rotate_right.c */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/* 110-binary_tree_is_bst.c */
int binary_tree_is_bst(const binary_tree_t *tree);

/* 111-bst_insert.c */
bst_t *bst_insert(bst_t **tree, int value);

/* 112-array_to_bst.c */
bst_t *array_to_bst(int *array, size_t size);

/* 113-bst_search.c */
bst_t *bst_search(const bst_t *tree, int value);

/* 114-bst_remove.c */
bst_t *bst_remove(bst_t *root, int value);
bst_t *bst_min_node(bst_t *root);

/* 120-binary_tree_is_avl.c */
int binary_tree_is_avl(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

/* 130-binary_tree_is_heap.c */
int binary_tree_is_heap(const binary_tree_t *tree);

/* 131-heap_insert.c */
heap_t *heap_insert(heap_t **root, int value);

#endif /* _BINARY_TREES_H_ */
