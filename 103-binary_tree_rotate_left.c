#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	temp = tree->left->right;
	new_root = tree->left;
	new_root->parent = tree->parent;
	new_root->right = tree;
	tree->parent = new_root;
	tree->left = temp;
	if (temp)
		temp->parent = tree;
	return (new_root);
}
