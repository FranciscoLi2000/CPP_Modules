/*
** TEACHING FILE - CPP07 ex00: Function Templates (swap, min, max)
**
** LEARNING PROGRESSION:
** - CPP00: Basic C++ syntax, functions, and simple types
** - CPP01: Pointers, references, and memory management fundamentals
** - CPP02: Orthodox Canonical Form, operator overloading for custom types
** - CPP03: Inheritance and polymorphism (runtime type variation)
** - CPP04: Abstract classes and interfaces
** - CPP05: Exception handling
** - CPP06: C++ casting operators
** - CPP07: HERE - C++ TEMPLATES - Compile-time code generation and generic programming
**
** CRITICAL CONCEPT: TEMPLATES
** ==========================================================================
** In previous modules (CPP00-06), we handled different types by:
** 1. Writing separate functions for each type (int, float, double, string)
** 2. Using inheritance/polymorphism (virtual functions - runtime overhead)
** 3. Using void* and casting (unsafe and ugly in C++)
**
** TEMPLATES solve this elegantly: Write code ONCE, compiler generates versions for each type!
**
** WHAT ARE TEMPLATES?
** - Templates are instructions for the C++ compiler to generate code at COMPILE TIME
** - NOT evaluated at runtime like virtual functions
** - Often called "generic programming" or "parametric polymorphism"
**
** ADVANTAGES over inheritance (from CPP03-04):
** - Zero runtime overhead (no virtual function calls, no pointer indirection)
** - Type-safe (checked at compile time, not runtime)
** - Works with built-in types (int, float, char) seamlessly
** - Compiler generates optimized code for each type
**
** DISADVANTAGES:
** - Longer compile times (compiler creates new code for each type)
** - Larger executable size (code duplication)
** - Template code must be in headers or .tpp files (no separate .cpp)
** - Error messages can be cryptic (template instantiation errors)
**
** WHY THIS EXERCISE?
** To teach that some problems don't need inheritance/polymorphism.
** Simple utility functions can be made generic with templates.
** This is the foundation for understanding the STL (Standard Template Library).
*/

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

/*
** FUNCTION TEMPLATE SYNTAX:
** 
** template <typename T>
** ReturnType functionName(T param1, T param2)
** {
**     // T is a placeholder for ANY type
**     // When calling swap(42, 10), T becomes int
**     // When calling swap("hello", "world"), T becomes const char*
** }
**
** KEY DIFFERENCE FROM CPP03 (Inheritance):
** - Inheritance: Handled through virtual functions at RUNTIME
** - Templates: Type is known at COMPILE TIME, compiler generates specific version
**
** TEMPLATE INSTANTIATION:
** When you call swap(a, b) where a and b are ints:
** Compiler creates:
**   void swap<int>(int &a, int &b)
**
** When you call swap(x, y) where x and y are strings:
** Compiler creates a NEW version:
**   void swap<std::string>(std::string &a, std::string &b)
*/

/*
** SWAP FUNCTION TEMPLATE:
**
** PURPOSE: Exchange values of two variables of ANY type
**
** PARAMETERS:
** - T &a: reference to first value (MUST be reference to modify the original)
** - T &b: reference to second value
**
** WHY REFERENCES (from CPP01)?
** Without references (using T a, T b), we'd be swapping COPIES, not the originals!
** References allow us to modify the actual variables passed in.
**
** RETURN TYPE: void
** - We modify the parameters directly, no need to return anything
**
** TEMPLATE PARAMETER: typename T
** - T can be ANY type: int, float, std::string, custom classes, etc.
** - Both parameters must be the SAME type T
** - The type is determined when the function is called (template instantiation)
**
** IMPLEMENTATION STRATEGY:
** Classic swap: use temporary variable
** 1. Save first value to temp
** 2. Copy second value to first
** 3. Copy temp to second
** No assignment operator needed - works with any type supporting operator=
*/
template <typename T>
void swap(T &a, T &b)
{
	/*
	** Temporary variable to hold one value during the swap
	** T tmp: Creates a temporary of type T, invoking the copy constructor
	** 
	** MEMORY (from CPP01):
	** - tmp is stored on the stack (not heap)
	** - Automatically destroyed when swap() ends
	** - Safe and efficient for small types
	*/
	T tmp = a;
	
	/*
	** Copy b's value into a
	** This uses operator= from type T
	** 
	** WHY THIS WORKS FOR ANY TYPE:
	** - Built-in types (int, float): operator= is built-in
	** - std::string: has operator= defined
	** - Custom classes: provided operator= (from CPP02 OCF)
	*/
	a = b;
	
	/*
	** Copy temp (original a) into b
	** Now a and b are swapped!
	*/
	b = tmp;
}

