#include "Tree.h"
#include <algorithm>

/*The implementation of the 'Node' class*/

template<class Type>
Node<Type>::Node(Type key) :key(key), parent(NULL), left(NULL), right(NULL) {}

template<class Type>
Node<Type>::~Node()
{
	if (left)
		delete left;
	if (right)
		delete right;
}

template<class Type>
ostream &operator<<(ostream &output, const Node<Type> &node)
{
	output << node.key;
	return output;
}

/*The implementation of the 'Tree' class*/

template<class Type>
Tree<Type>::Tree() :root(NULL) {}

template<class Type>
Tree<Type>::~Tree()
{
	if (root)
		delete root;
}

template<class Type>
void Tree<Type>::Insert(Type key)
{
	Node<Type> *new_node = new Node<Type>(key), *curr_node = root;
	while (curr_node)
	{
		new_node->parent = curr_node;
		if (curr_node->key > key)
			curr_node = curr_node->left;
		else
			curr_node = curr_node->right;
	}
	if (!new_node->parent)
		root = new_node;
	else if ((new_node->parent)->key > key)
		(new_node->parent)->left = new_node;
	else
		(new_node->parent)->right = new_node;
}

template<class Type>
Node<Type> *Tree<Type>::Search(Type key)
{
	Node<Type> *curr_node = root;
	while (curr_node)
	{
		if (curr_node->key == key)
			return curr_node;
		if (curr_node->key > key)
			curr_node = curr_node->left;
		else
			curr_node = curr_node->right;
	}
	return NULL;
}

template<class Type>
bool Tree<Type>::isEmpty() { return !root; }

template<class Type>
int Tree<Type>::getMaxDepth() { return getMaxDepth(root, 0); }

template<class Type>
int Tree<Type>::getMaxDepth(Node<Type> *node, int depth)
{
	if (!node)
		return depth;
	return std::max(getMaxDepth(node->left, depth + 1), getMaxDepth(node->right, depth + 1));
}

template<class Type>
void Tree<Type>::Traverse(ostream &output, Node<Type> *node)
{
	if (node)
	{
		output << node->key << '\t';
		Traverse(output, node->left);
		Traverse(output, node->right);
	}
}

template<class Type>
std::ostream &operator<<(std::ostream &output, Tree<Type> &tree)
{
	tree.Traverse(output, tree.root);
	return output;
}