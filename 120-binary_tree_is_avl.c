
#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	/* If the tree is empty, return 0. */
	if (!tree)
		return (0);
	/*
	* Calculate the height of left and right subtrees and take the maximum
	* of two heights.
	* Add 1 to the maximum height and return.
	*/
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree to measure the balance factor.
 *
 * Return: balance factor of the tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	/* If the tree is empty, return 0. */
	if (!tree)
		return (0);

	/* Calculate the height of the left and right subtrees. */
	if (tree->left)
		left_height = 1 + binary_tree_height(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height(tree->right);

	/* Return the difference between the left and right subtrees. */
	return (left_height - right_height);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance = 0;

	/* If the tree is empty, return 0. */
	if (!tree)
		return (0);

	/* Check if the tree is balanced. */
	balance = binary_tree_balance(tree);
	if (balance > 1 || balance < -1)
		return (0);

	/* If the tree is balanced, check if the left subtree is balanced. */
	if (tree->left)
		if (!binary_tree_is_avl(tree->left))
			return (0);

	/* If the left subtree is balanced, check if the right subtree is balanced. */
	if (tree->right)
		if (!binary_tree_is_avl(tree->right))
			return (0);

	/* If the right subtree is balanced, return 1. */
	return (1);
}

/* CODE DOESN'T PASS ALL CHECKS */
