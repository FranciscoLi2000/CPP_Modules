/*
** TEACHING FILE - CPP07 ex02: Array class template implementation
**
** WHY A SEPARATE .TPP FILE?
** ================================================================
** .tpp = "Template Parameterization"
** It's a convention to separate template declarations from implementations
** 
** REASONS FOR .TPP:
** 1. Keeps header file focused on interface (what the class offers)
** 2. Keeps implementation details in separate file (what/how it does)
** 3. Makes code more readable (long headers are hard to navigate)
** 4. Same benefit as .cpp files, but for templates
**
** CRITICAL: This file is #included by .hpp, not compiled separately
** Don't add #ifndef guards (already protected by .hpp)
** Compiler sees template code in every translation unit
**
** TEMPLATE IMPLEMENTATION RULES:
** - Every template member function is "inline" conceptually
** - Compiler generates code for each instantiation
** - File must be visible to compiler (hence included in .hpp)
*/

/*
** DEFAULT CONSTRUCTOR IMPLEMENTATION:
** Array();
**
** PURPOSE: Create an empty array with no elements
**
** MEMBER INITIALIZER LIST:
** : _data(NULL), _size(0)
** 
** These run BEFORE the constructor body
** Initialize member variables to their starting values
** More efficient than assignment in body
** Required for const members and references
**
** WHY THIS ORDER?
** - _data first: it's what will be NULL
** - _size second: size of that empty array is 0
**
** WHY BOTH TOGETHER?
** They must stay consistent:
** If _size is 0, _data must be NULL (no allocation)
** If _data is NULL, _size must be 0 (or undefined behavior)
*/
template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
	/*
	** Constructor body is empty
	** Member initializer list did all the work
	**
	** WHY EMPTY BODY?
	** Nothing more needed after initialization
	** Initializer list is sufficient
	**
	** WHEN WOULD BODY BE NEEDED?
	** If constructor needed to do other work:
	** - Call functions
	** - Perform calculations
	** - Validate inputs
	**
	** For default constructor, just initialization is fine
	*/
}

/*
** SIZED CONSTRUCTOR IMPLEMENTATION:
** Array(unsigned int n);
**
** PURPOSE: Create an array with n elements
** All elements initialized to default values
**
** PARAMETER: unsigned int n
** Number of elements to allocate
** unsigned: sizes can't be negative
**
** IMPLEMENTATION STRATEGY:
** 1. Allocate memory with new T[n]
** 2. Store the size
** 3. Elements are automatically initialized
**
** KEY POINT: new T[n] initializes each element
** For int: initializes to 0
** For float: initializes to 0.0
** For std::string: initializes to empty string
** For custom class: calls default constructor for each
**
** THIS IS IMPORTANT (hint from PDF):
** "Try to compile int * a = new int(); then display *a"
** new int() with parentheses calls default constructor
** For int, default constructor initializes to 0
** Without parentheses, new int would leave uninitialized
** But new T[] always initializes elements
*/
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n)
{
	/*
	** Constructor body is empty
	** Member initializer list did everything:
	** - Allocated memory: new T[n]
	** - Stored size: _size = n
	** 
	** WHY USE INITIALIZER LIST FOR ALLOCATION?
	** Efficient and clean
	** Alternative (not preferred):
	** {
	**     _data = new T[n];
	**     _size = n;
	** }
	**
	** Both work, but initializer list is more idiomatic C++
	** Especially important for const members (can't assign in body)
	*/
}

