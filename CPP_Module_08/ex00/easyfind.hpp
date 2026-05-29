/*
** CPP08 ex00 - easyfind
**
** This exercise teaches function templates and STL algorithms.
** The idea is simple: reuse std::find instead of writing a manual loop.
** That is one of the big C++ lessons of this module:
** prefer tested standard tools when they already solve the problem.
**
** Why block comments?
** The subject asked for teaching notes, so the code explains both
** what the function does and why the design is chosen.
*/

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

/*
** A tiny custom exception is clearer than returning end() silently.
** If the value is not found, the caller gets an explicit failure.
*/
class EasyfindException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("easyfind: value not found");
		}
};

/*
** Non-const overload:
** returns a mutable iterator so the caller can change the found value.
*/
template <typename Container>
typename Container::iterator easyfind(Container& container, int value)
{
	typename Container::iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw EasyfindException();
	return (it);
}

/*
** Const overload:
** this version protects the container from modification.
** It teaches const-correctness, another important habit in C++.
*/
template <typename Container>
typename Container::const_iterator easyfind(const Container& container, int value)
{
	typename Container::const_iterator it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw EasyfindException();
	return (it);
}

#endif
