#include "Fixed.hpp"
#include <iostream>
#include <cmath>

/*
 * Constructor from int:
 * int value is shifted left by _fractionalBits (multiply by 256)
 * Example: Fixed(5) stores 5 * 256 = 1280 in _rawBits
 * When converted back, 1280 / 256 = 5.0
 */
Fixed::Fixed(const int value) : _rawBits(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

/*
 * Constructor from float:
 * We multiply by 2^_fractionalBits (256) and round to nearest integer
 * std::roundf() ensures proper rounding: 2.5 -> 3, 2.4 -> 2
 * Example: Fixed(2.5f) stores roundf(2.5 * 256) = 640 in _rawBits
 */
Fixed::Fixed(const float value) : _rawBits(roundf(value * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _rawBits(src.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_rawBits = rhs.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

/*
 * toFloat() conversion:
 * Convert fixed-point back to floating-point for display/calculation.
 * Divide by 256 (shift right by _fractionalBits)
 */
float	Fixed::toFloat(void) const
{
	return ((float)_rawBits / (1 << _fractionalBits));
}

/*
 * toInt() conversion:
 * Convert fixed-point back to integer, losing fractional part.
 * Shift right by _fractionalBits to get the integer part.
 */
int	Fixed::toInt(void) const
{
	return (_rawBits >> _fractionalBits);
}

/*
 * Comparison Operators:
 * Compare the raw bit values directly.
 * Since fixed-point representation is monotonic (larger raw bits = larger value),
 * we can compare the raw bits directly.
 */
bool	Fixed::operator>(const Fixed &rhs) const
{
	return (_rawBits > rhs._rawBits);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (_rawBits < rhs._rawBits);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (_rawBits >= rhs._rawBits);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (_rawBits <= rhs._rawBits);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (_rawBits == rhs._rawBits);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (_rawBits != rhs._rawBits);
}

/*
 * Arithmetic Operators:
 * 
 * Addition/Subtraction: Simple addition/subtraction of raw bits
 * Example: Fixed(2.0) + Fixed(3.0) = (2*256) + (3*256) = 5*256 = Fixed(5.0)
 * 
 * Multiplication/Division: More complex due to fixed-point arithmetic
 * Multiply: (a * 256) * (b * 256) / 256 = a * b * 256
 *   So: (a_raw * b_raw) / 256
 * Divide: (a * 256) / (b * 256) = a / b
 *   So: (a_raw * 256) / b_raw = (a_raw << 8) / b_raw
 */
Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(_rawBits + rhs._rawBits);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(_rawBits - rhs._rawBits);
	return (result);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits((_rawBits * rhs._rawBits) >> _fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits((_rawBits << _fractionalBits) / rhs._rawBits);
	return (result);
}

/*
 * Pre-Increment (++a):
 * Increments the object first, then returns a reference to it.
 * This is more efficient than post-increment because no copy is made.
 */
Fixed	&Fixed::operator++(void)
{
	_rawBits++;
	return (*this);
}

/*
 * Pre-Decrement (--a):
 * Decrements the object first, then returns a reference to it.
 */
Fixed	&Fixed::operator--(void)
{
	_rawBits--;
	return (*this);
}

/*
 * Post-Increment (a++):
 * The 'int' parameter is a dummy used to distinguish this from pre-increment.
 * Returns a copy of the original value before incrementing.
 * Less efficient than pre-increment due to the copy.
 */
Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	_rawBits++;
	return (temp);
}

/*
 * Post-Decrement (a--):
 * Returns a copy of the original value before decrementing.
 */
Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	_rawBits--;
	return (temp);
}

/*
 * Min function (non-const version):
 * Returns a reference to the smaller of two Fixed objects.
 * Non-const version for non-const Fixed objects.
 */
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a._rawBits < b._rawBits)
		return (a);
	return (b);
}

/*
 * Min function (const version):
 * Returns a const reference to the smaller of two const Fixed objects.
 * This overload allows passing const Fixed objects and returns a const reference.
 */
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._rawBits < b._rawBits)
		return (a);
	return (b);
}

/*
 * Max function (non-const version):
 * Returns a reference to the larger of two Fixed objects.
 */
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a._rawBits > b._rawBits)
		return (a);
	return (b);
}

/*
 * Max function (const version):
 * Returns a const reference to the larger of two const Fixed objects.
 */
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._rawBits > b._rawBits)
		return (a);
	return (b);
}

/*
 * Stream Output Operator:
 * Displays the Fixed number as a floating-point value.
 * Calls toFloat() to convert the raw bits back to a readable format.
 */
std::ostream	&operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}
