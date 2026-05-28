#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	int	i;

	std::cout << "Brain copy constructor called" << std::endl;
	for (i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	int	i;

	if (this != &other)
	{
		for (i = 0; i < 100; ++i)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index >= 100)
		return ;
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= 100)
		return ("");
	return (ideas[index]);
}
