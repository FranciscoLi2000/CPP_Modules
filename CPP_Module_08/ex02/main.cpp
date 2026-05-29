/*
** CPP08 ex02 - MutantStack demo
**
** The exercise proves that inheritance can extend an adaptor class.
** We still use stack behavior, but we can also walk through the values.
*/

#include "MutantStack.hpp"

#include <iostream>

int main(void)
{
	MutantStack<int> mstack;
	MutantStack<int>::iterator it;

	/*
	** Push order matters: the top of the stack is the last pushed value,
	** while iteration walks through the underlying container order.
	*/
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "top: " << mstack.top() << std::endl;

	mstack.pop();
	std::cout << "top after pop: " << mstack.top() << std::endl;

	for (it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;

	return (0);
}
