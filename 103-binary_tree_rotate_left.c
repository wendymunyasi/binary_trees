#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* If the tree is empty, return NULL. */
	if (!tree)
		return (NULL);

	/*
	* If the tree is not empty, create a new_root variable and set it to
	* the right child of the tree.
	*/
	new_root = tree->right;

	/* If the new_root is empty, return the tree. */
	if (!new_root)
		return (tree);

	/* Set the right child of the tree to the left child of the new_root. */
	tree->right = new_root->left;

	/*
	* If the left child of the new_root is not empty, set the parent of the
	* left child of the new_root to the tree.
	*/
	if (new_root->left)
		new_root->left->parent = tree;

	/* Set the parent of the new_root to the parent of the tree. */
	new_root->parent = tree->parent;

	/* Set the left child of the new_root to the tree. */
	new_root->left = tree;

	/* Set the parent of the tree to the new_root. */
	tree->parent = new_root;

	/* Return the new_root. */
	return (new_root);
}
