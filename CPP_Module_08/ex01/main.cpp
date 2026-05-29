/*
** CPP08 ex01 - Span demo
**
** The demo shows:
** - single insertions
** - range insertion from iterators
** - the two span computations
** - exception handling when the class is overfilled
*/

#include "Span.hpp"

#include <iostream>
#include <vector>

static void printResult(const char* label, int value)
{
	std::cout << label << value << std::endl;
}

int main(void)
{
	Span sp(6);
	std::vector<int> extra;

	extra.push_back(12);
	extra.push_back(4);
	extra.push_back(25);
	extra.push_back(9);

	/*
	** We mix single values and range insertion to show both APIs.
	** This mirrors how real STL containers are commonly used.
	*/
	sp.addNumber(42);
	sp.addNumber(7);
	sp.addNumber(extra.begin(), extra.end());

	printResult("shortest span: ", sp.shortestSpan());
	printResult("longest span:  ", sp.longestSpan());

	try
	{
		sp.addNumber(100);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
