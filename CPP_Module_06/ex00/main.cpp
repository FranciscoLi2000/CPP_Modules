/*
** TEACHING FILE - main.cpp for ex00
** 
** PURPOSE: Demonstrate ScalarConverter functionality with various test cases
**
** LEARNING POINTS DEMONSTRATED:
** 1. How to call static methods (ScalarConverter::convert)
** 2. Command-line argument parsing (argc, argv)
** 3. Testing edge cases in type conversion
** 4. Understanding when conversions are "impossible"
**
** COMPILATION:
** make
**
** USAGE EXAMPLES:
** ./convert 0              # char: Non displayable, int: 0, float: 0.0f, double: 0.0
** ./convert 42             # char: '*', int: 42, float: 42.0f, double: 42.0
** ./convert 42.0f          # all types converted from float
** ./convert 'c'            # convert character
** ./convert nan            # NaN special value
** ./convert -inff          # -infinity float
*/

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	/*
	** INPUT VALIDATION:
	** 
	** WHY THIS CHECK?
	** - Program needs exactly one command-line argument
	** - argv[0] is the program name (not counted in argc-1)
	** - argc should be 2 (program name + 1 argument)
	**
	** LEARNING FROM PREVIOUS MODULES:
	** - CPP00: Basic C++ with main function basics
	** - CPP05: Exception handling (here we use simple error return instead)
	*/
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <scalar literal>" << std::endl;
		std::cerr << "Examples: 42, 42.0f, 'c', nan, -inf" << std::endl;
		return 1;
	}

	/*
	** CALL STATIC METHOD:
	** 
	** ScalarConverter::convert(argv[1]);
	** 
	** WHY ::SCOPE RESOLUTION OPERATOR?
	** - Accesses static member of ScalarConverter class
	** - No instance needed (no object instantiation)
	** - Similar to calling std::cout << "hello"
	** - The :: says "look in ScalarConverter namespace/class"
	**
	** WHY argv[1]?
	** - argv is array of C-strings (char* array)
	** - argv[0] is program name
	** - argv[1] is first user argument
	** - It gets implicitly converted to std::string (ScalarConverter constructor handles it)
	*/
	ScalarConverter::convert(argv[1]);

	return 0;
}
