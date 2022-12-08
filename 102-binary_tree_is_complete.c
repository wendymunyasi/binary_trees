#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to check.
 *
 * If tree is NULL, your function must return 0.
 *
 * Return: 1 if complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (tree->left && tree->right)
		return (binary_tree_is_complete(tree->left) &&
			binary_tree_is_complete(tree->right));

	if (tree->left && !tree->right)
		return (0);

	if (!tree->left && tree->right)
		return (0);

	return (1);
}

/* CODE DOESN'T PASS ALL CHECKS */
