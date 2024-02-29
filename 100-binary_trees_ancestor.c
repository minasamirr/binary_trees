#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: A pointer to the first node
 * @second: A pointer to the second node
 *
 * Return: A pointer to the lowest common ancestor node, or NULL if none
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor;

	if (!first || !second)
		return (NULL);

	ancestor = first;
	while (ancestor)
	{
		if (binary_tree_is_ancestor(ancestor, second))
			return ((binary_tree_t *)ancestor);
		ancestor = ancestor->parent;
	}

	return (NULL);
}

/**
 * binary_tree_is_ancestor - Checks if a node is an ancestor of another
 * @node: A pointer to the potential ancestor node
 * @target: A pointer to the target node
 *
 * Return: 1 if node is an ancestor of target, 0 otherwise
 */
int binary_tree_is_ancestor(const binary_tree_t *node,
		const binary_tree_t *target)
{
	while (target)
	{
		if (node == target)
			return (1);
		target = target->parent;
	}

	return (0);
}
