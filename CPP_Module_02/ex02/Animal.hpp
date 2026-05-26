#ifndef ANIMAL_HPP
#define ANIMAL_HPP

/*
 * CPP02 - Exercise 02: Polymorphism and Inheritance
 * 
 * Key Concepts:
 * 
 * 1. Inheritance:
 *    - A derived class inherits from a base class
 *    - Allows code reuse and hierarchy organization
 *    - public inheritance: derived class is a kind of base class
 * 
 * 2. Virtual Functions:
 *    - A virtual function can be overridden by derived classes
 *    - Called through a pointer/reference, uses the actual (derived) class's version
 *    - Enables polymorphic behavior (many forms)
 * 
 * 3. Virtual Destructors (CRITICAL!):
 *    - When deleting a derived object through a base pointer, the virtual destructor
 *      ensures the derived destructor is called first, then the base destructor
 *    - Without virtual destructor, only base destructor is called -> memory leak!
 * 
 * 4. Abstract Base Class:
 *    - A class with at least one pure virtual function (= 0)
 *    - Cannot be instantiated directly, only used as a base class
 *    - Forces derived classes to implement the pure virtual functions
 */

#include <string>
#include <iostream>

/*
 * Abstract base class Animal
 * Cannot create instances of Animal directly, only derived classes.
 */
class Animal
{
public:
	/*
	 * Default constructor:
	 * Initializes common animal properties.
	 */
	Animal(void);

	/*
	 * CRITICAL: Virtual destructor!
	 * Ensures that when deleting a derived object (e.g., Dog*) through a base pointer (Animal*),
	 * the derived destructor runs first, then the base destructor.
	 * This prevents memory leaks when resources are held by derived classes.
	 */
	virtual ~Animal(void);

	/*
	 * Copy constructor and assignment operator.
	 * Following Orthodox Canonical Form.
	 */
	Animal(const Animal &src);
	Animal	&operator=(const Animal &rhs);

	/*
	 * Pure Virtual Function:
	 * = 0 means this function MUST be implemented by derived classes.
	 * Cannot be called on an Animal object directly (it's abstract).
	 * This forces derived classes to define their own behavior.
	 */
	virtual void	makeSound(void) const = 0;

	/*
	 * Virtual function (not pure):
	 * Derived classes CAN override this, but don't have to.
	 * If not overridden, the base implementation is used.
	 */
	virtual void	eat(void) const;

	/*
	 * Getters:
	 * const functions that return member variables.
	 */
	const std::string	&getName(void) const;
	unsigned int		getAge(void) const;

	/*
	 * Setters:
	 * Modifiers for member variables.
	 */
	void	setName(const std::string &name);
	void	setAge(unsigned int age);

protected:
	/*
	 * Protected members:
	 * Not public (hidden from outside), but accessible to derived classes.
	 * This allows derived classes to directly modify these values if needed.
	 */
	std::string		_name;
	unsigned int	_age;

private:
	/*
	 * Private members:
	 * Not accessible from outside or from derived classes.
	 * Use protected for data you want derived classes to access.
	 */
};

#endif
