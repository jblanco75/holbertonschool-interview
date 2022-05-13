#include "binary_trees.h"
/**
 * heapify - find max
 * @root: root of the heap
 * Return: void
 */
void heapify(binary_tree_t *root)
{
	int tmp = 0;
	binary_tree_t *new = NULL;

	while (1)
	{
		if (root->left == NULL)
			break;
		else if (root->right == NULL)
			new = root->left;
		else
		{
			if (root->left->n >= root->right->n)
				new = root->left;
			else
				new = root->right;
		}
		if (root->n >= new->n)
			break;
		tmp = root->n, root->n = new->n, new->n = tmp;
		root = new;
	}
}
/**
 * countNodes - Nodes count
 * @root: root of the heap
 * Return: number of nodes
 */
int countNodes(heap_t *root)
{
	int left = 0, right = 0;

	if (root == NULL)
		return (0);

	left = countNodes(root->left);
	right = countNodes(root->right);

	return ((left + right) + 1);
}
/**
 * getLast - get the last
 * @root: the root of the heap
 * Return: the last node
 */
binary_tree_t *getLast(heap_t *root)
{
	int nodes = 0, size = 0;
	binary_tree_t *last = NULL;

	size = countNodes(root);

	for (nodes = 1; nodes <= size; nodes <<= 1)
		;
	nodes >>= 2;

	for (last = root; nodes > 0; nodes >>= 1)
	{
		if (size & nodes)
			last = last->right;
		else
			last = last->left;
	}
	return (last);
}

/**
 * heap_extract - extract a node
 * @root: root node of the heap
 * Return: root node of a Max Binary Heap
 */
int heap_extract(heap_t **root)
{
	binary_tree_t *end = NULL, *head = NULL;
	int ex = 0;

	if (root == NULL || *root == NULL)
		return (0);

	head = *root;
	if (head->left == NULL && head->right == NULL)
	{
		ex = head->n, *root = NULL;
		return (free(head), ex);
	}
	head = *root, ex = head->n;
	end = getLast(*root);

	if (end->parent->left == end)
		end->parent->left = NULL;
	else
		end->parent->right = NULL;

	end->left = head->left;
	end->right = head->right;
	end->parent = head->parent;

	if (head->left)
		head->left->parent = end;
	if (head->right)
		head->right->parent = end;

	*root = end;
	free(head);

	heapify(*root);

	return (ex);
}
