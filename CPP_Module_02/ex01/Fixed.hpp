#ifndef FIXED_HPP
#define FIXED_HPP

/*
 * CPP02 - Exercise 01: Operator Overloading
 * 
 * Building on ex00, we now add:
 * 1. Constructor from int and float (implicit conversions)
 * 2. Arithmetic Operators: +, -, *, /
 * 3. Comparison Operators: <, >, <=, >=, ==, !=
 * 4. Increment/Decrement: ++a, a++, --a, a--
 * 5. Min/Max static functions
 * 
 * Operator Overloading:
 * - Allows us to define custom behavior for operators on our classes
 * - Some operators can be members, others must be free functions
 * - Provides a more natural, intuitive syntax for operations
 */

#include <iostream>
#include <cmath>

class Fixed
{
public:
	/*
	 * Constructor from int:
	 * Converts an integer to a fixed-point number.
	 * Shift left by _fractionalBits: multiply by 2^8 = 256
	 * explicit prevents accidental implicit conversions
	 */
	explicit Fixed(const int value);

	/*
	 * Constructor from float:
	 * Converts a floating-point number to fixed-point.
	 * Round to the nearest integer: value * 256 + 0.5
	 * This avoids truncation errors.
	 */
	explicit Fixed(const float value);

	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &src);
	Fixed	&operator=(const Fixed &rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	/*
	 * Conversion operators:
	 * Allow converting a Fixed back to int or float for display/calculation
	 * Note: These enable implicit conversions, which can be dangerous
	 * but are useful for display purposes in this exercise
	 */
	float	toFloat(void) const;
	int		toInt(void) const;

	/*
	 * Comparison Operators:
	 * Return true or false based on comparison.
	 * All are const because they don't modify the object state.
	 */
	bool	operator>(const Fixed &rhs) const;
	bool	operator<(const Fixed &rhs) const;
	bool	operator>=(const Fixed &rhs) const;
	bool	operator<=(const Fixed &rhs) const;
	bool	operator==(const Fixed &rhs) const;
	bool	operator!=(const Fixed &rhs) const;

	/*
	 * Arithmetic Operators:
	 * Perform mathematical operations between Fixed objects.
	 */
	Fixed	operator+(const Fixed &rhs) const;
	Fixed	operator-(const Fixed &rhs) const;
	Fixed	operator*(const Fixed &rhs) const;
	Fixed	operator/(const Fixed &rhs) const;

	/*
	 * Pre-Increment/Decrement (++a, --a):
	 * Returns a reference to the modified object.
	 * This allows: a = ++b = ++c;
	 */
	Fixed	&operator++(void);
	Fixed	&operator--(void);

	/*
	 * Post-Increment/Decrement (a++, a--):
	 * Takes a dummy 'int' parameter to distinguish from pre-version.
	 * Returns a copy of the original value (by value, not reference).
	 * More expensive than pre-increment because it creates a copy.
	 */
	Fixed	operator++(int);
	Fixed	operator--(int);

	/*
	 * Min/Max Static Functions:
	 * Static functions work on the class, not on instances.
	 * We don't need an object to call them: Fixed::min(a, b);
	 * Return const references to avoid copies of potentially large objects.
	 */
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
};

std::ostream	&operator<<(std::ostream &o, const Fixed &fixed);

#endif
