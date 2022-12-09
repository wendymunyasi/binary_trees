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
		*root = new_node; /* If root is empty, set the root to the new node */
		return (new_node);
	}
	/* If the root is not empty, find the first available spot in the tree */
	tmp = *root;
	while (tmp) /* If tmp is not empty */
	{	/* Check if the left node is empty and the right node is not */
		if (tmp->left && !tmp->right)
		{	/* If it is set the right node to the new node */
			tmp->right = new_node; /*  set the parent of the new node to tmp */
			new_node->parent = tmp;
			break;
		}
		else if (!tmp->left) /* If left node is not empty and right node is */
		{
			tmp->left = new_node; /* set the left node to the new node */
			new_node->parent = tmp; /* set the parent of the new node to tmp */
			break;
		} /* If neither of those are true */
		/* check if left node value is less than right node value*/
		else if (tmp->left->n < tmp->right->n)
			tmp = tmp->left; /* If yes, set tmp to the left node */
		else
			tmp = tmp->right; /* If not, set tmp to the right node. */
	}
	/*  check if new node parent is empty and new node value is greater than parent value of new node. */
	while (new_node->parent && new_node->n > new_node->parent->n)
	{	/* If yes, set new node value to parent value of the new node */
		new_node->n = new_node->parent->n;
		new_node->parent->n = value; /* set parent of the new node value to the value */
		new_node = new_node->parent; /* set the new node to the parent of the new node */
	}
	return (new_node); /* return new node */
}

/* CODE DOESN'T PASS ALL CHECKS */