/*
** MIN FUNCTION TEMPLATE:
**
** PURPOSE: Return the smaller of two values of ANY type
**
** PARAMETERS:
** - const T &a: reference to first value (const because we only read it)
** - const T &b: reference to second value
**
** RETURN TYPE: T (not T&)
** - We return a VALUE, not a reference
** - This is safe: if we returned T&, could cause dangling reference issues
**
** SPECIAL RULE (from the spec):
** "If the two are equal, return the second one"
** This is implemented using < (less than) operator
** - If a < b: return b (the second value)
** - Otherwise (a >= b): return a
**
** TEMPLATE REQUIREMENT:
** Type T MUST support:
** - operator< (less than comparison)
** - Copyable (copy constructor, needed to return T)
**
** WHY NOT use <= or >= instead of <?
** - Some custom types might not define all comparison operators
** - Just using < is minimal requirement
** - Works with integers, floats, strings, etc.
**
** CONST PARAMETERS (from CPP00-01):
** We use const T& not T because:
** 1. Efficiency: references avoid copying the entire value into the function
** 2. Intent: const shows we won't modify these values
** 3. Works with temporary values: int min(5+2, 10*2) - can't pass temps to non-const refs
*/
template <typename T>
T min(const T &a, const T &b)
{
	/*
	** LOGIC: Return the smallest value
	** Special rule: if equal, return the SECOND value (b)
	** 
	** IMPLEMENTATION:
	** - If a < b: a is smaller, return a
	** - If a >= b: return b (handles both equal and a > b cases)
	**   - If a == b: return b (second value as required)
	**   - If a > b: return b (the smaller value)
	**
	** Using ternary operator (condition ? true_value : false_value):
	** - More concise and efficient than if/else
	** - Single expression, compiler may inline
	** - Returns second value when values are equal (spec requirement)
	*/
	return (a < b) ? a : b;
}

/*
** MAX FUNCTION TEMPLATE:
**
** PURPOSE: Return the larger of two values of ANY type
**
** PARAMETERS:
** - const T &a: reference to first value
** - const T &b: reference to second value
**
** RETURN TYPE: T (value, not reference, same reason as min())
**
** SPECIAL RULE (from the spec):
** "If the two are equal, return the second one"
** This is implemented using > (greater than) operator
** - If a > b: return a
** - Otherwise (a <= b): return b (the second value)
**
** TEMPLATE REQUIREMENT:
** Type T MUST support:
** - operator> (greater than comparison)
** - Copyable (copy constructor, needed to return T)
**
** COMPARISON WITH MIN:
** min uses <, max uses >
** For equal values:
** - min(a, a) returns a (second via ? : logic: a<a is false, return a)
** - max(a, a) returns a (second via ? : logic: a>a is false, return b which is a)
** Both consistently return the second value when equal.
*/
template <typename T>
T max(const T &a, const T &b)
{
	/*
	** LOGIC: If a > b, return a, else return b (second)
	** Mirrors max concept: return the bigger value
	** Special case: if equal, return second (b)
	*/
	return (a > b) ? a : b;
}

/*
** SUMMARY OF TEMPLATE CONCEPTS USED HERE:
** ================================================================
**
** 1. GENERIC PROGRAMMING:
**    One template function works with int, float, string, custom classes
**    No need for function overloading or inheritance
**
** 2. COMPILE-TIME POLYMORPHISM:
**    Unlike CPP03 (inheritance with virtual - runtime polymorphism)
**    Compiler decides which version to use at COMPILE TIME
**    Errors caught before runtime
**
** 3. TYPE SAFETY:
**    Can't accidentally pass different types (swap(5, "hello") won't compile)
**    Compiler will reject it with "template parameter deduction error"
**
** 4. ZERO RUNTIME OVERHEAD:
**    No virtual function tables, no pointer chasing
**    Each instantiation can be fully inlined by the compiler
**    As fast as hand-written code for that specific type
**
** 5. TEMPLATE INSTANTIATION:
**    First time swap<int> is called, compiler generates it
**    Each type gets its own copy (code bloat trade-off)
**    But specialization: compiler may optimize specific types
**
** WHEN TO USE TEMPLATES vs INHERITANCE (CPP03 lesson):
** Use TEMPLATES when:
** - You need maximum performance (no virtual overhead)
** - Working with many different types that share operations
** - You want compile-time checking
**
** Use INHERITANCE when:
** - You need runtime polymorphism (dynamic dispatch)
** - Different types may be known only at runtime
** - You want smaller code size (code shared via virtual functions)
*/

#endif // TEMPLATE_HPP
