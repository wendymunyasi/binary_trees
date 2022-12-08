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
	/* If the tree is empty, it's not a BST. */
	if (tree == NULL)
		return (0);
	/* If the tree has no children, it's a BST. */
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	/* If the tree has two children, */
	if (tree->left != NULL && tree->right != NULL)
	{
		/*
		* check that left child is less than the parent and the right
		* child is greater than the parent,
		*/
		if (tree->left->n < tree->n && tree->right->n > tree->n)
			/* If so, recursively check that left and right subtrees are also BSTs */
			return (binary_tree_is_bst(tree->left) &&
				binary_tree_is_bst(tree->right));
		else
			return (0);
	}
	/* If the tree has only a left child, */
	if (tree->left != NULL)
	{
		/* check that the left child is less than the parent. */
		if (tree->left->n < tree->n)
			/* If so, recursively check that the left subtree is a BST. */
			return (binary_tree_is_bst(tree->left));
		else
			return (0);
	}
	if (tree->right != NULL) /* If the tree has only a right child, */
	{
		/* check that the right child is greater than the parent. */
		if (tree->right->n > tree->n)
			/* If so, recursively check that the right subtree is a BST. */
			return (binary_tree_is_bst(tree->right));
		else
			return (0);
	}
	return (0);
}

/* CODE DOESN'T PASS ALL CHECKS */
