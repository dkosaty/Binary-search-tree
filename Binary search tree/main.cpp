#include <iostream>
#include "Menu.h"

int main()
{
	Menu menu({ "0. Exit",
		"1. Insert the new node",
		"2. Search of the node",
		"3. Get max depth",
		"4. Show the tree" });
	std::cout << "Menu:" << std::endl; std::cout << menu;
	while (true)
	{
		int choice = 0; std::cout << ">>> "; std::cin >> choice;
		menu.Action(choice);
	}
	return 0;
}