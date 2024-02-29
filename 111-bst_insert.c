#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: The value to store in the node to be inserted
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    if (!tree)
        return NULL;

    if (!(*tree))
    {
        *tree = binary_tree_node(NULL, value);
        if (!(*tree))
            return NULL;
        return *tree;
    }

    if (value < (*tree)->n)
    {
        if (!((*tree)->left))
        {
            (*tree)->left = binary_tree_node(*tree, value);
            if (!((*tree)->left))
                return NULL;
            return (*tree)->left;
        }
        return bst_insert(&((*tree)->left), value);
    }
    else if (value > (*tree)->n)
    {
        if (!((*tree)->right))
        {
            (*tree)->right = binary_tree_node(*tree, value);
            if (!((*tree)->right))
                return NULL;
            return (*tree)->right;
        }
        return bst_insert(&((*tree)->right), value);
    }

    return NULL; // If value is already present in the tree
}

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: A pointer to the first element of the array to be converted
 * @size: The number of elements in the array
 * Return: A pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
    bst_t *root = NULL;
    size_t i;

    for (i = 0; i < size; i++)
    {
        if (!bst_insert(&root, array[i]))
        {
            binary_tree_delete(root); // Clean up if insertion fails
            return NULL;
        }
    }

    return root;
}

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (tree == NULL)
        return;

    binary_tree_delete(tree->left);
    binary_tree_delete(tree->right);
    free(tree);
}
