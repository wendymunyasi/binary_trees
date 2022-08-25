#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree.
 * @tree: pointer to the root node of the tree to measure the size.
 *
 * Return: size of a binary tree. If tree is NULL,
 * your function must return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);
	/*  Get the size of left subtree recursively */
	left = binary_tree_size(tree->left);

	/* Get the size of right subtree recursively */
	right = binary_tree_size(tree->right);

	/* Calculate size of the tree as following: */
	return (left + 1 + right);
}
