/*
** Template code must be visible to every translation unit that uses it.
** That is why the range-add function lives in a .tpp file included
** from the header instead of a separate .cpp.
*/

template <typename InputIterator>
void Span::addNumber(InputIterator first, InputIterator last)
{
	std::vector<int>::size_type count = static_cast<std::vector<int>::size_type>(std::distance(first, last));

	if (_numbers.size() + count > static_cast<std::vector<int>::size_type>(_maxSize))
		throw FullSpanException();
	_numbers.insert(_numbers.end(), first, last);
}
