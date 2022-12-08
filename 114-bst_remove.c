#include "binary_trees.h"

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the desired
 * value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (!root)
		return (NULL);
	/* If the value is less than the root, */
	if (value < root->n)
		/* recursively call the function on the left side of the tree. */
		root->left = bst_remove(root->left, value);
	/* If the value is greater than the root, */
	else if (value > root->n)
		/* recursively call the function on the right side of the tree. */
		root->right = bst_remove(root->right, value);
	else /* If the value is equal to the root, we found the node to remove. */
	{
		if (!root->left) /* If the node to remove has no left child, */
		{
			/* then replace the node with its right child. */
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (!root->right) /* If the node to remove has no right child, */
		{
			tmp = root->left; /* then replace the node with its left child. */
			free(root);
			return (tmp);
		}
		/*
		* If the node has both a left and right child then find the minimum
		* value in the right subtree.
		*/
		tmp = bst_min_node(root->right);
		/* replace the value of the node to remove with the minimum value. */
		root->n = tmp->n;
		/* recursively call the func on right subtree to remove min value node. */
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root); /* return the root */
}

/**
 * bst_min_node - finds the minimum node in a binary search tree.
 * @root: pointer to the root node of the tree to traverse.
 *
 * Return: pointer to the minimum node
 */
bst_t *bst_min_node(bst_t *root)
{
	bst_t *tmp;

	/* Assign the address of the root node to the tmp pointer. */
	tmp = root;

	/* Loop until the left node of the tmp pointer is NULL. */
	while (tmp->left != NULL)
		tmp = tmp->left;
	/* Return the address of the tmp pointer. */
	return (tmp);
}

/* CODE DOESN'T PASS ALL CHECKS */