/*
** COPY CONSTRUCTOR IMPLEMENTATION:
** Array(const Array<T>& other);
**
** PURPOSE: Create a new Array as DEEP copy of another
**
** BEHAVIOR:
** Creates new memory and copies elements
** Original and copy are completely independent
**
** DEEP COPY EXAMPLE:
** Array<int> arr1(3);
** arr1[0] = 10; arr1[1] = 20; arr1[2] = 30;
**
** Array<int> arr2 = arr1;  // Copy constructor called
**
** After this:
** arr1._data points to memory with {10, 20, 30}
** arr2._data points to DIFFERENT memory with {10, 20, 30}
** Modifying arr1[0] = 99 doesn't affect arr2[0]
**
** MEMORY LAYOUT:
** arr1._data ---> [10][20][30]
** arr2._data ---> [10][20][30]  (Different memory!)
**
** If we did shallow copy (WRONG):
** arr1._data ---> [10][20][30]
** arr2._data ------+
** Both point to same memory!
** If arr1 destroyed, arr2._data becomes invalid!
*/
template <typename T>
Array<T>::Array(const Array<T>& other) : _data(new T[other._size]), _size(other._size)
{
	/*
	** Copy elements from other array to new array
	**
	** FOR LOOP EXPLANATION:
	** size_t i = 0: Start at index 0
	** i < _size: Continue while index is valid
	** i++: Move to next element
	**
	** LOOP BODY:
	** _data[i] = other._data[i];
	** Copy each element using operator=
	**
	** WHY ELEMENT BY ELEMENT?
	** Can't use memcpy (type-unsafe, doesn't call operator=)
	** Must use proper copy for complex types
	** For int: works fine, just copies bits
	** For std::string: calls operator= which does proper string copying
	** For custom class: calls operator= which may have custom copy logic
	**
	** GENERIC PROGRAMMING:
	** This single loop works for ANY type T!
	** If T is int, copies ints
	** If T is std::string, copies strings
	** If T is custom class, copies using that class's operator=
	*/
	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
}

/*
** ASSIGNMENT OPERATOR IMPLEMENTATION:
** Array<T>& operator=(const Array<T>& other);
**
** PURPOSE: Assign one Array to another after both constructed
**
** DIFFERENCE FROM COPY CONSTRUCTOR:
** Copy constructor: creates new object
**   Array<int> a = b;   // Copy constructor
**
** Assignment: modifies existing object
**   a = b;               // Assignment operator
**
** CRITICAL POINT: Handle self-assignment (a = a)
** Without self-assignment check:
** a = a;
** 1. Delete _data (which is a's data)
** 2. Try to copy from deleted memory (undefined behavior!)
** 3. Crash or corruption
**
** IMPLEMENTATION STRATEGY:
** 1. Check if this is the same object as other
** 2. If same: return immediately
** 3. If different:
**    - Delete old memory
**    - Allocate new memory
**    - Copy elements
**    - Return reference to this
**
** RETURN TYPE: Array<T>&
** Return reference to allow chaining:
** a = b = c;  // Works because operator= returns reference
*/
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	/*
	** SELF-ASSIGNMENT CHECK:
	**
	** if (this != &other)
	**
	** this: pointer to current object (from CPP00-01)
	** &other: address of the other object
	**
	** If they're the same object: this == &other
	** Then a = a was called, which is a no-op
	** Just return without doing anything
	**
	** WHY THIS CHECK?
	** If we skip this and do:
	** a = a;
	** 1. delete[] _data;  // Deletes a's data!
	** 2. Allocate new memory  // OK
	** 3. Copy from other._data (which we just deleted!)  // CRASH
	**
	** ALTERNATIVE PATTERN:
	** Some code does "copy and swap":
	** 1. Make temporary copy
	** 2. Swap with this
	** 3. Temporary destroyed, old memory freed
	** This is more exception-safe, but more complex
	*/
	if (this != &other)
	{
		/*
		** DELETE OLD MEMORY:
		** delete[] _data;
		**
		** Remove the previously allocated array
		** Make room for new allocation
		**
		** WHY delete[] AND NOT delete?
		** _data was allocated with new T[_size]
		** Must use matching delete[]
		** Using delete (not delete[]) causes undefined behavior
		**
		** WHY NOT CHECK FOR NULL FIRST?
		** delete[] NULL is safe (C++ standard guarantees)
		** Checking is unnecessary but doesn't hurt
		** (Some programmers do it for clarity)
		*/
		delete[] _data;
		
		/*
		** ALLOCATE NEW MEMORY:
		** _data = new T[other._size];
		**
		** Allocate array for the new size
		** If other has 10 elements, allocate 10 Ts
		** If other has 0 elements, this becomes new T[0] (empty but valid)
		**
		** WHY NEW SIZE?
		** We're copying another array, so copy its size
		** Can't reuse old memory if sizes don't match
		**
		** MEMORY FOR DIFFERENT TYPES:
		** new T[5] allocates:
		** - If T=int: 20 bytes (5*4) on typical system
		** - If T=float: 20 bytes (5*4)
		** - If T=std::string: hundreds of bytes (strings are complex)
		** - If T=MyClass: size depends on class members
		**
		** Compiler knows T at instantiation, calculates size
		*/
		_data = new T[other._size];
		
		/*
		** UPDATE SIZE:
		** _size = other._size;
		**
		** Store the new array's size
		** Needed for bounds checking in operator[]
		** And for iteration in loops
		*/
		_size = other._size;
		
		/*
		** COPY ELEMENTS:
		** Same loop as copy constructor
		**
		** Copy each element from other to this
		** Element by element copy with operator=
		** Works for any type T that supports operator=
		*/
		for (size_t i = 0; i < _size; i++)
		{
			_data[i] = other._data[i];
		}
	}
	
	/*
	** RETURN REFERENCE TO THIS:
	** return *this;
	**
	** *this: dereference the this pointer to get reference to object
	** Allows operator chaining:
	** a = b = c;  // operator=(c) returns reference to b, then b is assigned to a
	**
	** WHY RETURN *this NOT this?
	** return *this: returns reference (Array<T>&)
	** return this: returns pointer (Array<T>*)
	** Reference is more idiomatic and conventional
	**
	** WHY RETURN ANYTHING?
	** Allows chaining like C++ operators
	** a = b = c;  // Multiple assignments in one expression
	** Also allows: if ((a = b) == c) { ... }
	**
	** For user code: usually a = b; (no chaining)
	** But STL containers expect operator= to return reference
	*/
	return (*this);
}

