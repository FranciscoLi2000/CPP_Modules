/*
** TEACHING FILE - CPP07 ex02: Array class template
**
** LEARNING PROGRESSION:
** - CPP00: Basic C++ classes, constructors, destructors
** - CPP01: Pointers, references, dynamic memory (new/delete)
** - CPP02: Orthodox Canonical Form (OCF): default constructor, copy constructor, operator=, destructor
** - CPP03: Inheritance and polymorphism
** - CPP04: Abstract classes
** - CPP05: Exception handling with try/catch/throw
** - CPP06: Type casting
** - CPP07: Templates - HERE - Class templates combining all previous knowledge!
**
** WHAT IS ARRAY CLASS TEMPLATE?
** ================================================================
** A generic, type-safe, bounds-checked dynamic array that:
** 1. Works with ANY type (int, float, string, custom classes)
** 2. Grows when constructed with a size
** 3. Provides bounds checking (throws exception if out of bounds)
** 4. Implements full OCF for proper memory management
** 5. Supports copy constructor and assignment operator
**
** WHY CLASS TEMPLATES (not just function templates)?
** - Need to maintain state (the array and its size)
** - Need multiple member functions (constructor, destructor, operator[])
** - Function templates (ex00, ex01) are stateless utilities
** - Class templates manage resources and encapsulate behavior
**
** COMPARISON TO ARRAYS YOU ALREADY KNOW:
** - C-style arrays (int arr[10]): fixed size, on stack, no bounds checking
** - C++ built-in arrays (int* arr = new int[10]): dynamic, on heap, manual cleanup
** - std::vector (from CPP08+): dynamic, with STL algorithms, more complex
** - Our Array template: custom implementation, learns all concepts!
**
** KEY CONCEPTS INTEGRATED:
** 1. TEMPLATES: type parameter T works for any type
** 2. OCF (from CPP02): proper construction/destruction/copying
** 3. DYNAMIC MEMORY (from CPP01): new[]/delete[] for array storage
** 4. EXCEPTIONS (from CPP05): throw std::exception for out of bounds
** 5. OPERATOR OVERLOADING (from CPP02): operator[] for array access
** 6. CONST CORRECTNESS (from CPP00-01): const methods, const parameters
**
** DESIGN CHOICES EXPLAINED:
** - Store elements with new T[size], not new T* or std::vector
** - Constructor with unsigned int (sizes can't be negative)
** - size() method returns size_t (standard for sizes)
** - operator[] throws std::exception on out of bounds (not silent undefined behavior)
** - Deep copy in copy constructor and operator= (not shared ownership)
** - No move semantics (C++98 doesn't have std::move)
*/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstddef>

/*
** CLASS TEMPLATE DECLARATION:
**
** template <typename T>
** class ClassName { ... }
**
** TEMPLATE PARAMETER:
** - typename T: represents ANY type
** - Will be replaced at compile time when class is instantiated
** - Example: Array<int> generates Array with T=int
**           Array<std::string> generates Array with T=std::string
**
** TEMPLATE INSTANTIATION:
** When you write: Array<int> myArray;
** Compiler generates: entire class with T replaced by int
** When you write: Array<float> otherArray;
** Compiler generates: different class with T replaced by float
** Each is a completely independent class!
*/
template <typename T>
class Array
{
	/*
	** PRIVATE SECTION (from CPP02 - encapsulation):
	** Members that can't be accessed from outside the class
	** Only the class itself can modify these
	*/
	private:
		/*
		** MEMBER VARIABLE: _data
		**
		** PURPOSE: Pointer to dynamically allocated array
		**
		** TYPE: T*
		** - T*: pointer to type T
		** - Could be int*, float*, std::string*, or any T*
		** - Actually points to an array (T[]), not single T
		**
		** WHY DYNAMIC (new)?
		** - Size determined at runtime, not compile time
		** - Stack has limited size; don't want big arrays on stack (from CPP01)
		** - Heap allows large allocations
		**
		** WHY NAME STARTS WITH _?
		** - Convention to distinguish member variables from local variables
		** - _data is clearly a member; data could be anything
		** - Some coding styles use _data_ or data_ instead
		** - Important for code readability
		**
		** INITIALIZATION:
		** Set to NULL in constructor (before allocating)
		** Allocated in constructor with new T[size]
		** Freed in destructor with delete[] _data
		*/
		T* _data;
		
