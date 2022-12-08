#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: value to store in the node to be inserted.
 *
 * If the address stored in tree is NULL, the created node must become
 * the root node.
 * If the value is already present in the tree, it must be ignored.
 *
 * Return: pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;
	bst_t *current = NULL;

	if (!tree) /* check to make sure that the tree exists. */
		return (NULL);
	new_node = binary_tree_node(NULL, value); /* create new node */
	if (!new_node)
		return (NULL);
	if (!*tree) /* check to see if the tree is empty. */
	{
		*tree = new_node; /* If it is, the new node is assigned to the tree */
		return (new_node); /* return the new node */
	}
	current = *tree; /* set the current node to the root of the tree */
	while (current)
	{
		if (value < current->n) /* If new node val is less than current node val, */
		{
			if (!current->left)
			{
				current->left = new_node;
				new_node->parent = current;
				break;
			}
			current = current->left; /* new node is inserted to left of current node. */
		}
		else if (value > current->n)
		{
			if (!current->right)
			{
				current->right = new_node;
				new_node->parent = current;
				break;
			}
			current = current->right; /* new node is inserted to right of current. */
		}
		else
		{
			free(new_node); /* If new node value is equal to the current node value. */
			return (NULL);
		}
	}
	return (new_node); /* return new node */
}
