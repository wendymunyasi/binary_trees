#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is full. 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left, right;

	/* if binary tree node is NULL then it is not a full binary tree */
	if (tree == NULL)
		return (0);

	/* if binary tree node does have empty left and right sub-trees */
	/* (if leaf node) */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* if both left and right are not NULL, and left & right subtrees are full */
	if ((tree->left) && (tree->right))
	{
		left = binary_tree_is_full(tree->left);
		right = binary_tree_is_full(tree->right);
		return (left && right);
	}

	/* We reach here when none of the above if conditions work */
	return (0);
}
