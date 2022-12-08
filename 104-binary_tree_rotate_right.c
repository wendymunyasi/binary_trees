#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* If the tree is empty, return NULL. */
	if (!tree)
		return (NULL);

	/* Set the new root to the left child of the tree. */
	new_root = tree->left;

	/* If the new root exists, */
	if (new_root)
	{
		/* set the left child of the tree to the right child of the new root */
		tree->left = new_root->right;

		/* If the right child of the new root exists, */
		if (new_root->right)
			/* set the parent of the right child to the tree. */
			new_root->right->parent = tree;

		/* Set the right child of the new root to the tree. */
		new_root->right = tree;
		/* Set the parent of the new root to the parent of the tree. */
		new_root->parent = tree->parent;
		/* Set the parent of the tree to the new root. */
		tree->parent = new_root;
	}
	/* Return the new root */
	return (new_root);
}
