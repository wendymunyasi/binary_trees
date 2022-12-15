#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	/* Return 0 if tree is NULL */
	if (tree == NULL)
	{
		return (0);
	}
	/* Return 1 if tree is a leaf node (has no children) */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	/* Check if the left and right subtrees are valid Max Binary Heaps */
	int is_left_heap = binary_tree_is_heap(tree->left);
	int is_right_heap = binary_tree_is_heap(tree->right);

	/* Return 0 if either subtree is not a valid Max Binary Heap */
	if (!is_left_heap || !is_right_heap)
	{
		return (0);
	}

	/* Check if the current node satisfies the Max Binary Heap property */
	int is_heap = 1;

	/* Check if the left child satisfies the Max Binary Heap property */
	if (tree->left != NULL && tree->n < tree->left->n)
	{
		is_heap = 0;
	}
	/* Check if the right child satisfies the Max Binary Heap property */
	if (tree->right != NULL && tree->n < tree->right->n)
	{
		is_heap = 0;
	}

	/**
	 * Return 1 if the current node satisfies the Max Binary Heap property,
	 * and 0 otherwise
	 */
	return (is_heap);
}


/* CODE DOESN'T PASS ALL CHECKS */
