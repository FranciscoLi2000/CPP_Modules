/*
** CPP08 ex01 - Span
**
** This exercise combines STL containers, iterators and algorithms.
** The class stores integers up to a fixed capacity and can compute:
** - the shortest distance between any two values
** - the longest distance between any two values
**
** The big lesson here is to let the STL do the heavy lifting:
** vector stores the data, sort/min/max compute the results.
*/

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iterator>
#include <limits>
#include <vector>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;

	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span(void);

		void addNumber(int n);

		/*
		** Range insertion is the bonus-style part of the exercise.
		** It teaches that templates can accept iterators from many containers.
		*/
		template <typename InputIterator>
		void addNumber(InputIterator first, InputIterator last);

		int shortestSpan(void) const;
		int longestSpan(void) const;

		class FullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#include "Span.tpp"

#endif
