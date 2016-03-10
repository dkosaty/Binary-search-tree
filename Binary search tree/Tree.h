#pragma once

#include <ostream>

using namespace std;

template<class Type>
class Node
{
public:
	Node(Type key);
	~Node();
	friend ostream &operator<<<Type>(ostream &output, const Node<Type> &node);
protected:
	Type key;
	Node<Type> *parent, *left, *right;
private:
	template<class Type>
	friend class Tree;
};

template<class Type>
class Tree
{
public:
	Tree();
	~Tree();
	void Insert(Type key);
	Node<Type> *Search(Type key);
	bool isEmpty();
	int getMaxDepth(); int getMaxDepth(Node<Type> *node, int depth);
	void Traverse(ostream &output, Node<Type> *node);
	friend ostream &operator<<<Type>(ostream &output, Tree<Type> &tree);
private:
	Node<Type> *root;
};