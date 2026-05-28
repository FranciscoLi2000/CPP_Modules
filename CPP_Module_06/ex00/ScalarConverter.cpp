/*
** TEACHING FILE - ScalarConverter.cpp Implementation
** 
** LEARNING GOALS:
** 1. Understanding static_cast for numeric type conversions
** 2. String parsing and validation
** 3. Handling special floating point values (inf, nan)
** 4. Detecting overflow and impossible conversions
** 5. Proper error handling without exceptions (following C++98 constraints)
*/

#include "ScalarConverter.hpp"

/*
** PRIVATE CONSTRUCTOR IMPLEMENTATION:
** Empty implementation - just prevents instantiation
*/
ScalarConverter::ScalarConverter() {}

/*
** COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR:
** Empty implementations - never called due to private access
*/
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) { return *this; }

/*
** DESTRUCTOR:
** Empty implementation for explicit private destructor
*/
ScalarConverter::~ScalarConverter() {}

/*
** HELPER FUNCTION: detectLiteralType
** 
** PURPOSE: Determine what type the input string represents
**
** RETURN VALUES:
** 'c' = char literal (e.g., 'a', 'c', '0')
** 'i' = int literal (e.g., 0, -42, 2147483647)
** 'f' = float literal (e.g., 1.5f, -inf, nanf)
** 'd' = double literal (e.g., 1.5, -inf, nan)
** 'x' = unknown/invalid
**
** LEARNING POINT:
** This demonstrates string parsing - a critical skill in C++
** We parse character by character to identify patterns
*/
static char detectLiteralType(const std::string &literal)
{
	/*
	** CHAR LITERAL DETECTION:
	** Format: 'c' where c is a single character
	** Examples: 'a', '0', ' ', '\0'
	**
	** LOGIC:
	** - Check if length is exactly 3
	** - Check if first and last characters are single quotes
	*/
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return 'c';

	/*
	** SPECIAL FLOAT VALUES:
	** Format: -inff, +inff, nanf
	** 
	** WHY SPECIAL HANDLING?
	** - These are valid float literals in C++
	** - They represent special IEEE 754 floating point values
	** - Must be detected before general number parsing
	*/
	if (literal == "-inff" || literal == "+inff" || literal == "-inf" || literal == "+inf")
		return (literal[literal.length() - 1] == 'f') ? 'f' : 'd';
	
	if (literal == "nanf" || literal == "nan")
		return (literal[literal.length() - 1] == 'f') ? 'f' : 'd';

	/*
	** FLOAT LITERAL DETECTION:
	** Must end with 'f' suffix
	** Examples: 1.5f, -42.0f, 0.0f
	**
	** LOGIC:
	** - Check if last character is 'f'
	** - Check if rest is a valid number (can contain: digits, +, -, .)
	*/
	if (literal.length() > 1 && literal[literal.length() - 1] == 'f')
	{
		std::string num = literal.substr(0, literal.length() - 1);
		bool valid = true;
		bool hasDot = false;
		
		/*
		** PARSE FLOAT CONTENT:
		** - Allow one optional '+' or '-' at start
		** - Allow digits 0-9
		** - Allow exactly one decimal point '.'
		*/
		for (size_t i = 0; i < num.length(); i++)
		{
			char c = num[i];
			if ((c == '+' || c == '-') && i != 0)
				valid = false;
			else if (c == '.')
			{
				if (hasDot)
					valid = false;
				hasDot = true;
			}
			else if (c < '0' || c > '9')
				valid = false;
		}
		
		if (valid && hasDot)
			return 'f';
	}

	/*
	** DOUBLE LITERAL DETECTION:
	** No 'f' suffix, but has decimal point
	** Examples: 1.5, -42.0, 0.0
	**
	** PARSE LOGIC:
	** - Allow one optional '+' or '-' at start
	** - Allow digits 0-9
	** - Allow exactly one decimal point '.'
	*/
	{
		bool hasDot = false;
		bool valid = true;
		
		for (size_t i = 0; i < literal.length(); i++)
		{
			char c = literal[i];
			if ((c == '+' || c == '-') && i != 0)
				valid = false;
			else if (c == '.')
			{
				if (hasDot)
					valid = false;
				hasDot = true;
			}
			else if (c < '0' || c > '9')
				valid = false;
		}
		
		if (valid && hasDot)
			return 'd';
	}

	/*
	** INT LITERAL DETECTION:
	** Just digits with optional +/- prefix
	** Examples: 42, -1, 0, +99
	**
	** PARSE LOGIC:
	** - Allow one optional '+' or '-' at start
	** - All remaining characters must be digits 0-9
	*/
	{
		bool valid = true;
		
		for (size_t i = 0; i < literal.length(); i++)
		{
			char c = literal[i];
			if ((c == '+' || c == '-') && i != 0)
				valid = false;
			else if (c < '0' || c > '9')
				valid = false;
		}
		
		if (valid && literal.length() > 0)
			return 'i';
	}

	/* If nothing matched, it's invalid */
	return 'x';
}

