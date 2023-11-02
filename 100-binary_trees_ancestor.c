#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @frt: a pointer to the frt node to find the ancestor
 * @sec: a pointer to the sec node to find the ancestor
 *
 * Return: pointer to the ancestor node
 *         NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *frt,
				     const binary_tree_t *sec)
{
	size_t depth_frt, depth_sec;

	if (!frt || !sec)
		return (NULL);

	depth_frt = binary_tree_depth(frt);
	depth_sec = binary_tree_depth(sec);

	while (depth_frt > depth_sec)
	{
		frt = frt->parent;
		depth_frt--;
	}
	while (depth_sec > depth_frt)
	{
		sec = sec->parent;
		depth_sec--;
	}
	while (frt && sec)
	{
		if (frt == sec)
			return ((binary_tree_t *)frt);
		frt = frt->parent;
		sec = sec->parent;
	}
	return ((binary_tree_t *)frt);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: node to calculate the depth of
 *
 * Return: depth of the node
 *         0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);
}
