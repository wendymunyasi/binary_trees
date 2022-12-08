#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * If tree is NULL, return 0.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	if (tree->left != NULL && tree->right != NULL)
	{
		if (tree->left->n < tree->n && tree->right->n > tree->n)
			return (binary_tree_is_bst(tree->left) &&
				binary_tree_is_bst(tree->right));
		else
			return (0);
	}
	if (tree->left != NULL)
	{
		if (tree->left->n < tree->n)
			return (binary_tree_is_bst(tree->left));
		else
			return (0);
	}
	if (tree->right != NULL)
	{
		if (tree->right->n > tree->n)
			return (binary_tree_is_bst(tree->right));
		else
			return (0);
	}
	return (0);
}
