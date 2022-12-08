#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	/* If the tree is empty, return 0. */
	if (!tree)
		return (0);

	/* If the tree has no children, return 1. */
	if (!tree->left && !tree->right)
		return (1);

	/* If the tree has children, */
	if (tree->left && tree->right)
	{
		/* check if the parent is greater than both children. */
		if (tree->n >= tree->left->n && tree->n >= tree->right->n)

			/* If so, recursively check the left and right subtrees. */
			return (binary_tree_is_heap(tree->left) &&
				binary_tree_is_heap(tree->right));
	}
	return (0);
}

/* CODE DOESN'T PASS ALL CHECKS */