		/*
		** MEMBER VARIABLE: _size
		**
		** PURPOSE: Store the number of elements in the array
		**
		** TYPE: size_t
		** - size_t: unsigned integer type for sizes
		** - From C++ standard library (<cstddef>)
		** - Standard type for array/container sizes
		** - Can't be negative (unsigned ensures this)
		** - Large enough for any array size on the system
		**
		** WHY NOT int OR unsigned int?
		** - size_t is semantically correct for sizes
		** - size_t matches size() return type (consistency)
		** - size_t matches new T[size] requirement (type safety)
		**
		** INITIALIZATION:
		** Set to 0 in default constructor (empty array)
		** Set to n in sized constructor
		** Never modified after construction (immutable after creation)
		*/
		size_t _size;
		
	/*
	** PUBLIC SECTION (from CPP02):
	** Members that can be accessed from outside the class
	** This is the interface the user sees
	*/
	public:
		/*
		** CONSTRUCTOR 1: Default constructor (no parameters)
		**
		** PURPOSE: Create an empty array with no elements
		**
		** ORTHODOX CANONICAL FORM (from CPP02):
		** Every class needs a default constructor
		** Even if not explicitly used, compiler may call it
		**
		** IMPLEMENTATION:
		** Initialize _data to NULL (no allocation yet)
		** Initialize _size to 0 (no elements)
		**
		** WHY NULL AND NOT UNINITIALIZED?
		** - If someone accidentally calls operator[], we can check for NULL
		** - Safer than undefined behavior
		** - Makes destructor safe (delete[] NULL is safe)
		**
		** DECLARATION (in header):
		** Array();
		**
		** IMPLEMENTATION (in .cpp or .tpp):
		** template <typename T>
		** Array<T>::Array() : _data(NULL), _size(0) {}
		**
		** What are these colon initializers?
		** These are MEMBER INITIALIZER LISTS (from CPP02)
		** - Set member variables BEFORE constructor body runs
		** - For simple types like T*, this is efficient
		** - More efficient than: _data = NULL; in constructor body
		** - REQUIRED for const members and references
		*/
		Array();
		
		/*
		** CONSTRUCTOR 2: Sized constructor (one parameter)
		**
		** PURPOSE: Create an array with n elements initialized to default values
		**
		** PARAMETER:
		** - unsigned int n: number of elements to allocate
		**   unsigned: sizes can't be negative
		**   int: from the specification (though size_t would be better)
		**
		** BEHAVIOR:
		** 1. Allocate memory for n elements: new T[n]
		** 2. Store the size in _size
		** 3. Elements are initialized to default values:
		**    - int: 0
		**    - float: 0.0
		**    - std::string: empty string ""
		**    - Custom class: default constructor called for each
		**
		** MEMORY ALLOCATION:
		** new T[n] does:
		** 1. Allocates memory for n consecutive T objects
		** 2. Calls default constructor of T for each element (if T is a class)
		** 3. Returns pointer to first element
		**
		** NEW T[] VS NEW T:
		** - new T[n]: allocates array, calls constructor for each element
		** - new T: allocates single element, calls constructor
		** - MUST use delete[] for arrays (not delete)
		** - MUST use delete for single elements (not delete[])
		**
		** EXAMPLE: Array<int> arr(5);
		** 1. new int[5] allocates 5 integers on heap
		** 2. Integers are zero-initialized (int rule)
		** 3. _data points to first int
		** 4. _size = 5
		**
		** TIP FROM PDF:
		** "Try to compile int * a = new int(); then display *a."
		** Result: displays 0 (default initialization of int)
		** This demonstrates that new int() initializes to 0
		*/
		Array(unsigned int n);
		
		/*
		** COPY CONSTRUCTOR (from CPP02 OCF)
		**
		** PURPOSE: Create a new Array as a DEEP COPY of another Array
		**
		** PARAMETER:
		** - const Array<T>& other: const reference to another Array
		**   const: we won't modify the source array
		**   reference: avoid copying the entire array to pass it (from CPP01)
		**   <T>: template parameter must match exactly
		**
		** ORTHODOX CANONICAL FORM (from CPP02):
		** Every class should have a copy constructor
		** Especially critical for classes managing dynamic resources
		**
		** BEHAVIOR: DEEP COPY (not shallow copy!)
		** 1. Get size from other array
		** 2. Allocate new memory for our elements (not share other's memory!)
		** 3. Copy each element from other's array to our array
		** 4. Now both arrays are independent
		** 5. Modifying one doesn't affect the other
		**
		** WHY DEEP COPY?
		** If we did shallow copy (just copy the pointer):
		** - Both arrays would point to same memory
		** - Delete the first array: destructor calls delete[] _data
		** - Second array's _data becomes dangling pointer (memory freed!)
		** - Accessing second array causes undefined behavior / crash
		**
		** SHALLOW COPY DISASTER (what NOT to do):
		** Array<int> arr1(5);
		** Array<int> arr2 = arr1;  // Shallow copy: arr2._data = arr1._data
		** delete arr1;             // Calls delete[] _data
		** arr2[0] = 5;             // CRASH! Memory already freed!
		**
		** DEEP COPY SAFETY (what we do):
		** Array<int> arr1(5);
		** Array<int> arr2 = arr1;  // Deep copy: allocate new memory, copy elements
		** delete arr1;             // Calls delete[] on arr1._data only
		** arr2[0] = 5;             // OK! arr2 has its own memory
		**
		** DECLARATION:
		** Array(const Array<T>& other);
		**
		** IMPLEMENTATION PSEUDOCODE:
		** template <typename T>
		** Array<T>::Array(const Array<T>& other) : _size(other._size)
		** {
		**     _data = new T[_size];         // Allocate new memory
		**     for (size_t i = 0; i < _size; i++)
		**         _data[i] = other._data[i]; // Copy each element
		** }
		*/
		Array(const Array<T>& other);
		
