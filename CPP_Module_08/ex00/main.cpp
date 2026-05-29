/*
** CPP08 ex00 - easyfind demo
**
** Teaching goal:
** - create standard containers
** - search them with a template function
** - catch the exception when the value does not exist
*/

#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	std::vector<int> values;
	std::list<int> numbers;

	/*
	** We fill the containers manually because CPP08 stays in C++98.
	** No initializer lists here; the exercise trains the basics first.
	*/
	values.push_back(10);
	values.push_back(20);
	values.push_back(30);
	values.push_back(40);

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);

	try
	{
		std::cout << "vector search: " << *easyfind(values, 30) << std::endl;
		std::cout << "list search:   " << *easyfind(numbers, 2) << std::endl;
		std::cout << "missing value:  " << *easyfind(values, 99) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
