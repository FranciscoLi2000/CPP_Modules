#ifndef DOG_HPP
#define DOG_HPP

/*
 * Derived Class: Dog
 * 
 * Dog is-a Animal:
 * - Dog inherits from Animal (public inheritance)
 * - Dog has all of Animal's members and methods
 * - Dog can override virtual functions to provide its own behavior
 * - Dog is responsible for implementing pure virtual functions (makeSound)
 */

#include "Animal.hpp"

class Dog : public Animal
{
public:
	/*
	 * Constructor:
	 * Calls the base class (Animal) constructor first through member initializer list.
	 * Then initializes any Dog-specific members.
	 */
	Dog(void);

	/*
	 * Destructor:
	 * Called first when a Dog object is destroyed.
	 * Then automatically calls the base class destructor.
	 */
	~Dog(void);

	/*
	 * Copy constructor and assignment (if needed, though not overridden here).
	 * Can inherit from base class or override for Dog-specific behavior.
	 */
	Dog(const Dog &src);
	Dog	&operator=(const Dog &rhs);

	/*
	 * Implementation of pure virtual function from Animal:
	 * Every concrete derived class MUST implement this.
	 */
	virtual void	makeSound(void) const;

	/*
	 * Optional override of virtual function:
	 * We override eat() to show Dog-specific behavior.
	 */
	virtual void	eat(void) const;

private:
	/*
	 * Dog-specific member variable.
	 * Not shared with other Animal types.
	 */
	int	_breed;
};

#endif