		/*
		** ASSIGNMENT OPERATOR (from CPP02 OCF)
		**
		** PURPOSE: Assign one Array to another (after both are constructed)
		**
		** PARAMETERS:
		** - const Array<T>& other: const reference to source array
		**
		** RETURN TYPE: Array<T>&
		** - Return reference to *this
		** - Allows chaining: a = b = c;
		** - Reference to this object (modified)
		**
		** DIFFERENCE FROM COPY CONSTRUCTOR:
		** Copy constructor: creates NEW object (called with initialization)
		**   Array<int> a = b;          // Copy constructor
		**   Array<int> a(b);           // Copy constructor
		**
		** Assignment operator: modifies EXISTING object (called with =)
		**   Array<int> a(3);
		**   Array<int> b(5);
		**   a = b;                     // Assignment operator
		**
		** IMPLEMENTATION:
		** Must handle self-assignment (a = a should work)
		** 1. Check if other is the same object (this == &other)
		** 2. If same: do nothing, return *this
		** 3. If different:
		**    - Delete old memory (_data and _size)
		**    - Allocate new memory
		**    - Copy elements from other
		**    - Set new size
		**    - Return *this
		**
		** WHY CHECK FOR SELF-ASSIGNMENT?
		** Without check:
		** a = a;
		** 1. Delete old _data (oops, that's a._data)
		** 2. Try to read from deleted memory to copy
		** 3. Undefined behavior / crash
		**
		** DECLARATION:
		** Array<T>& operator=(const Array<T>& other);
		**
		** IMPLEMENTATION PSEUDOCODE:
		** template <typename T>
		** Array<T>& Array<T>::operator=(const Array<T>& other)
		** {
		**     if (this != &other)              // Self-assignment check
		**     {
		**         delete[] _data;              // Free old memory
		**         _size = other._size;
		**         _data = new T[_size];        // Allocate new memory
		**         for (size_t i = 0; i < _size; i++)
		**             _data[i] = other._data[i]; // Copy elements
		**     }
		**     return (*this);                  // Return reference to this object
		** }
		*/
		Array<T>& operator=(const Array<T>& other);
		
		/*
		** DESTRUCTOR (from CPP02 OCF)
		**
		** PURPOSE: Clean up allocated memory when Array is destroyed
		**
		** ORTHODOX CANONICAL FORM (from CPP02):
		** Must free any dynamically allocated memory
		** Called automatically when object goes out of scope
		**
		** IMPLEMENTATION:
		** 1. Check if _data is not NULL
		** 2. If not NULL, call delete[] _data to free memory
		** 3. Set _data to NULL (paranoid, but good practice)
		** 4. Don't need to delete[] _size (it's an integer, not allocated)
		**
		** WHY delete[] AND NOT delete?
		** - _data was allocated with new T[size]
		** - MUST delete with matching delete[]
		** - new/delete is for single objects
		** - new[]/delete[] is for arrays
		** - Mixing them causes crashes or memory corruption!
		**
		** WHY CHECK FOR NULL?
		** delete[] NULL is safe (standard says so)
		** But checking makes intent clear in code
		**
		** WHEN IS DESTRUCTOR CALLED?
		** 1. Stack objects: when going out of scope
		**    {
		**        Array<int> a(5);  // Constructor called
		**    }  // Destructor called here
		**
		** 2. Heap objects: when delete is called
		**    Array<int>* a = new Array<int>(5);
		**    delete a;  // Destructor called before memory freed
		**
		** 3. Array elements: when parent array destroyed
		**    Array<Array<int>> a(3);  // Creates 3 Arrays
		**    // When a destroyed, destructor called for each element
		**
		** VIRTUAL DESTRUCTORS:
		** Only make destructor virtual if class is base class (CPP03)
		** For final concrete classes like this, virtual not needed
		**
		** DECLARATION:
		** ~Array();
		**
		** IMPLEMENTATION PSEUDOCODE:
		** template <typename T>
		** Array<T>::~Array()
		** {
		**     delete[] _data;  // Free heap memory
		**     _data = NULL;    // Optional: prevent dangling pointer
		** }
		*/
		~Array();
		
