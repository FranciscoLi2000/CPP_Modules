#include "Fixed.hpp"
#include <iostream>

/*
 * Main test program for ex00:
 * Demonstrates the Orthodox Canonical Form in action.
 * We'll see which methods are called and when.
 */
int	main(void)
{
	Fixed	a;

	/*
	 * Copy Constructor:
	 * When we create 'b' as a copy of 'a', the copy constructor is invoked.
	 * This creates a new object with the same state as 'a'.
	 */
	Fixed	b(a);

	/*
	 * Default Constructor:
	 * Creating 'c' as a new Fixed object calls the default constructor.
	 */
	Fixed	c;

	/*
	 * Copy Assignment Operator:
	 * Assigning 'c' to 'a' calls the copy assignment operator.
	 * This copies the data from 'c' into 'a' (both objects already existed).
	 */
	a = b = c;

	/*
	 * Stream Output:
	 * Using operator<< to print Fixed objects.
	 */
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;

	/*
	 * Automatic Cleanup:
	 * When main() returns, all local objects go out of scope.
	 * Their destructors are called automatically in reverse order of creation.
	 * This demonstrates RAII (Resource Acquisition Is Initialization).
	 */
	return (0);
}
