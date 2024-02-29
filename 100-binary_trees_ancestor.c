#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL if no common
 *         ancestor was found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor = NULL;
	const binary_tree_t *current;

	if (!first || !second)
		return (NULL);

	current = first;
	while (current)
	{
		const binary_tree_t *tmp = second;

		while (tmp)
		{
			if (current == tmp)
				return ((binary_tree_t *)current);
			tmp = tmp->parent;
		}
		current = current->parent;
	}

	return ((binary_tree_t *)ancestor);
}
