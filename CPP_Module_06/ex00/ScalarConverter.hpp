/*
** TEACHING FILE - CPP06 ex00: Scalar Type Conversion
** 
** LEARNING PROGRESSION:
** - CPP00: Basic C++ with classes and constructors
** - CPP01: Pointers, references, memory allocation
** - CPP02: Orthodox Canonical Form (OCF), operator overloading
** - CPP03: Inheritance and polymorphism
** - CPP04: Abstract classes and interfaces  
** - CPP05: Exception handling and custom exceptions
** - CPP06: HERE - C++ casting operators (static_cast, dynamic_cast, const_cast, reinterpret_cast)
**
** THIS EXERCISE TEACHES:
** 1. Static methods and private constructors (preventing instantiation)
** 2. String parsing and type detection
** 3. Using static_cast for safe type conversions
** 4. Handling edge cases: special float/double values (inf, nan), overflow
** 5. Proper C++ design using encapsulation
*/

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <limits>

/*
** ScalarConverter CLASS:
** 
** PURPOSE:
** Convert string representations of C++ scalar literals (char, int, float, double)
** between different scalar types with proper type checking and edge case handling.
**
** WHY STATIC ONLY?
** - This class is a utility/helper class, not meant to represent an object
** - We want to prevent instantiation to enforce correct usage pattern
** - Similar to how std::abs() is static, not a class instance method
**
** CASTING CONCEPT REMINDER (from CPP06):
** - static_cast: Safe cast between related types at compile time
**   Syntax: static_cast<TargetType>(value)
**   Example: static_cast<int>(3.14) converts double to int
**
** - C++ is strongly typed, unlike C where (int)3.14 is allowed
**   static_cast makes the intention explicit and is type-safe
*/
class ScalarConverter
{
	private:
		/*
		** PRIVATE CONSTRUCTOR:
		** 
		** WHY PRIVATE?
		** - Prevents users from creating instances: ScalarConverter converter;
		** - Forces users to use static method: ScalarConverter::convert("42");
		** - This is the "Static Utility Class" design pattern
		**
		** LEARNING FROM PREVIOUS MODULES:
		** - CPP00: Learned about constructors and their purpose
		** - CPP02: Learned about private members and encapsulation (OCF)
		** - CPP06: Now learning static-only classes that prevent instantiation
		*/
		ScalarConverter();

		/*
		** PRIVATE COPY CONSTRUCTOR & ASSIGNMENT OPERATOR:
		** 
		** WHY PRIVATE?
		** - Even though constructor is private, we want to be extra clear
		**   this class should NOT be copied or assigned
		** - Prevents accidental copying if someone tries to bypass constructor restriction
		**
		** LEARNING FROM CPP02 (Orthodox Canonical Form):
		** - Explicitly declaring them private shows intent to forbid copying
		** - Similar to how we deleted move semantics in CPP02 exercises
		*/
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &other);

		/*
		** DESTRUCTOR:
		** Private empty destructor (optional but explicit about intent)
		*/
		~ScalarConverter();

	public:
		/*
		** STATIC CONVERT METHOD:
		**
		** PURPOSE: Main entry point for conversion
		**
		** PARAMETERS:
		** - const std::string& literal: string representation of a scalar
		**   Examples: "42", "42.0f", "'c'", "nan", "-inf"
		**
		** WHY STATIC?
		** - No instance state needed - pure utility function
		** - Called as: ScalarConverter::convert("42")
		** - No need for this pointer
		**
		** FUNCTIONALITY:
		** 1. Detect input type (char, int, float, double, special)
		** 2. Convert to all four types
		** 3. Handle edge cases (overflow, non-displayable chars, special values)
		** 4. Output results in specified format
		**
		** CASTING DECISION:
		** - Uses static_cast for safe type conversions within well-defined ranges
		** - static_cast is safe for numeric types that can be verified at compile time
		** - Ensures program doesn't use old C-style casts like (int)3.14
		*/
		static void convert(const std::string &literal);
};

#endif
