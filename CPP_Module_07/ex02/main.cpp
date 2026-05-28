/*
** TEACHING FILE - CPP07 ex02: Main test file for Array class template
**
** This file demonstrates all features of the Array class template:
** - Constructors (default and sized)
** - Copy constructor (deep copy)
** - Assignment operator (deep copy)
** - Destructor (cleanup)
** - operator[] (read/write with bounds checking)
** - size() method
**
** CONCEPTS COVERED:
** - CPP02: Orthodox Canonical Form (OCF)
** - CPP01: Dynamic memory, pointers, references
** - CPP05: Exception handling (throw/catch)
** - CPP07: Templates, generic programming
**
** C++ STANDARD: C++98 (no C++11 features)
*/

#include <iostream>
#include <string>
#include "Array.hpp"

/*
** WHAT WILL WE TEST?
** ================================================================
**
** 1. DEFAULT CONSTRUCTOR:
**    Create empty Array with no elements
**
** 2. SIZED CONSTRUCTOR:
**    Create Array with n elements, initialized to default
**
** 3. COPY CONSTRUCTOR:
**    Create copy of existing Array (deep copy)
**
** 4. ASSIGNMENT OPERATOR:
**    Assign one Array to another (deep copy)
**
** 5. OPERATOR[] (READ):
**    Access elements for reading
**
** 6. OPERATOR[] (WRITE):
**    Modify elements
**
** 7. BOUNDS CHECKING:
**    Verify exception thrown for invalid indices
**
** 8. size() METHOD:
**    Get the number of elements
**
** 9. DIFFERENT TYPES:
**    Test with int, float, and std::string
**
** 10. DESTRUCTOR:
**     Automatically cleanup (implicit when we exit scope)
*/

