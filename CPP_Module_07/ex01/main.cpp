/*
** TEACHING FILE - CPP07 ex01: Main test file for iter template
**
** This file demonstrates how iter template works with different types
** and different callback functions.
**
** CONCEPTS USED:
** - CPP01: Function pointers and addresses
** - CPP00: Basic output with std::cout
** - CPP07: Templates that work with function pointers
**
** C++ STANDARD: C++98 (no lambda functions, no std::function)
*/

#include <iostream>
#include <string>
#include "iter.hpp"

/*
** TEST CALLBACK FUNCTIONS:
** These are the functions we'll pass to iter.
** Each one does something with the element it receives.
**
** WHY WRITE THESE SEPARATELY?
** - We need to pass them as function pointers to iter
** - Function name (without ()) is the address of the function
** - We can use &func_name or just func_name to get the pointer
*/

/*
** FUNCTION 1: Print an integer
**
** PURPOSE: Print an integer to std::cout with a newline
**
** PARAMETER:
** - int x: an integer value to print
**
** RETURN: void (nothing to return)
**
** USAGE WITH ITER:
** int array[5] = {1, 2, 3, 4, 5};
** iter(array, 5, &print_int);
** This calls print_int(1), print_int(2), ..., print_int(5)
**
** FUNCTION POINTER SIGNATURE:
** Type of this function is: void (*)(int)
** Can be passed to iter<int> as the third parameter
*/
void print_int(int x)
{
	/*
	** Output the integer
	** std::cout is the output stream (from CPP00)
	** << is stream insertion operator (operator overloading from CPP02)
	** std::endl outputs newline and flushes the stream
	*/
	std::cout << x << std::endl;
}

/*
** FUNCTION 2: Print a float
**
** PURPOSE: Print a float value
**
** PARAMETER:
** - float x: a floating-point value to print
**
** RETURN: void
**
** FUNCTION POINTER SIGNATURE:
** Type: void (*)(float)
** Can be passed to iter<float> only
** NOT compatible with iter<int> (type mismatch)
*/
void print_float(float x)
{
	/*
	** Output the float
	** std::cout automatically formats floats appropriately
	** Default precision usually shows 6 significant digits
	*/
	std::cout << x << std::endl;
}

/*
** FUNCTION 3: Increment and print an integer
**
** PURPOSE: Add 1 to an integer and print it
**
** PARAMETER:
** - int x: value to increment and print
**
** RETURN: void
**
** KEY INSIGHT:
** This function receives the value, not a reference
** So modifying x won't change the original array element
** This demonstrates call-by-value (from CPP01)
**
** FUNCTION POINTER SIGNATURE:
** Type: void (*)(int)
** Same as print_int! But different implementation
*/
void print_int_incremented(int x)
{
	/*
	** x + 1 calculates new value
	** We print x+1, not x
	** Original array is unmodified
	*/
	std::cout << x + 1 << std::endl;
}

/*
** FUNCTION 4: Print a string
**
** PURPOSE: Print a string value
**
** PARAMETER:
** - std::string s: copy of the string
**   We receive a copy (by value, from CPP01)
**   This matches the iter template signature
**
** RETURN: void
**
** FUNCTION POINTER SIGNATURE:
** Type: void (*)(std::string)
** Can be passed to iter<std::string>
**
** WHY BY VALUE AND NOT BY REFERENCE?
** The iter template expects the function signature: void (*func)(T)
** Where T is the template parameter (std::string in this case)
** The parameter type must exactly match T
** To use const reference, we'd need a more complex template
** For simplicity in C++98, we use by-value for this exercise
**
** EFFICIENCY NOTE:
** Passing std::string by value creates a copy
** In production code, we'd want to pass by const reference
** But that requires more advanced template techniques
*/
void print_string(std::string s)
{
	/*
	** Output the string
	** std::cout has operator<< overloaded for std::string
	** Strings print without quotes (unlike C-strings)
	*/
	std::cout << s << std::endl;
}

