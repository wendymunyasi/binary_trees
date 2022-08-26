#include "binary_trees.h"

/**
 * node_height_2 - function that computes the height of a binary tree's node.
 * @tree: pointer to the root node of the tree to measure the height.
 * @n: accumulated height.
 * @height: pointer to the maximum height in the node's tree.
 *
 * Return: no return.
 */
void node_height_2(const binary_tree_t *tree, size_t n, size_t *height)
{
	if (tree != NULL)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
		{
			if (n > *height)
			{
				*height = n;
			}
		}
		else
		{
			node_height_2(tree->left, n + 1, height);
			node_height_2(tree->right, n + 1, height);
		}
	}
}

/**
 * binary_tree_height - function that measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: Height of tree. If tree is NULL, your function must return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	node_height_2(tree, 0, &height);
	return (height);
}