/*
** DESTRUCTOR IMPLEMENTATION:
** ~Array();
**
** PURPOSE: Clean up dynamically allocated memory
**
** CALLED WHEN:
** 1. Stack object goes out of scope:
**    {
**        Array<int> a(5);  // Constructor
**    }  // Destructor called here automatically
**
** 2. Heap object is deleted:
**    Array<int>* a = new Array<int>(5);
**    delete a;  // Destructor called first, then memory freed
**
** 3. Array element is destroyed:
**    Array<Array<int>> matrix(3);  // 3 Arrays created
**    // When matrix destroyed, destructor called for each element
**
** ORTHODOX CANONICAL FORM (from CPP02):
** Every class managing resources must have destructor
** Without it: default destructor does nothing
** Allocated memory is leaked!
*/
template <typename T>
Array<T>::~Array()
{
	/*
	** FREE ALLOCATED MEMORY:
	** delete[] _data;
	**
	** Return the memory to the system
	** Prevents memory leak
	**
	** WHY delete[] AND NOT delete?
	** _data was allocated with new T[]
	** Must use matching delete[]
	**
	** WHAT HAPPENS:
	** 1. If T is a class with destructor, calls destructor for each element
	**    (e.g., Array<std::string> calls string destructor for each string)
	** 2. Frees the memory block
	** 3. Returns memory to the heap
	**
	** EXAMPLE: Array<std::string>
	** When destroyed:
	** 1. delete[] _data calls:
	**    - Destructor for string at _data[0]
	**    - Destructor for string at _data[1]
	**    - ... for all elements
	**    - Each destructor frees string's internal buffer
	** 2. Then frees the array itself
	**
	** DOUBLE DESTRUCTION BUG (what NOT to do):
	** Array<T>::~Array()
	** {
	**     delete[] _data;
	**     delete[] _data;  // BUG! Deleting same memory twice!
	** }
	** This causes undefined behavior / crash
	**
	** OPTIONAL: Set _data to NULL
	** _data = NULL;  // Not strictly necessary but good practice
	**
	** Some programmers do this to "poison" the pointer
	** If someone accidentally uses destroyed object, dereferencing NULL
	** gives immediate crash (easier to debug) instead of subtle corruption
	**
	** In production code, this is not usually done
	** But for teaching, it shows intent
	*/
	delete[] _data;
}