/*
** MAIN FUNCTION: Demonstrate iter with different types
**
** PURPOSE: Test iter template with:
** 1. Arrays of integers
** 2. Arrays of floats
** 3. Arrays of strings
** 4. Different callback functions
*/
int main(void)
{
	/*
	** TEST 1: Iterate over integers with print_int
	** ================================================================
	*/
	
	/*
	** Create an integer array
	** array_int[5] declares array of 5 integers on the stack (from CPP01)
	** = {10, 20, 30, 40, 50} initializes with these values
	** If we don't initialize, values are garbage (uninitialized)
	*/
	int array_int[5] = {10, 20, 30, 40, 50};
	
	/*
	** Output label
	** Let's print what we're doing
	*/
	std::cout << "--- Integers with print_int ---" << std::endl;
	
	/*
	** Call iter with integer array
	** 
	** PARAMETERS:
	** - array_int: address of first element (implicit conversion)
	**   Array name without [] decays to pointer to first element (from CPP01)
	** - 5: number of elements
	** - &print_int: address of the print_int function
	**   & is not strictly necessary (function name decays to pointer)
	**   but &func_name is explicit and clear
	**
	** TEMPLATE INSTANTIATION:
	** Compiler sees function calls with int parameters
	** Generates: void iter<int>(int array[], size_t length, void (*func)(int))
	**
	** WHAT HAPPENS:
	** Loop iteration 0: (*func)(array_int[0]) -> print_int(10)
	** Loop iteration 1: (*func)(array_int[1]) -> print_int(20)
	** Loop iteration 2: (*func)(array_int[2]) -> print_int(30)
	** Loop iteration 3: (*func)(array_int[3]) -> print_int(40)
	** Loop iteration 4: (*func)(array_int[4]) -> print_int(50)
	*/
	iter(array_int, 5, &print_int);
	
	/*
	** EXPECTED OUTPUT:
	** 10
	** 20
	** 30
	** 40
	** 50
	*/
	
	std::cout << std::endl;
	
	/*
	** TEST 2: Iterate over integers with print_int_incremented
	** ================================================================
	** This shows that different callbacks can work with the same iter template
	*/
	
	std::cout << "--- Integers with print_int_incremented ---" << std::endl;
	
	/*
	** Same array, different callback function
	** The callback receives values by value (not reference)
	** So incrementing in the callback doesn't change the array
	*/
	iter(array_int, 5, &print_int_incremented);
	
	/*
	** EXPECTED OUTPUT:
	** 11 (10 + 1)
	** 21 (20 + 1)
	** 31 (30 + 1)
	** 41 (40 + 1)
	** 51 (50 + 1)
	**
	** The original array is unchanged!
	*/
	
	std::cout << std::endl;
	
	/*
	** TEST 3: Iterate over floats
	** ================================================================
	** Different type = different template instantiation!
	*/
	
	/*
	** Create float array
	** float array_float[4]: array of 4 floats
	** = {1.1f, 2.2f, 3.3f, 4.4f} initializes
	** f suffix tells compiler: 1.1 is float, not double
	*/
	float array_float[4] = {1.1f, 2.2f, 3.3f, 4.4f};
	
	std::cout << "--- Floats with print_float ---" << std::endl;
	
	/*
	** Call iter with float array
	** 
	** TEMPLATE INSTANTIATION:
	** Compiler now generates: void iter<float>(float array[], size_t length, void (*func)(float))
	** This is a COMPLETELY DIFFERENT function from iter<int>!
	**
	** TYPE SAFETY:
	** If we tried to pass print_int (which expects int), compiler would reject it
	** Function pointer type doesn't match: void (*)(float) vs void (*)(int)
	** This is why templates are type-safe!
	*/
	iter(array_float, 4, &print_float);
	
	/*
	** EXPECTED OUTPUT:
	** 1.1
	** 2.2
	** 3.3
	** 4.4
	*/
	
	std::cout << std::endl;
	
	/*
	** TEST 4: Iterate over strings
	** ================================================================
	** Templates work with ANY type that can be iterated
	*/
	
	/*
	** Create string array
	** std::string array_string[3]: array of 3 strings
	** String literals "hello" etc. are converted to std::string by constructor (from CPP00)
	*/
	std::string array_string[3] = {"hello", "world", "template"};
	
	std::cout << "--- Strings with print_string ---" << std::endl;
	
	/*
	** Call iter with string array
	** 
	** TEMPLATE INSTANTIATION:
	** Compiler generates: void iter<std::string>(std::string array[], size_t length, void (*func)(const std::string&))
	** Another completely different function!
	**
	** FUNCTION POINTER WITH REFERENCES:
	** The callback accepts const std::string&
	** This is allowed in function pointers
	** Reference parameter type is part of the function signature
	*/
	iter(array_string, 3, &print_string);
	
	/*
	** EXPECTED OUTPUT:
	** hello
	** world
	** template
	*/
	
	std::cout << std::endl;
	
	/*
	** SUMMARY OF TEMPLATE INSTANTIATION:
	** ================================================================
	** In this program, compiler generated 3 versions of iter:
	** 1. iter<int>(int array[], size_t length, void (*func)(int))
	** 2. iter<float>(float array[], size_t length, void (*func)(float))
	** 3. iter<std::string>(std::string array[], size_t length, void (*func)(const std::string&))
	**
	** POWERFUL CONCEPT:
	** One template, used with 3 different types, 4 different callbacks
	** Each combination is type-safe (checked at compile time)
	** No runtime overhead for type checking
	** No need for inheritance or virtual functions
	**
	** FROM CPP01 MEMORY:
	** - Function pointers store addresses of functions in memory
	** - Dereferencing (*func) calls the function
	** - Arrays decay to pointers when passed to functions
	**
	** ADVANCED CONCEPT FOR LATER:
	** - In C++98, can only pass function pointers
	** - In C++11+, can pass function objects and lambda functions
	** - In C++17+, can pass any callable object
	** - STL provides std::for_each which does something similar
	** but more flexible with iterators instead of pointers
	*/
	
	return (0);
}

/*
** LEARNING COMPLETE:
** You now understand:
** 1. How iter template works with any type
** 2. How function pointers work with templates
** 3. How compiler generates different code for each type
** 4. Generic algorithms (design pattern used in STL)
** 5. Separation of concerns: data (array) vs. operation (callback)
**
** NEXT: Study ex02 to learn class templates (more complex!)
*/
