#include "binary_trees.h"

/**
 * binary_tree_insert_right - new node replaces right-child if
 * parent present, old right-child is set to new right-child
 *
 * @parent: Pointer to the node to insert the right-child in.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to new node, else NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	binary_tree_t *new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = parent->right;
	if (parent->right != NULL)
		parent->right->parent = new_node;

	parent->right = new_node;
	return (new_node);
}

