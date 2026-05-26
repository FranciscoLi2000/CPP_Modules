#ifndef FIXED_HPP
#define FIXED_HPP

/*
 * CPP02 - Exercise 00: Fixed-point Numbers
 * 
 * Orthodox Canonical Form (OCF) Overview:
 * - Also known as the "Rule of Three" (or Four in C++11+)
 * - When a class manages resources, we must define:
 *   1. Default Constructor: Initialize the object
 *   2. Destructor: Clean up resources
 *   3. Copy Constructor: Create a copy from another object
 *   4. Copy Assignment Operator: Assign one object to another
 * 
 * Fixed-Point Representation:
 * - A fixed-point number uses a fixed number of bits for the decimal part
 * - Example: if we have 8 bits for the fractional part, value 256 = 1.0
 * - This avoids floating-point precision issues in some contexts
 */

#include <iostream>

class Fixed
{
public:
	/*
	 * Default Constructor:
	 * Called when a Fixed object is created without arguments.
	 * Initializes the object to a known state (rawBits = 0).
	 */
	Fixed(void);

	/*
	 * Destructor:
	 * Called when the object is destroyed.
	 * Cleans up any resources (though this simple class has none).
	 * We print debug info to understand object lifetime.
	 */
	~Fixed(void);

	/*
	 * Copy Constructor:
	 * Called when creating a new object from an existing one: Fixed a(b);
	 * Must create an independent copy of the source object.
	 */
	Fixed(const Fixed &src);

	/*
	 * Copy Assignment Operator:
	 * Called when assigning one existing object to another: a = b;
	 * Different from copy constructor (both objects already exist).
	 * Must handle self-assignment and return a reference to self.
	 */
	Fixed	&operator=(const Fixed &rhs);

	/*
	 * Getters/Setters:
	 * - getRawBits(): Returns the raw fixed-point representation
	 * - setRawBits(): Sets the raw fixed-point representation
	 */
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					_rawBits;

	/*
	 * Static Member Variable:
	 * Shared across all Fixed instances.
	 * Defines the number of bits to the right of the binary point.
	 * If _fractionalBits = 8, then 256 represents 1.0
	 */
	static const int	_fractionalBits = 8;
};

/*
 * Operator Overloading for Output:
 * Allows: std::cout << myFixed;
 * The << operator is defined outside the class because the left operand (std::ostream) is not Fixed.
 */
std::ostream	&operator<<(std::ostream &o, const Fixed &fixed);

#endif
