#include <iostream>
#include "Menu.h"
#include "Tree.cpp"

typedef int Type;

Tree<Type> tree;

Menu::Menu(vector<string> items) :items(items) {}

void Menu::Action(int choice)
{
	Type key;
	switch (choice)
	{
	case 0:
		exit(EXIT_SUCCESS);
	case 1:
		cout << "Enter the key = "; cin >> key;
		tree.Insert(key);
		break;
	case 2:
		cout << "Enter the key of the node which will found = "; cin >> key;
		cout << "The found node: " << tree.Search(key) << endl;
		break;
	case 3:
		cout << "The max depth of the tree = " << tree.getMaxDepth() << endl;
		break;
	case 4:
		if (tree.isEmpty())
			cout << "The tree is empty" << endl;
		else
			cout << tree << endl;
		break;
	default:
		exit(EXIT_FAILURE);
		break;
	}
}

ostream &operator<<(ostream &output, const Menu &menu)
{
	for (auto item : menu.items)
		output << item << endl;
	return output;
}