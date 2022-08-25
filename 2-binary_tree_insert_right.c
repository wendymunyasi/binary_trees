#include "binary_trees.h"

/**
 * binary_tree_insert_right - function that inserts a node as the,
 * right-child of another node.
 *
 * @parent: pointer to the node to insert the right-child in.
 * @value: value to store in the new node.
 *
 * If parent already has a right-child, the new node must take its place,
 * and the old right-child must be set as the right-child of the new node.
 *
 * Return: pointer to the created node, or NULL on failure or if parent,
 * is NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	if (parent != NULL)
	{
		new_node = malloc(sizeof(binary_tree_t));
		if (new_node != NULL)
		{
			new_node->left = NULL;
			new_node->right = parent->right;
			new_node->parent = parent;
			new_node->n = value;
			if (parent->right != NULL)
				parent->right->parent = new_node;
			parent->right = new_node;
		}
	}
	return (new_node);
}
