#include "binary_trees.h"
#define MAX_NODES 1000


/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	/* return (0 if tree is NULL */
	if (tree == NULL)
	{
		return (0);
	}

	/* return (1 if tree is a leaf node (has no children) */
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}

	/* Recursively calculate the height of the left and right subtrees */
	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	/**
	 * return (the maximum of the left and right subtree heights, plus 1 to
	 * account for the current node
	 */
	return (((left_height > right_height) ? left_height : right_height) + 1);
	/* return (fmax(left_height, right_height) + 1); */
}

/**
 * find_min - returns a pointer to the node with the min value in bin tree.
 * @tree: pointer to the root node of the tree to measure the min value.
 *
 * Return: pointer to the node with the minimum value.
 */
const binary_tree_t *find_min(const binary_tree_t *tree)
{
	/* return (NULL if tree is NULL */
	if (tree == NULL)
	{
		return (NULL);
	}

	/* If tree has no left child, it is the minimum value in the subtree */
	if (tree->left == NULL)
	{
		return (tree);
	}

	/* Recursively search the left subtree for the minimum value */
	return (find_min(tree->left));
}

/**
 * find_max - returns a pointer to the node with the max value in bin tree.
 * @tree: pointer to the root node of the tree to measure the max value.
 *
 * Return: pointer to the node with the maximum value.
 */
const binary_tree_t *find_max(const binary_tree_t *tree)
{
	/* return (NULL if tree is NULL */
	if (tree == NULL)
	{
		return (NULL);
	}

	/* If tree has no right child, it is the maximum value in the subtree */
	if (tree->right == NULL)
	{
		return (tree);
	}

	/* Recursively search the right subtree for the maximum value */
	return (find_max(tree->right));
}

/**
 * has_duplicates - checks if binary tree has dublicate values.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if a binary tree contains duplicate values, and 0 otherwise.
 */
int has_duplicates(const binary_tree_t *tree)
{
	/* return (0 if tree is NULL */
	if (tree == NULL)
	{
		return (0);
	}

	/* Initialize an array to store the values in the tree */
	int values[MAX_NODES];

	/**
	 * Recursively traverse the tree and add the values of each node to the
	 * array
	 */
	int num_values = has_duplicates_2(tree, values, 0);

	/* Loop through the array and check for duplicate values */
	for (int i = 0; i < num_values; i++)
	{
		/* return (1 if a duplicate value is found */
		if (count_occurrences(values, num_values, values[i]) > 1)
		{
			return (1);
		}
	}

	/* If no duplicate values were found, return (0 */
	return (0);
}

/**
 * has_duplicates_2 - Helper function for has_duplicates().
 * @tree: pointer to the root node of the tree to check.
 * @values:  values to check.
 * @n: value to compare to.
 *
 * Return: 1 if a binary tree contains duplicate values, and 0 otherwise.
 */
int has_duplicates_2(const binary_tree_t *tree, int *values, int n)
{
	/* return (n if tree is NULL */
	if (tree == NULL)
	{
		return (n);
	}

	/* Add the value of the current node to the array */
	values[n] = tree->n;
	n++;

	/* Recursively traverse the left and right subtrees */
	n = has_duplicates_2(tree->left, values, n);
	n = has_duplicates_2(tree->right, values, n);

	/* return (the updated number of values in the array */
	return (n);
}

/**
 * count_occurrences - return (no of occurrences of a given value in an array.
 * @array: pointer to array to check.
 * @n: the number of elements in the array.
 * @value: the value to search for in the array.
 *
 * Return: number of occurrences of a given value in an array.
 */
int count_occurrences(const int *array, int n, int value)
{
	int count = 0;

	/* Loop through the array and count the number of occurrences of value */
	for (int i = 0; i < n; i++)
	{
		if (array[i] == value)
		{
			count++;
		}
	}
	return (count);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0); /* return 0 if tree is NULL */
	}
	if (tree->left == NULL && tree->right == NULL)
	{
		return (1); /* return 1 if tree is a leaf node (has no children) */
	}
	int left_height = binary_tree_height(tree->left); /* left subtree height */
	int right_height = binary_tree_height(tree->right); /* right subtree height */
	int height_diff = abs(left_height - right_height); /* find the difference */

	if (height_diff > 1)
	{
		return (0); /* return 0 if the height difference is greater than 1 */
	}
	/* check if there is value in right subtree lower than root node value */
	if (tree->right != NULL && tree->n > find_min(tree->right)->n)
	{
		return (0);
	}
	/* check if there is value in left subtree greater than root node value */
	if (tree->left != NULL && tree->n < find_max(tree->left)->n)
	{
		return (0);
	}
	if (has_duplicates(tree->left))
	{
		return (0); /* return 0 if there are duplicate values in the left subtree */
	}
	if (has_duplicates(tree->right))
	{
		return (0); /* return 0 if there are duplicate values in the right subtree */
	}
	/* Recursively check the left and right subtrees */
	if (!binary_tree_is_avl(tree->left) || !binary_tree_is_avl(tree->right))
	{
		return (0);
	}
	return (1); /* If all checks pass then it is a valid AVL tree */
}

/* CODE DOESN'T PASS ALL CHECKS */