/*
** MAIN CONVERT METHOD:
** 
** EXECUTION FLOW:
** 1. Detect input type
** 2. Parse input value
** 3. Convert to all 4 types (char, int, float, double)
** 4. Handle overflow/impossible conversions
** 5. Output results
**
** KEY LEARNING - WHY STATIC_CAST?
** - Explicit intent: programmer says "I know what I'm doing"
** - Compile-time checked: won't allow dangerous conversions
** - Not like C-style (int)3.14 which is implicit and unclear
** - Exactly what CPP06 is teaching: proper C++ casting
*/
void ScalarConverter::convert(const std::string &literal)
{
	char type = detectLiteralType(literal);

	/* VARIABLE DECLARATIONS with initial "impossible" values */
	double doubleValue = 0.0;
	float floatValue = 0.0f;
	int intValue = 0;
	char charValue = 0;
	
	/* Track conversion validity */
	bool isCharPossible = false;
	bool isIntPossible = false;
	bool isFloatPossible = false;
	bool isDoublePossible = false;

	/*
	** CHAR INPUT HANDLING:
	** Example input: 'a', 'Z', '0'
	** 
	** LEARNING POINT:
	** - Extract the character from quotes
	** - Char is basically a number 0-255 in C++
	** - Use static_cast to convert safely
	*/
	if (type == 'c')
	{
		charValue = literal[1];
		isCharPossible = true;
		
		/* Convert char to int using static_cast */
		intValue = static_cast<int>(charValue);
		isIntPossible = true;
		
		/* Convert char to floating point */
		floatValue = static_cast<float>(charValue);
		isFloatPossible = true;
		
		doubleValue = static_cast<double>(charValue);
		isDoublePossible = true;
	}
	/*
	** FLOAT INPUT HANDLING:
	** Example input: 3.14f, -inff, nanf
	**
	** WHY TRY-CATCH NOT USED?
	** - CPP98 and this module avoid exceptions where possible
	** - strtof() doesn't throw exceptions, it just converts what it can
	** - C++98 constraint: can't rely on modern exception handling
	*/
	else if (type == 'f')
	{
		/* strtof: convert C string to float */
		char *endptr;
		floatValue = strtof(literal.c_str(), &endptr);
		isFloatPossible = true;

		/* Check if full string was consumed */
		/* In CPP98, we skip this check for inf/nan special values */
		
		/* Convert float to double using static_cast */
		doubleValue = static_cast<double>(floatValue);
		isDoublePossible = true;

		/* 
		** FLOAT TO INT CONVERSION:
		** Check for overflow first before attempting cast
		**
		** WHY CHECK FIRST?
		** - If float > INT_MAX, static_cast behavior is undefined
		** - NaN and Inf comparisons always return false
		** - Must check explicitly before casting
		*/
		if (!std::isnan(floatValue) && !std::isinf(floatValue))
		{
			/* Check if value fits in int range */
			if (floatValue >= static_cast<float>(std::numeric_limits<int>::min()) &&
				floatValue <= static_cast<float>(std::numeric_limits<int>::max()))
			{
				intValue = static_cast<int>(floatValue);
				isIntPossible = true;
			}
		}

		/*
		** FLOAT TO CHAR CONVERSION:
		** 
		** WHAT WE CHECK:
		** 1. Not NaN (always impossible)
		** 2. Not infinity (always impossible)
		** 3. Within range 0-127 (printable ASCII) or 0-255 (extended ASCII)
		** 4. When cast to int, falls in char range
		**
		** WHY ALL THESE CHECKS?
		** - NaN and Inf are not representable as int or char
		** - Char typically represents 0-127 (or 0-255 unsigned)
		** - Overflow would give undefined behavior
		*/
		if (!std::isnan(floatValue) && !std::isinf(floatValue))
		{
			if (floatValue >= 0 && floatValue <= 127)
			{
				int temp = static_cast<int>(floatValue);
				charValue = static_cast<char>(temp);
				isCharPossible = true;
			}
		}
	}
	/*
	** DOUBLE INPUT HANDLING:
	** Example input: 3.14, -inf, nan
	** 
	** LOGIC: Almost identical to float handling
	** Main difference: uses strtod instead of strtof
	*/
	else if (type == 'd')
	{
		char *endptr;
		doubleValue = strtod(literal.c_str(), &endptr);
		isDoublePossible = true;

		/* Convert double to float using static_cast */
		floatValue = static_cast<float>(doubleValue);
		isFloatPossible = true;

		/* Double to int conversion with overflow check */
		if (!std::isnan(doubleValue) && !std::isinf(doubleValue))
		{
			if (doubleValue >= static_cast<double>(std::numeric_limits<int>::min()) &&
				doubleValue <= static_cast<double>(std::numeric_limits<int>::max()))
			{
				intValue = static_cast<int>(doubleValue);
				isIntPossible = true;
			}
		}

		/* Double to char conversion with range check */
		if (!std::isnan(doubleValue) && !std::isinf(doubleValue))
		{
			if (doubleValue >= 0 && doubleValue <= 127)
			{
				int temp = static_cast<int>(doubleValue);
				charValue = static_cast<char>(temp);
				isCharPossible = true;
			}
		}
	}
	/*
	** INT INPUT HANDLING:
	** Example input: 42, -1, 0
	**
	** CONVERSION LOGIC:
	** - String to int using strtol (safe parsing)
	** - Then convert int to other types
	*/
	else if (type == 'i')
	{
		char *endptr;
		long longValue = strtol(literal.c_str(), &endptr, 10);

		/* Check for overflow - if value doesn't fit in int */
		if (longValue >= static_cast<long>(std::numeric_limits<int>::min()) &&
			longValue <= static_cast<long>(std::numeric_limits<int>::max()))
		{
			intValue = static_cast<int>(longValue);
			isIntPossible = true;

			/* Int to float conversion using static_cast */
			floatValue = static_cast<float>(intValue);
			isFloatPossible = true;

			/* Int to double conversion using static_cast */
			doubleValue = static_cast<double>(intValue);
			isDoublePossible = true;

			/* Int to char conversion */
			if (intValue >= 0 && intValue <= 127)
			{
				charValue = static_cast<char>(intValue);
				isCharPossible = true;
			}
		}
	}

	/*
	** OUTPUT FORMATTING:
	** 
	** FORMAT RULES:
	** - char: print character if displayable, else "Non displayable"
	** - int: print integer value or "impossible"
	** - float: print with precision, add 'f' suffix
	** - double: print with precision, no suffix
	**
	** DISPLAYABLE CHARS:
	** - Range: 32 (space) to 126 (~)
	** - These are printable ASCII characters
	*/
	
	/* CHAR OUTPUT */
	std::cout << "char: ";
	if (!isCharPossible)
		std::cout << "impossible" << std::endl;
	else if (charValue < 32 || charValue > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << charValue << "'" << std::endl;

	/* INT OUTPUT */
	std::cout << "int: ";
	if (!isIntPossible)
		std::cout << "impossible" << std::endl;
	else
		std::cout << intValue << std::endl;

	/* FLOAT OUTPUT */
	std::cout << "float: ";
	if (!isFloatPossible)
		std::cout << "impossible" << std::endl;
	else
	{
		/*
		** FLOAT FORMATTING:
		** 
		** WHY .1f FORMAT?
		** - Always show at least 1 decimal place
		** - Makes 1.0f display as "1.0f" not "1f"
		** - Follows C++ convention for float literals
		**
		** SPECIAL VALUES:
		** - inf displays as "inf"
		** - nan displays as "nan"
		** - These are IEEE 754 standard representations
		*/
		std::cout << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
	}

	/* DOUBLE OUTPUT */
	std::cout << "double: ";
	if (!isDoublePossible)
		std::cout << "impossible" << std::endl;
	else
	{
		/* Same formatting as float, but without 'f' suffix for double */
		std::cout << std::fixed << std::setprecision(1) << doubleValue << std::endl;
	}
}
