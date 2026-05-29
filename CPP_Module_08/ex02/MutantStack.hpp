/*
** CPP08 ex02 - MutantStack
**
** std::stack is a container adaptor, which means it wraps another
** container and only exposes stack-style operations.
**
** The trick in this exercise is to inherit from std::stack and expose
** the protected underlying container `c` through iterators.
*/

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator			iterator;
		typedef typename std::stack<T>::container_type::const_iterator		const_iterator;

		MutantStack(void) : std::stack<T>()
		{
		}

		MutantStack(const MutantStack& other) : std::stack<T>(other)
		{
		}

		MutantStack& operator=(const MutantStack& other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}

		~MutantStack(void)
		{
		}

		/*
		** begin/end simply forward to the wrapped container.
		** This is the important design idea: the stack keeps its behavior,
		** but the user can also iterate like with a normal STL container.
		*/
		iterator begin(void)
		{
			return (this->c.begin());
		}

		iterator end(void)
		{
			return (this->c.end());
		}

		const_iterator begin(void) const
		{
			return (this->c.begin());
		}

		const_iterator end(void) const
		{
			return (this->c.end());
		}
};

#endif
