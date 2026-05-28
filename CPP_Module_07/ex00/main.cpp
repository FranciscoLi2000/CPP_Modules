/*
** TEACHING FILE - CPP07 ex00: Main test file for swap, min, max templates
**
** This file demonstrates how template functions are instantiated by the compiler.
** Each time we call a template with a NEW type, the compiler generates a version.
**
** COMPILATION CONCEPT:
** When we call:
**   swap(a, b);        // a, b are ints -> Compiler generates swap<int>
**   swap(c, d);        // c, d are strings -> Compiler generates swap<std::string>
**   min(a, b);         // ints -> Compiler generates min<int>
**   max(a, b);         // ints -> Compiler generates max<int>
**
** LINKER then combines all these generated functions into the final executable.
** This is why templates must be in .hpp/.tpp (visible to compiler everywhere).
**
** C++ STANDARD: C++98
** This code compiles with -std=c++98 flag (no C++11 features used)
*/

#include <iostream>
#include <string>
/*
** Why include <string>?
** - Need std::string for testing templates with non-primitive types
** - std::string has operator<, operator> defined in C++98
** - Demonstrates that templates work with library types, not just built-ins
**
** Why include <iostream>?
** - Need std::cout for output
** - Need std::endl for newlines
*/

#include "template.hpp"
/*
** Include the template functions
** Must use .hpp so compiler sees template definitions
** When this .hpp is included, compiler has the template code available
*/

