#include "Fixed.hpp"
#include <iostream>

/*
 * Default Constructor Implementation:
 * Initializes _rawBits to 0 (representing 0.0 in fixed-point).
 */
Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/*
 * Destructor Implementation:
 * Called when the object is destroyed (goes out of scope or is explicitly deleted).
 * We print to show object lifecycle.
 */
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/*
 * Copy Constructor Implementation:
 * Deep copy of the source object.
 * : _rawBits(src.getRawBits()) initializes our _rawBits with the source's value.
 * The member function getRawBits() is called on the source object.
 */
Fixed::Fixed(const Fixed &src) : _rawBits(src.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

/*
 * Copy Assignment Operator Implementation:
 * 
 * Important: This operator is called when assigning between existing objects.
 * Steps:
 * 1. Check for self-assignment (a = a) to avoid unnecessary work
 * 2. Copy the data from rhs to this object
 * 3. Return a reference to *this so we can chain assignments (a = b = c)
 */
Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	/*
	 * Self-assignment guard:
	 * If we're assigning to ourselves, we can skip the copy and return immediately.
	 */
	if (this != &rhs)
	{
		_rawBits = rhs.getRawBits();
	}
	return (*this);
}

/*
 * getRawBits() implementation:
 * Simple accessor that returns the raw fixed-point value.
 * marked const because it doesn't modify the object state.
 */
int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

/*
 * setRawBits() implementation:
 * Simple mutator that sets the raw fixed-point value.
 */
void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

/*
 * Operator<< Implementation:
 * This allows printing a Fixed object to an output stream.
 * We output the raw bits in decimal form.
 */
std::ostream	&operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.getRawBits();
	return (o);
}
