#include "binary_trees.h"

/**
 * binary_tree_preorder -  function that goes through a binary tree,
 * using pre-order traversal.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node.
 *
 * If tree or func is NULL, do nothing.
 *
 * Return: no return.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if ((tree != NULL) && (func != NULL))
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
