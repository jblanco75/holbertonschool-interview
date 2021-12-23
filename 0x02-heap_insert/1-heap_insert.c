#include "binary_trees.h"
/**
 * num_nodes - count nodes
 * @root: double pointer
 * Return: number of nodes
 */
int num_nodes(heap_t *root)
{
	int n;

	if (root == NULL)
		return (0);
	if (root)
		n = 1;
	n += num_nodes(root->left);
	n += num_nodes(root->right);

	return (n);
}

/**
 * complete_tree - function that checks if a tree is perfect
 * @tree: pointer to the root
 * Return: 1 if true or 0 if false
 */

int complete_tree(const heap_t *tree)
{
	int p1, p2;

	if (tree == NULL)
		return (0);
	p1 = num_nodes(tree->left);
	p2 = num_nodes(tree->right);
	if (p1 == p2)
		return (1);
	return (0);
}

/**
 * heaper - finds the parent to insert a new child
 * @root: double pointer to the root node of the heap
 *
 * Return: pointer to the parent node
 */
heap_t *heaper(heap_t *root)
{
	heap_t *p;
	int l, r, lf, rf;

	if (root == NULL)
		return (NULL);

	p = root;
	l = num_nodes(p->left);
	r = num_nodes(p->right);
	lf = complete_tree(p->left);
	rf = complete_tree(p->right);

	if (!l || !r)
		return (p);
	if (!lf || (lf && rf && l == r))
		return (heaper(p->left));
	else if (!rf || (lf && rf && l > r))
		return (heaper(p->right));
	return (p);
}

/**
 * heapyfier - sorts a child and a parent node
 * @new: inserted node
 *
 * Return: nothing
 */
void heapyfier(heap_t **new)
{
	heap_t *current;
	int aux;

	current = *new;
	while (current->parent)
	{
		if (current->parent->n < current->n)
		{
			aux = current->parent->n;
			current->parent->n = current->n;
			current->n = aux;
			*new = current->parent;
		}
		current = current->parent;
	}
}
/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 *
 * Return: a pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;
	heap_t *parent;

	parent = heaper(*root);
	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);
	if (parent == NULL)
		*root = new;
	else if (!(parent->left))
		parent->left = new;
	else
		parent->right = new;
	heapyfier(&new);
	return (new);
}
