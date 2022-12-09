#include "binary_trees.h"

/**
 * heap_insert - inserts a value in Max Binary Heap.
 * @root: double pointer to the root node of the Heap to insert the value.
 * @value: value to store in the node to be inserted.
 *
 * Return: pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *tmp = NULL;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	tmp = *root;
	while (tmp)
	{
		if (tmp->left && !tmp->right)
		{
			tmp->right = new_node;
			new_node->parent = tmp;
			break;
		}
		else if (!tmp->left)
		{
			tmp->left = new_node;
			new_node->parent = tmp;
			break;
		}
		else if (tmp->left->n < tmp->right->n)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		new_node->n = new_node->parent->n;
		new_node->parent->n = value;
		new_node = new_node->parent;
	}
	return (new_node);
}
