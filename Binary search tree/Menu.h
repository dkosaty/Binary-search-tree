#pragma once

#include <vector>
#include <string>

class Menu
{
public:
	Menu(std::vector<std::string> items);
	void Action(int choice);
	friend std::ostream &operator<<(std::ostream &output, const Menu &menu);
private:
	std::vector<std::string> items;
};