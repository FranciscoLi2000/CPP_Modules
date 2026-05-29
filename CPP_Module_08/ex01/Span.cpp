/*
** Span.cpp contains the non-template logic.
** The implementation focuses on two ideas:
** 1. protect the class invariants
** 2. reuse algorithms instead of writing low-level loops
*/

#include "Span.hpp"

#include <iostream>

Span::Span(void) : _numbers(), _maxSize(0)
{
	/*
	** Default construction gives an empty span with no capacity.
	** This keeps the class valid even before the user chooses a size.
	*/
}

Span::Span(unsigned int N) : _numbers(), _maxSize(N)
{
	/*
	** N is fixed at construction because the exercise models a bounded
	** container. Once the capacity is set, it never changes.
	*/
}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize)
{
	/*
	** vector already knows how to copy its own elements.
	** That is a nice example of how STL types reduce manual work.
	*/
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	return (*this);
}

Span::~Span(void)
{
}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw FullSpanException();
	_numbers.push_back(n);
}

int Span::shortestSpan(void) const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> sorted(_numbers);
	long best;

	std::sort(sorted.begin(), sorted.end());
	best = std::numeric_limits<long>::max();
	for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i)
	{
		long current = static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]);

		if (current < best)
			best = current;
	}
	return (static_cast<int>(best));
}

int Span::longestSpan(void) const
{
	std::vector<int>::const_iterator minIt;
	std::vector<int>::const_iterator maxIt;

	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();
	minIt = std::min_element(_numbers.begin(), _numbers.end());
	maxIt = std::max_element(_numbers.begin(), _numbers.end());
	return (static_cast<int>(static_cast<long>(*maxIt) - static_cast<long>(*minIt)));
}

const char* Span::FullSpanException::what() const throw()
{
	return ("Span: container is full");
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return ("Span: not enough numbers");
}
