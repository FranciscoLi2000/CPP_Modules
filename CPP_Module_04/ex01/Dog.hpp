#ifndef DOG_HPP
#define DOG_HPP

/*
 * Dog now owns a Brain, so copying must duplicate the pointed-to object.
 */

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	virtual ~Dog(void);

	virtual void	makeSound(void) const;
	void	setIdea(int index, const std::string &idea);
	std::string	getIdea(int index) const;

private:
	Brain	*_brain;
};

#endif