int main(void)
{
	/*
	** TEST 1: DEFAULT CONSTRUCTOR
	** ================================================================
	*/
	std::cout << "=== TEST 1: Default Constructor ===" << std::endl;
	
	/*
	** Create empty Array using default constructor
	** Array<int>() is called implicitly
	** Calls: _data = NULL, _size = 0
	*/
	Array<int> empty;
	
	/*
	** Check size of empty array
	** size() should return 0
	** This confirms default constructor worked
	*/
	std::cout << "Empty array size: " << empty.size() << std::endl;
	/*
	** EXPECTED OUTPUT: Empty array size: 0
	*/
	
	std::cout << std::endl;
	
	/*
	** TEST 2: SIZED CONSTRUCTOR
	** ================================================================
	*/
	std::cout << "=== TEST 2: Sized Constructor ===" << std::endl;
	
	/*
	** Create Array with 5 int elements
	** Calls: new int[5], all elements initialized to 0
	** Stores: _data = pointer to 5 ints, _size = 5
	**
	** DEFAULT INITIALIZATION:
	** new int[5] initializes all to 0 (C++ rule for new[])
	** Not garbage values (would be the case with malloc)
	*/
	Array<int> nums(5);
	
	/*
	** Print initial size
	** Should be 5
	*/
	std::cout << "Created array of 5 elements" << std::endl;
	std::cout << "Size: " << nums.size() << std::endl;
	/*
	** EXPECTED OUTPUT: Size: 5
	*/
	
	/*
	** Access and display elements
	** All should be 0 (default initialized)
	** This demonstrates operator[] works
	*/
	std::cout << "Initial values: ";
	for (size_t i = 0; i < nums.size(); i++)
	{
		/*
		** Access element using operator[]
		** Non-const version since nums is not const
		** Returns reference to element
		*/
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
	/*
	** EXPECTED OUTPUT: Initial values: 0 0 0 0 0
	*/
	
	std::cout << std::endl;
	
	/*
	** TEST 3: ASSIGNMENT (non-const operator)
	** ================================================================
	*/
	std::cout << "=== TEST 3: Assignment (Modify Elements) ===" << std::endl;
	
	/*
	** Modify elements using operator[] on left side of =
	** This is why operator[] returns T& (reference, not value)
	** nums[0] = value is only possible with reference return
	*/
	nums[0] = 10;
	nums[1] = 20;
	nums[2] = 30;
	nums[3] = 40;
	nums[4] = 50;
	
	/*
	** Print modified values
	*/
	std::cout << "After modification: ";
	for (size_t i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
	/*
	** EXPECTED OUTPUT: After modification: 10 20 30 40 50
	*/
	
	std::cout << std::endl;
	
	/*
	** TEST 4: COPY CONSTRUCTOR (Deep Copy)
	** ================================================================
	*/
	std::cout << "=== TEST 4: Copy Constructor (Deep Copy) ===" << std::endl;
	
	/*
	** Create copy of nums
	** Calls copy constructor: Array<int>(const Array<int>& other)
	**
	** WHAT HAPPENS:
	** 1. Allocate new memory: new int[5]
	** 2. Copy each element from nums to copy_nums
	** 3. Both arrays are now independent
	**
	** DEEP COPY VERIFICATION:
	** After this, if we modify nums, copy_nums should NOT be affected
	** This proves they have separate memory
	*/
	Array<int> copy_nums = nums;
	
	/*
	** Verify copy has same size
	*/
	std::cout << "Copy size: " << copy_nums.size() << std::endl;
	/*
	** EXPECTED OUTPUT: Copy size: 5
	*/
	
	/*
	** Verify copy has same values
	*/
	std::cout << "Copy values: ";
	for (size_t i = 0; i < copy_nums.size(); i++)
	{
		std::cout << copy_nums[i] << " ";
	}
	std::cout << std::endl;
	/*
	** EXPECTED OUTPUT: Copy values: 10 20 30 40 50
	*/
	
	/*
	** PROVE IT'S INDEPENDENT (deep copy)
	** Modify original
	*/
	nums[0] = 99;
	
	/*
	** Check copy is unaffected
	*/
	std::cout << "After modifying original[0] = 99:" << std::endl;
	std::cout << "  Original[0]: " << nums[0] << std::endl;
	std::cout << "  Copy[0]: " << copy_nums[0] << std::endl;
	/*
	** EXPECTED OUTPUT:
	** After modifying original[0] = 99:
	**   Original[0]: 99
	**   Copy[0]: 10
	** (NOT 99, proving independent memory)
	*/
	
	std::cout << std::endl;
	
	/*
	** TEST 5: ASSIGNMENT OPERATOR (Deep Copy)
	** ================================================================
	*/
	std::cout << "=== TEST 5: Assignment Operator ===" << std::endl;
	
	/*
	** Create another array (sized constructor)
	*/
	Array<int> assigned(3);
	assigned[0] = 100;
	assigned[1] = 200;
	assigned[2] = 300;
	
	std::cout << "Before assignment:" << std::endl;
	std::cout << "  assigned size: " << assigned.size() << std::endl;
	std::cout << "  assigned values: ";
	for (size_t i = 0; i < assigned.size(); i++)
	{
		std::cout << assigned[i] << " ";
	}
	std::cout << std::endl;
	/*
	** EXPECTED OUTPUT:
	** Before assignment:
	**   assigned size: 3
	**   assigned values: 100 200 300
	*/
	
	/*
	** ASSIGN nums to assigned
	** Calls assignment operator: operator=(const Array<int>&)
	**
	** WHAT HAPPENS:
	** 1. Check for self-assignment (this != &other) - passes
	** 2. Delete old memory of assigned (3 elements)
	** 3. Allocate new memory for 5 elements
	** 4. Copy all values from nums to assigned
	** 5. Return *this
	**
	** AFTER ASSIGNMENT:
	** - assigned now has size 5 (same as nums)
	** - assigned has values 99, 20, 30, 40, 50 (same as nums)
	** - Old values 100, 200, 300 are gone (destroyed)
	*/
	assigned = nums;
	
	std::cout << "After assignment (assigned = nums):" << std::endl;
	std::cout << "  assigned size: " << assigned.size() << std::endl;
	std::cout << "  assigned values: ";
	for (size_t i = 0; i < assigned.size(); i++)
	{
		std::cout << assigned[i] << " ";
	}
	std::cout << std::endl;
	/*
	** EXPECTED OUTPUT:
	** After assignment (assigned = nums):
	**   assigned size: 5
	**   assigned values: 99 20 30 40 50
	** (Note: 99, not 10, because we modified nums[0] earlier)
	*/
	
	std::cout << std::endl;
	
	/*
	** TEST 6: BOUNDS CHECKING WITH EXCEPTION
	** ================================================================
	*/
	std::cout << "=== TEST 6: Bounds Checking (Exception Handling) ===" << std::endl;
	
	/*
	** Create small array for testing
	*/
	Array<int> small(3);
	small[0] = 1;
	small[1] = 2;
	small[2] = 3;
	
	/*
	** TEST VALID ACCESS
	*/
	std::cout << "Valid access:" << std::endl;
	std::cout << "  small[0] = " << small[0] << std::endl;
	std::cout << "  small[2] = " << small[2] << std::endl;
	/*
	** EXPECTED OUTPUT:
	** Valid access:
	**   small[0] = 1
	**   small[2] = 3
	*/
	
	/*
	** TEST INVALID ACCESS (OUT OF BOUNDS)
	** Use try/catch (from CPP05)
	**
	** try: execute code that might throw
	** catch: handle the exception if thrown
	*/
	std::cout << "Testing out of bounds access:" << std::endl;
	try
	{
		/*
		** Try to access index 5 (but array only has 0, 1, 2)
		** This will throw std::exception
		** 
		** operator[](5) checks: if (5 >= 3) throw std::exception();
		** Condition is true, so exception is thrown
		** Normal execution stops here
		** Jump to catch block
		*/
		std::cout << "  Attempting small[5]..." << std::endl;
		small[5] = 99;  // This line won't execute
		std::cout << "  THIS WON'T PRINT (exception thrown)" << std::endl;
	}
	catch (std::exception& e)
	{
		/*
		** Catch block runs when exception is thrown
		** e is the exception object
		** We can use it to get information about the error
		**
		** std::exception::what() returns error message
		** (returns generic message in base std::exception)
		*/
		std::cout << "  CAUGHT EXCEPTION: Array index out of bounds!" << std::endl;
	}
	/*
	** EXPECTED OUTPUT:
	** Testing out of bounds access:
	**   Attempting small[5]...
	**   CAUGHT EXCEPTION: Array index out of bounds!
	*/
	
	std::cout << std::endl;
	
	/*
	** TEST 7: DIFFERENT TYPE (std::string)
	** ================================================================
	*/
	std::cout << "=== TEST 7: Array of Strings ===" << std::endl;
	
	/*
	** Create array of 3 strings
	** Calls: new std::string[3]
	** Each element is default-constructed as empty string ""
	**
	** TEMPLATE INSTANTIATION:
	** This generates: Array<std::string>
	** Completely different from Array<int>!
	** Same code template, different type
	*/
	Array<std::string> words(3);
	
	/*
	** Initialize string elements
	** Using operator[] returns reference to std::string
	** Can assign string values
	*/
	words[0] = "Hello";
	words[1] = "World";
	words[2] = "Templates";
	
	/*
	** Print string array
	*/
	std::cout << "String array:" << std::endl;
	for (size_t i = 0; i < words.size(); i++)
	{
		std::cout << "  [" << i << "] = " << words[i] << std::endl;
	}
	/*
	** EXPECTED OUTPUT:
	** String array:
	**   [0] = Hello
	**   [1] = World
	**   [2] = Templates
	*/
	
	/*
	** COPY STRING ARRAY
	** Demonstrates deep copy works for complex types too
	*/
	Array<std::string> words_copy = words;
	
	/*
	** Modify original
	*/
	words[0] = "Modified";
	
	/*
	** Check copy is unaffected
	*/
	std::cout << "\nAfter modification:" << std::endl;
	std::cout << "  Original[0]: " << words[0] << std::endl;
	std::cout << "  Copy[0]: " << words_copy[0] << std::endl;
	/*
	** EXPECTED OUTPUT:
	** After modification:
	**   Original[0]: Modified
	**   Copy[0]: Hello
	*/
	
	std::cout << std::endl;
	
	/*
	** TEST 8: DIFFERENT TYPE (float)
	** ================================================================
	*/
	std::cout << "=== TEST 8: Array of Floats ===" << std::endl;
	
	/*
	** Create array of 4 floats
	** Calls: new float[4]
	** Each element is default-initialized to 0.0
	*/
	Array<float> floats(4);
	floats[0] = 1.5f;
	floats[1] = 2.7f;
	floats[2] = 3.14f;
	floats[3] = 4.99f;
	
	std::cout << "Float array: ";
	for (size_t i = 0; i < floats.size(); i++)
	{
		std::cout << floats[i] << " ";
	}
	std::cout << std::endl;
	/*
	** EXPECTED OUTPUT: Float array: 1.5 2.7 3.14 4.99
	** (Precision may vary)
	*/
	
	std::cout << std::endl;
	
	/*
	** SUMMARY AND LEARNING
	** ================================================================
	**
	** WHAT WE DEMONSTRATED:
	** 1. Templates work with any type (int, string, float)
	** 2. Deep copy prevents memory sharing issues
	** 3. Bounds checking prevents buffer overflows
	** 4. Exception handling provides error notification
	** 5. OCF (constructor, destructor, copy, assign) is critical
	** 6. Operator overloading makes custom types feel natural
	**
	** CONCEPTS FROM PREVIOUS MODULES:
	** - CPP00: Classes and constructors
	** - CPP01: Pointers, dynamic memory, references
	** - CPP02: OCF, operator overloading, copy semantics
	** - CPP05: Exception handling (try/throw/catch)
	** - CPP07: Generic programming with templates
	**
	** CLASS TEMPLATE PATTERN:
	** template <typename T>
	** class Array { ... }
	** 
	** Same pattern used in Standard Template Library:
	** - std::vector<T>
	** - std::list<T>
	** - std::map<K, V>
	** - std::queue<T>
	** All follow this generic template pattern
	**
	** MEMORY MANAGEMENT:
	** Proper destructors prevent memory leaks
	** Deep copy prevents dangling pointers
	** This is why OCF is non-negotiable (CPP02 lesson)
	**
	** PERFORMANCE:
	** - Stack allocation (Array<int> a;): fast, limited size
	** - Heap allocation (new int[n]): slower, unlimited size
	** - Templates: compile-time, zero overhead
	** - But generates code for each type (code bloat)
	**
	** When main() ends, all objects are destroyed in reverse order:
	** 1. words_copy (~Array<std::string>)
	** 2. words (~Array<std::string>)
	** 3. floats (~Array<float>)
	** 4. small (~Array<int>)
	** 5. assigned (~Array<int>)
	** 6. copy_nums (~Array<int>)
	** 7. nums (~Array<int>)
	** 8. empty (~Array<int>)
	**
	** Each destructor calls delete[] to free memory
	** All memory properly cleaned up, no leaks!
	**
	** THIS IS THE POWER OF RAII:
	** Resource Acquisition Is Initialization
	** Constructors acquire resources (allocate memory)
	** Destructors release resources (free memory)
	** Ensures no leaks, even if exceptions thrown
	*/
	
	return (0);
}

/*
** LEARNING COMPLETE:
** You now understand:
** 1. Class templates - generic classes for any type
** 2. Combining OCF with templates
** 3. Deep copy and memory ownership
** 4. Exception safety in templates
** 5. Operator overloading in templates
** 6. Generic programming pattern used throughout C++
**
** CPP07 COMPLETE!
** You've learned:
** - ex00: Function templates (swap, min, max)
** - ex01: Function templates with callbacks (iter)
** - ex02: Class templates (Array)
**
** NEXT MODULES (CPP08, CPP09):
** - More templates and the Standard Template Library (STL)
** - Iterators, containers, algorithms
** - Advanced template techniques
**
** CONGRATULATIONS on completing CPP07!
** You've mastered the foundation of modern C++.
*/
