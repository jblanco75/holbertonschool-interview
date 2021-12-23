#include "binary_trees.h"
/**
 * heapyfier - locates node to correct position in max heap
 * @newNode: node to move to correct position
 * Return: newnode
 */
heap_t *heapyfier(heap_t *newNode)
{
	heap_t *temp;
	int val = 0;

	while (newNode && newNode->parent)
	{
		while (newNode->n > newNode->parent->n)
		{
			temp = newNode;
			val = newNode->n;
			newNode = newNode->parent;
			temp->n = newNode->n;
			newNode->n = val;
		}
	}
	return (newNode);
}
/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: a pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newNode = *root, *parentNode;

	if (*root == NULL)
	{
		newNode = binary_tree_node(*root, value);
		*root = newNode;
		return (*root);
	}

	while (newNode != NULL)
	{
		parentNode = newNode;

		if (newNode->n == value)
			return (heapyfier(newNode));

		if (newNode->n < value)
			newNode = newNode->left;
		else
			newNode = newNode->right;
	}

	if (value > parentNode->n)
	{
		parentNode->left = binary_tree_node(parentNode, value);
		return (parentNode->left);
	}
	else
	{
		parentNode->right = binary_tree_node(parentNode, value);
		return (parentNode->right);
	}
}