/*
** SUBSCRIPT OPERATOR IMPLEMENTATION (non-const version):
** T& operator[](size_t index);
**
** PURPOSE: Access and modify array elements like built-in arrays
**
** RETURN TYPE: T&
** Reference to the element
** Can be used on left side of assignment:
** a[0] = 10;  // Modifies the element
**
** PARAMETER: size_t index
** Which element to access
** size_t: unsigned integer (can't be negative)
**
** BOUNDS CHECKING:
** This is the main safety feature of our Array
** Built-in C arrays don't check:
** int arr[5];
** arr[100] = 10;  // No error! Undefined behavior!
**
** Our Array checks:
** if (index >= _size) throw std::exception();
** If index is invalid, throw exception (from CPP05)
**
** EXCEPTION HANDLING (from CPP05):
** throw std::exception();
** - Creates exception object
** - Throws it (stops normal execution)
** - Calling code can catch it with try/catch
** - If not caught, program terminates
**
** USER'S PERSPECTIVE:
** Array<int> a(5);
** a[0] = 10;      // OK, index 0 is valid (0 < 5)
** a[4] = 20;      // OK, index 4 is valid (4 < 5)
** a[5] = 30;      // Throws exception (5 >= 5)
** a[100] = 40;    // Throws exception (100 >= 5)
**
** COMPARISON TO VECTOR (C++98 STL):
** std::vector also has operator[]
** vector<int> v(5);
** v[100] = 10;  // No error! Undefined behavior!
** (Use v.at(100) for bounds checking in vector)
**
** But there's also at():
** v.at(100) throws exception if out of bounds
** Our operator[] does the same (safer!)
**
** ALTERNATIVE IMPLEMENTATION:
** Could just return NULL or default value
** But throwing exception is better (caller knows something went wrong)
** Silent failures are hard to debug
**
** INLINE OPTIMIZATION:
** This is a good candidate for inline
** Short function, called frequently
** Compiler probably inlines it automatically
*/
template <typename T>
T& Array<T>::operator[](size_t index)
{
	/*
	** CHECK BOUNDS:
	** if (index >= _size)
	**
	** index >= _size means index is invalid:
	** Valid indices: 0, 1, 2, ..., _size-1
	** Invalid: any >= _size
	**
	** EXAMPLE: Array of 5 elements
	** Valid indices: 0, 1, 2, 3, 4
	** Invalid: 5, 6, 100, etc.
	**
	** IF OUT OF BOUNDS:
	** throw std::exception();
	**
	** Creates and throws exception
	** Exception includes no message in C++98
	** (Could derive custom exception with message)
	**
	** WHAT HAPPENS AFTER THROW?
	** Function immediately stops executing
	** Memory is cleaned up (stack unwinding)
	** Control passes to nearest try/catch block
	** If no catch: program terminates with error
	**
	** CALLER CODE:
	** try
	** {
	**     a[100] = 5;  // Throws exception
	** }
	** catch (std::exception& e)  // (from CPP05)
	** {
	**     std::cout << "Out of bounds!";
	** }
	*/
	if (index >= _size)
	{
		throw std::exception();
	}
	
	/*
	** RETURN REFERENCE TO ELEMENT:
	** return _data[index];
	**
	** _data: pointer to first element
	** _data[index]: element at that index (pointer arithmetic)
	**
	** Return reference (&) not value
	** Allows modification:
	** a[0] = 10;  // Works because we return reference
	**
	** If we returned by value (T not T&):
	** a[0] = 10;  // Modifies the copy, not the array!
	**
	** POINTER ARITHMETIC:
	** _data[index] is equivalent to *(_data + index)
	** - _data: address of first element
	** - _data + index: address of element at index
	** - *(...): dereference to get the element
	** The [] operator is just syntax sugar for this
	**
	** EXAMPLE MEMORY:
	** Array<int> a(5);
	** _data points to: [?][?][?][?][?]  (5 uninitialized ints)
	** a[0] accesses: _data[0] = _data + 0
	** a[2] accesses: _data[2] = _data + 2  (points to 3rd element)
	**
	** HOW C++ KNOWS THE OFFSET?
	** If _data = 1000 (example address)
	** And T = int (4 bytes)
	** Then _data + 2 = 1000 + 2*4 = 1008
	** Compiler multiplies index by sizeof(T)
	** This is "pointer arithmetic" (from CPP01)
	*/
	return _data[index];
}