		/*
		** OPERATOR[] - SUBSCRIPT OPERATOR (from CPP02)
		**
		** PURPOSE: Access array elements like built-in arrays
		**
		** TWO VERSIONS:
		** 1. operator[](size_t i): non-const, can modify elements
		** 2. const operator[](size_t i) const: const, read-only access
		**
		** NON-CONST VERSION:
		** T& operator[](size_t index);
		** - Returns reference to element at index
		** - Can be used on left side of assignment: a[0] = 5;
		** - Can modify the element: a[0] += 1;
		** - Caller can modify the array
		**
		** CONST VERSION:
		** T operator[](size_t index) const;
		** - Called when accessing elements of const Array
		** - Returns element VALUE (or const reference)
		** - Can't be used on left side of assignment
		** - Can only read elements: x = a[0];
		** - Caller can't modify the array
		**
		** BOUNDS CHECKING:
		** Unlike C arrays, check if index is valid
		** If index >= _size: throw std::exception
		** This prevents silent buffer overflows
		**
		** EXCEPTION HANDLING (from CPP05):
		** throw std::exception();
		** - Creates exception object and throws it
		** - Calling code can catch it with try/catch
		** - If not caught, program terminates
		**
		** PARAMETER:
		** - size_t index: which element to access
		**   size_t: unsigned, so can't be negative
		**   (C++ prevents negative indices at compile time for size_t)
		**
		** DECLARATION:
		** T& operator[](size_t index);
		** T operator[](size_t index) const;
		**
		** USAGE:
		** Array<int> a(5);
		** a[0] = 10;           // Non-const version
		** std::cout << a[0];   // Could use either (non-const version used)
		** 
		** const Array<int>& b = a;
		** std::cout << b[0];   // Const version
		** b[0] = 10;           // COMPILE ERROR - can't modify const
		** std::cout << b[10];  // Throws exception - index out of bounds
		**
		** IMPLEMENTATION PSEUDOCODE:
		** template <typename T>
		** T& Array<T>::operator[](size_t index)
		** {
		**     if (index >= _size)
		**         throw std::exception();
		**     return _data[index];
		** }
		**
		** template <typename T>
		** T Array<T>::operator[](size_t index) const
		** {
		**     if (index >= _size)
		**         throw std::exception();
		**     return _data[index];
		** }
		*/
		T& operator[](size_t index);
		T operator[](size_t index) const;
		
		/*
		** size() MEMBER FUNCTION (from CPP00)
		**
		** PURPOSE: Return the number of elements in the array
		**
		** RETURN TYPE: size_t
		** - size_t is standard for sizes
		** - Consistent with standard library containers
		**
		** PARAMETERS: None
		** - No input needed; return member _size
		**
		** CONST CORRECTNESS:
		** const keyword at end means: this function doesn't modify the object
		** Can call on const Array objects
		** Must use on const objects (compiler enforces)
		**
		** EXAMPLE USAGE:
		** Array<int> a(5);
		** std::cout << a.size();  // Outputs 5
		**
		** const Array<int>& b = a;
		** std::cout << b.size();  // OK - const function
		**
		** DECLARATION:
		** size_t size() const;
		**
		** IMPLEMENTATION PSEUDOCODE:
		** template <typename T>
		** size_t Array<T>::size() const
		** {
		**     return _size;
		** }
		*/
		size_t size() const;
};

/*
** TEMPLATE DEFINITION IN .TPP FILE?
** ================================================================
** This header file declares the class template
** But where is the implementation?
**
** Three options:
** 1. Implement directly in header (less clean)
** 2. Implement in separate .tpp file and #include at end (clean!)
** 3. Have both .hpp and .cpp (doesn't work for templates!)
**
** We use option 2 (include .tpp at end)
** The .tpp file has all the implementation code
** It's #included here so compiler sees it in every translation unit
**
** NOTE: The .tpp file should NOT have #include guards
** It's included by .hpp, which already has guards
*/

/*
** INCLUDE THE TEMPLATE IMPLEMENTATION:
** This must come AFTER the class declaration
** Compiler needs to see both declaration and implementation
*/
#include "Array.tpp"

#endif // ARRAY_HPP