/*
** WHAT DOES main() DO?
** 
** PURPOSE: Demonstrate all three template functions with different types
** 
** We test:
** 1. SWAP with ints
** 2. MIN/MAX with ints
** 3. SWAP with strings
** 4. MIN/MAX with strings
**
** WHY TEST WITH BOTH ints AND strings?
** To prove the templates work with ANY type!
** This is the power of generic programming.
**
** EXPECTED OUTPUT:
** a = 3, b = 2
** min(a, b) = 2
** max(a, b) = 3
** c = chaine2, d = chaine1
** min(c, d) = chaine1
** max(c, d) = chaine2
*/
int main(void)
{
	/*
	** TEST 1: Swap with integers
	** ==================================================
	*/
	
	/*
	** Declare two integers
	** int is the most basic type in C++
	** Both get stack memory (automatic storage, from CPP01)
	*/
	int a = 2;
	int b = 3;
	
	/*
	** Call swap(a, b)
	** Since a and b are ints, compiler instantiates swap<int>
	** 
	** BEHIND THE SCENES:
	** Compiler generates:
	**   void swap<int>(int &a, int &b)
	**   {
	**       int tmp = a;       // tmp = 2
	**       a = b;             // a = 3
	**       b = tmp;           // b = 2
	**   }
	**
	** Then calls: swap<int>(a, b);
	** Result: a becomes 3, b becomes 2
	*/
	::swap(a, b);
	/*
	** Why :: prefix?
	** - Explicitly calls global namespace swap
	** - Avoids confusion with std::swap (from STL)
	** - In C++98, good practice to be explicit about which function we're calling
	*/
	
	/*
	** Print the swapped values
	** std::cout is the C++ output stream (from CPP00)
	** << operator chains output (operator overloading from CPP02)
	** std::endl outputs newline and flushes buffer
	*/
	std::cout << "a = " << a << ", b = " << b << std::endl;
	/*
	** Expected output: a = 3, b = 2
	*/
	
	/*
	** Call min(a, b) with instantiated ints
	** Compiler creates min<int>
	** Returns min value, or second if equal
	** min(3, 2) -> 3 > 2, so return 2 (second value)
	*/
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	/*
	** Expected output: min( a, b ) = 2
	*/
	
	/*
	** Call max(a, b)
	** Compiler creates max<int>
	** Returns max value, or second if equal
	** max(3, 2) -> 3 > 2, so return 3 (first value)
	*/
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	/*
	** Expected output: max( a, b ) = 3
	*/
	
	/*
	** TEST 2: Swap, min, max with strings
	** ==================================================
	** This demonstrates templates work with ANY type that supports
	** operator<, operator>, operator= and copy constructor.
	** std::string has all of these (standard library, C++98)
	*/
	
	/*
	** Declare two strings using std::string
	** String literals like "chaine1" are const char*
	** Constructor of std::string converts them to std::string objects
	** 
	** CONSTRUCTOR CALL (from CPP00):
	** std::string c = "chaine1" calls:
	**   std::string(const char *str)
	** which creates a string object from the C-string literal
	*/
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	/*
	** Call swap with strings
	** Compiler generates swap<std::string>
	** This is a DIFFERENT function from swap<int>!
	** 
	** BEHIND THE SCENES:
	** Compiler generates:
	**   void swap<std::string>(std::string &a, std::string &b)
	**   {
	**       std::string tmp = a;   // Uses std::string copy constructor
	**       a = b;                  // Uses std::string operator=
	**       b = tmp;                // Uses std::string operator=
	**   }
	**
	** The underlying logic is identical to swap<int>!
	** But it's a completely separate function.
	*/
	::swap(c, d);
	
	/*
	** Output the swapped strings
	** std::string has operator<< defined, so it prints correctly
	*/
	std::cout << "c = " << c << ", d = " << d << std::endl;
	/*
	** Expected output: c = chaine2, d = chaine1
	*/
	
	/*
	** Call min(c, d) with strings
	** Compiler creates min<std::string>
	** String comparison: lexicographic (dictionary order)
	** "chaine2" < "chaine2" (same)? No, so return second (d = "chaine1"... wait)
	**
	** WAIT! After swap: c = "chaine2", d = "chaine1"
	** min("chaine2", "chaine1"):
	**   Is "chaine2" < "chaine1"? In lexicographic order, "chaine2" > "chaine1"
	**   So the condition (a < b) is false
	**   Return second value: d = "chaine1"
	*/
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	/*
	** Expected output: min( c, d ) = chaine1
	*/
	
	/*
	** Call max(c, d) with strings
	** max("chaine2", "chaine1"):
	**   Is "chaine2" > "chaine1"? Yes (lexicographic)
	**   Return first value: c = "chaine2"
	*/
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	/*
	** Expected output: max( c, d ) = chaine2
	*/
	
	/*
	** TEMPLATE INSTANTIATION SUMMARY:
	** ================================================================
	**
	** Compiler generated 6 template instances in this program:
	** 1. swap<int>
	** 2. min<int>
	** 3. max<int>
	** 4. swap<std::string>
	** 5. min<std::string>
	** 6. max<std::string>
	**
	** Each function is completely independent:
	** - Different implementations generated by the compiler
	** - Compiler inlines the simple functions
	** - No runtime overhead compared to hand-written versions
	**
	** WHY THIS IS POWERFUL (vs CPP03 inheritance):
	** - No virtual function call overhead
	** - Works with built-in types (int, float)
	** - Each instantiation can be optimized individually
	** - No need for abstract base classes or pointer casting
	**
	** WHY WE CAN'T ALWAYS USE TEMPLATES:
	** - Must know types at compile time
	** - Can't use polymorphism (different types passed to same function at runtime)
	** - Compilation slower (must generate code for each type)
	** - Compiler errors are more complex and harder to debug
	*/
	
	/*
	** Return 0: Program succeeded
	** (from CPP00 - standard C/C++ convention)
	*/
	return (0);
}

/*
** LEARNING COMPLETE:
** You now understand:
** 1. How templates work at compile time
** 2. Template instantiation (compiler generates code)
** 3. Generic programming benefits
** 4. Why templates are different from inheritance (CPP03)
** 5. How to write type-safe utility functions
**
** NEXT: Study ex01 to learn about function pointers in templates
*/