/*
** SUBSCRIPT OPERATOR IMPLEMENTATION (const version):
** T operator[](size_t index) const;
**
** PURPOSE: Read-only access to array elements in const Arrays
**
** CALLED WHEN:
** const Array<int>& a = ...;
** int x = a[0];  // Const version (can't modify)
**
** vs non-const version called when:
** Array<int> a = ...;
** a[0] = 10;  // Non-const version (can modify)
**
** C++ OPERATOR OVERLOADING:
** Can have multiple versions of operator[]
** - Non-const: used on non-const objects
** - Const: used on const objects
** Compiler picks the right one automatically
**
** RETURN TYPE: T (not T&)
** Could return T& but then could modify:
** const Array<int>& a = ...;
** a[0] = 10;  // Would compile if returned T&!
** By returning T (value), C++ prevents modification
**
** RETURN BY VALUE TRADE-OFF:
** Pro: Prevents accidental modification
** Con: Copies the element (for complex types like std::string, slower)
**
** ALTERNATIVE: Return const T&
** const T& operator[](size_t index) const;
** More efficient, still prevents modification
** But more complex syntax
**
** FOR TEACHING: Return by value is simpler
**
** SAME BOUNDS CHECK:
** Check if index >= _size
** Throw exception if out of bounds
** Same as non-const version
**
** WHY DUPLICATED CODE?
** Both versions have almost identical implementation
** Unfortunately, C++98 doesn't have great way to avoid this
** (C++14+ has alternative approaches)
** Some tricks: const_cast, helper function, but they're hacky
** Accepting small duplication is pragmatic choice
*/
template <typename T>
T Array<T>::operator[](size_t index) const
{
	/*
	** BOUNDS CHECK:
	** Same as non-const version
	** Throw exception if index out of bounds
	*/
	if (index >= _size)
	{
		throw std::exception();
	}
	
	/*
	** RETURN ELEMENT:
	** return _data[index];
	**
	** Return by value (not reference)
	** This prevents modification:
	**
	** const Array<int> a(5);
	** a[0] = 10;  // COMPILE ERROR
	** // Because a[0] returns int value, not int&
	** // Can't assign to an rvalue
	**
	** vs non-const:
	** Array<int> a(5);
	** a[0] = 10;  // OK
	** // Because a[0] returns int&, can assign
	*/
	return _data[index];
}

/*
** size() MEMBER FUNCTION IMPLEMENTATION:
** size_t size() const;
**
** PURPOSE: Return the number of elements in array
**
** RETURN TYPE: size_t
** Standard type for sizes
** Unsigned (can't be negative)
** Matches _size type
**
** CONST KEYWORD:
** const at end means this function doesn't modify the object
** Can call on const Arrays:
** const Array<int> a(5);
** std::cout << a.size();  // OK - const function
**
** Must use on const objects (compiler enforces)
**
** IMPLEMENTATION:
** Simply return _size
** No calculations, no side effects
** Good candidate for inline (compiler probably does automatically)
**
** WHY NOT JUST ACCESS _size DIRECTLY?
** _size is private (from CPP02 encapsulation)
** Public interface only through size() function
** If we change how size is stored internally later,
** size() function can still provide the same interface
** User code doesn't need to change
**
** EXAMPLE: Changing implementation
** Current: Store as _size
** Future: Could compute from _capacity and _allocated flags
** Only size() would need to change
** All user code calling size() still works!
**
** This is INTERFACE STABILITY
** One of the key benefits of encapsulation from CPP02
*/
template <typename T>
size_t Array<T>::size() const
{
	/*
	** SIMPLE RETURN:
	** return _size;
	**
	** Just return the stored size value
	** No validation needed (it's always consistent)
	** No computation needed
	** Simple and efficient
	*/
	return _size;
}
