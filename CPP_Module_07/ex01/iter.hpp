/*
** TEACHING FILE - CPP07 ex01: Function template iter
**
** LEARNING PROGRESSION:
** - CPP00: Basic C++ functions and classes
** - CPP01: Pointers and references - CRITICAL for this exercise
** - CPP02: operator overloading
** - CPP03: Inheritance and polymorphism
** - CPP04: Abstract classes
** - CPP05: Exception handling
** - CPP06: Type casting
** - CPP07: Templates part 1 - HERE - Advanced template usage with function pointers
**
** WHAT IS ITER?
** ================================================================
** Iter is a template function that:
** 1. Takes an array (pointer to first element)
** 2. Takes the length of that array
** 3. Takes a function to call on each element
** 4. Calls that function on every element in the array
**
** This is similar to:
** - JavaScript's array.forEach(callback)
** - Python's for loop: for item in array: callback(item)
** - Functional programming concepts
**
** WHY IS THIS USEFUL?
** - Separates data (array) from operations (what to do with each element)
** - Enables code reuse: same iter works with different callbacks
** - Foundation for more advanced concepts (STL algorithms like std::for_each)
**
** HOW DOES IT USE FUNCTION POINTERS (from CPP01)?
** ================================================================
** From CPP01, we learned:
** - A function has an address in memory
** - We can store that address in a pointer: void (*func_ptr)(int)
** - We can pass function pointers as parameters
** - We can call the function through the pointer: (*func_ptr)(42)
**
** ITER USES THIS: the third parameter is a function to apply to each element
**
** TEMPLATE IN ITER:
** We make it a template because:
** - Array could be int[], float[], string[], or any custom type
** - The function's parameter type must match the array element type
** - One template works for all types!
**
** EXAMPLE USAGE:
** int array[3] = {1, 2, 3};
** iter(array, 3, &my_function);  // calls my_function(1), my_function(2), my_function(3)
**
** FUNCTION POINTER vs TEMPLATE FUNCTION:
** - Can pass regular functions: &regular_function
** - Can pass instantiated template functions: &template_function<int>
** Both work because they have the same signature (type of function)
*/

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/*
** ITER FUNCTION TEMPLATE:
**
** PURPOSE: Apply a function to every element in an array
**
** TEMPLATE PARAMETERS:
** - T: the type of array elements (int, float, std::string, etc.)
**
** FUNCTION PARAMETERS:
** - T array[]: the array to iterate over (actually a pointer to T)
**   In C++, T array[] parameter is equivalent to T* array
**   Syntax: T array[] shows intent better ("this is an array")
**
** - size_t length: number of elements in the array
**   size_t is unsigned integer type (from CPP00-01)
**   Used for array sizes because negative sizes don't make sense
**   From <cstddef> header (included by most headers)
**
** - void (*func)(T): a function pointer that takes one T parameter and returns void
**   void: function returns nothing
**   (*func): this is a function pointer (the * and () indicate "pointer to function")
**   (T): the function takes one parameter of type T
**
** FUNCTION POINTER SYNTAX EXPLANATION:
** Regular function declaration: void my_func(int x);
** Function pointer declaration: void (*func_ptr)(int);
**
** Reading right-to-left:
** - func_ptr: is a...
** - (*...): pointer to a...
** - void (...): function returning void
** - (int): that takes int parameter
**
** The parentheses are critical!
** - void *func_ptr(int) means: func_ptr returns a pointer to void (WRONG)
** - void (*func_ptr)(int) means: func_ptr IS a pointer to function (CORRECT)
**
** RETURN TYPE: void (nothing)
** We don't return anything - the callback function modifies data
** or produces side effects (like printing)
**
** C++98 COMPATIBILITY:
** This syntax works in C++98
** In C++11+, we could use std::function or lambda functions
** But we stick with C++98 function pointers for compatibility
*/
template <typename T>
void iter(T array[], size_t length, void (*func)(T))
{
	/*
	** LOOP through each element of the array
	**
	** LOOP STRUCTURE:
	** for (initialization; condition; increment)
	**
	** size_t i = 0: Start at element 0
	** Why size_t? It matches the length parameter type
	** Should be unsigned (array indices can't be negative)
	**
	** i < length: Continue while i is less than array length
	** This is the standard "for each element" pattern
	**
	** i++: After each iteration, move to next element
	** Equivalent to: i = i + 1
	*/
	for (size_t i = 0; i < length; i++)
	{
		/*
		** Call the function on the current element
		** func: the function pointer we received as parameter
		** (*func): dereference the pointer to call the function
		** array[i]: the current element
		**
		** EXAMPLE:
		** If func points to a function that prints integers,
		** and array[0] = 42,
		** then (*func)(array[i]) calls that function with 42
		**
		** WHY DEREFERENCE (*func)?
		** - func is a pointer (address of a function in memory)
		** - (*func) gets the function itself
		** - (*func)(array[i]) calls that function
		**
		** ALTERNATE SYNTAX:
		** func(array[i]) also works! (C++ allows both)
		** Compiler treats func(x) same as (*func)(x) for function pointers
		** But (*func) makes the pointer dereference explicit
		*/
		(*func)(array[i]);
	}
}

/*
** UNDERSTANDING TEMPLATE INSTANTIATION HERE:
** ================================================================
**
** When we call: iter(int_array, 3, &int_function);
** Compiler generates: void iter<int>(int array[], size_t length, void (*func)(int))
**
** When we call: iter(float_array, 2, &float_function);
** Compiler generates: void iter<float>(float array[], size_t length, void (*func)(float))
**
** The function pointer type changes with the template!
** For int arrays: takes void (*func)(int)
** For float arrays: takes void (*func)(float)
** For string arrays: takes void (*func)(std::string)
**
** This is the power of templates: type safety automatically!
** You CAN'T accidentally pass a function expecting int to an iter<float>
** Compiler will reject it with a type mismatch error
**
** GENERIC PROGRAMMING PATTERN:
** This is a classic higher-order function (function taking function parameter)
** Combined with templates = very powerful and reusable code
*/

#endif // ITER_HPP

/*
** COMPARISON: iter vs. std::for_each (from STL, learned in later modules)
** ================================================================
**
** std::for_each (C++98 STL algorithm):
** - Does the same thing as iter
** - Takes iterators instead of array pointer and length
** - Can take function objects (objects with operator()) in addition to function pointers
** - More flexible but also more complex
**
** Our iter is simpler and demonstrates:
** - Core concept without STL complexity
** - How templates enable generic algorithms
** - How function pointers work with templates
**
** LEARNING VALUE:
** Understanding iter helps you understand std::for_each later
** Both are based on the same principle: apply operation to each element
*/
