#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: pointer to the root node of the BST to search
 * @value: value to search in the tree
 * Return: pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	/* If the tree is empty, return NULL. */
	if (!tree)
		return (NULL);

	/* If the value is found, return the tree. */
	if (value == tree->n)
		return ((bst_t *)tree);

	/* If the value is less than the tree's value, search the left subtree. */
	if (value < tree->n)
		return (bst_search(tree->left, value));

	/* If the value is greater than the tree's value, search the right subtree. */
	return (bst_search(tree->right, value));
}
