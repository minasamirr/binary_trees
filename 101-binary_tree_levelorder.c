#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_t **queue = malloc(sizeof(binary_tree_t *)
			* binary_tree_height(tree) * 2);

	if (!queue)
		return;

	int front = 0, rear = 0;
	binary_tree_t *current = NULL;

	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		current = queue[front++];

		func(current->n);

		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
}

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
        if (tree)
        {
                int left = 0, right = 0;

                if (tree->right)
                        right = 1 + binary_tree_height(tree->right);
                if (tree->left)
                        left = 1 + binary_tree_height(tree->left);
                if (left > right)
                        return (left);
                else
                        return (right);
        }
        else
                return (0);
}
