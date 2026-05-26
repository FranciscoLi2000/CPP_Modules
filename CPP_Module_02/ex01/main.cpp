#include "Fixed.hpp"
#include <iostream>

/*
 * Main test program for ex01:
 * Demonstrates all operator overloads we've implemented.
 */
int	main(void)
{
	/*
	 * Test 1: Constructors and conversions
	 * Create Fixed objects from int and float
	 */
	Fixed	a(10);
	Fixed	b(42.42f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;

	/*
	 * Test 2: Arithmetic operations
	 */
	std::cout << "\n--- Arithmetic Operations ---" << std::endl;
	Fixed	c = a + b;
	Fixed	d = a - b;
	Fixed	e = a * b;
	Fixed	f = a / b;

	std::cout << "a + b = " << c << std::endl;
	std::cout << "a - b = " << d << std::endl;
	std::cout << "a * b = " << e << std::endl;
	std::cout << "a / b = " << f << std::endl;

	/*
	 * Test 3: Comparison operators
	 */
	std::cout << "\n--- Comparison Operations ---" << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	/*
	 * Test 4: Increment/Decrement
	 */
	std::cout << "\n--- Increment/Decrement ---" << std::endl;
	Fixed	g(5);
	std::cout << "g = " << g << std::endl;
	std::cout << "++g = " << ++g << std::endl;
	std::cout << "g++ = " << g++ << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "--g = " << --g << std::endl;
	std::cout << "g-- = " << g-- << std::endl;
	std::cout << "g = " << g << std::endl;

	/*
	 * Test 5: Min and Max functions
	 */
	std::cout << "\n--- Min and Max ---" << std::endl;
	std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

	return (0);
}
