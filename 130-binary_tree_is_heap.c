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

	/* If tree isn't empty check if the left child is less than the parent. */
	if (tree->left && tree->n < tree->left->n)
		/* If it is, return 0 */
		return (0);

	/* Check if the right child is less than the parent. If it is, return 0. */
	if (tree->right && tree->n < tree->right->n)
		return (0);

	/* Check if the left and right child are empty. If they are, return 1. */
	if (!tree->left && !tree->right)
		return (1);
	
	/* Check if the left and right child are not empty. */
	if (tree->left && tree->right)
		/* If not, recurssively check the result of the left and right child. */
		return (binary_tree_is_heap(tree->left) &&
			binary_tree_is_heap(tree->right));
	return (0);
}

/* CODE DOESN'T PASS ALL CHECKS */
