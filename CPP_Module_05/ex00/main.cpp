#include "Bureaucrat.hpp"
#include <iostream>

/*
 * This main starts with the central rule of the module: grade bounds matter.
 */
int	main(void)
{
	try
	{
		Bureaucrat alice("Alice", 2);
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << alice << std::endl;
		alice.decrementGrade();
		std::cout << alice << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooHigh("TooHigh", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("TooLow", 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	return (0);
}
