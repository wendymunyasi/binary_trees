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

	/*  If the tree has two children, */
	if (tree->left && tree->right)
	{
		/*
		* Check if the left child is less than the parent and the right
		* child is less than the parent.
		*/
		if (tree->left->n > tree->n)
			return (0);
		if (tree->right->n > tree->n)
			return (0);
		/* If yes, recursively check the left and right subtrees. */
		return (binary_tree_is_heap(tree->left) &&
			binary_tree_is_heap(tree->right));
	}
	/* If the tree has only a left child */
	if (tree->left)
	{
		/* Check if the left child is less than the parent. */
		if (tree->left->n > tree->n)
			return (0);
		/* If so, recursively check the left subtree. */
		return (binary_tree_is_heap(tree->left));
	}
	/* If the tree has only a right child */
	if (tree->right)
	{
		if (tree->right->n > tree->n)
			return (0);
		/* If so, recursively check the right subtree. */
		return (binary_tree_is_heap(tree->right));
	}
	/* If none of the above conditions are met, return 0. */
	return (0);
}
