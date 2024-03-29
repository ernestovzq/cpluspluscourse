#include <iostream>
#include "mymath.h"

void uniform_initialization();
void pointers_references();
void const_qualifier();
void auto_keyword();
void rangebased_for();
void function_overloading();

int main() {
	//uniform_initialization();
	//pointers_references();
	//const_qualifier();
	//auto_keyword();
	//rangebased_for();
	function_overloading();
	return 0;
 }

void uniform_initialization() {
				/* C++ 98 */
	//Scalar Types
	int a1;                              // uninitialized 
	int a2 = 10;                         // copy initialization
	int a3(5);                           // direct initialization
	//User-defined Types
	std::string s1;                      // default constructor called
	std::string s2("C++");               // direct initialization
	//Vector Types 
	int b1[3];                           //uninitialized
	char b2[3] = { 'a','b','c' };        //copy initialization
	char b3[5] = { '\0' };               //aggreate initialization (copy initialization)
	char b4[10] = { "Hello" };           //copy initialization

				/* Uniform Initialization */
	//Scalar Types
	int c1{};                             //value initialization
	int c2{ 5 };                          //direct initialization
	//Vector Types
	char d1[5]{};                         //value initialization
	char d2[10]{ "Hello" };               //direect initialization
	//Heap Based Objects
	int* p1 = new int{};                  //value initialization
	char* p2 = new char[10]{};            //value initialization
	char* p3 = new char[10]{ "Hello" };   //direct initialization

				/* Most vexing parse */
	int e1();                             //It is a function, not used!

				/*Narrowing Coversion*/

	float f{};
	//int i{ f };                         //Compilation Error


				/* Uniform Initialization Advantages*/
	/*
	* Uniform Initialization for all types
	* Using Empty {} forces initialization for scalar and vector types
	* It prevents narrowing conversion
	*/

				/* Kinds of Initialization*/
	/*
	* Value Initialization  => T obj{};
	* Direct Initialization => T obj{v};
	* Copy Initialization   => T obj = v;
	*/
}

void pointers_references() {
				/*POINTERS*/
	/*
	* It holds the memory address of another variable
	* We can manipulate inderectly the value of the value
	*/
	//float* ptr_f = &x;             //the types should match 
	int x = 10;
	void* ptr = &x;                  // void variable (to point different types)
	ptr = nullptr;                   // nullptr, type safe version of NULL
	int* ptr2 = &x;
	*ptr2 = 5;                       //dereference operator

				/*REFERENCES*/
	/*
	* Alternative name or an alias of a variable
	* Used to modify a variable indirectly
	* It always needs an initializer, a variable (reference = referent)
	* It's always bound to that variable, cannot be bound to other one
	* No memory is allocated for a reference
	*/
	int x2 = 10;                     //referent
	int& ref1 = x2;                  //reference (bind to x2, share address)
	int y2 = 15;
	ref1 = y2;                        // x2 = 15 (not binded to y2)
	std::cout << "&ref1: " << &ref1 << "\n";
	std::cout << "&x2: " << &x2 << "\n";

				/*Pointers vs References*/
	/*
	*        REFERENCE                  |          POINTERS
	*- Always needs an initializer      |- Initializer optional
	* 
	*- The initializer should be a      |- Initializer does not need to be a 
	*  variable, a l-value              |  l-value
	* 
	*- No storage required              |- It has its own storage
	* 
	*- Does not require dereference     |- It requires dereference operator (*)
	*  operator to access the value     |  to access the value
	* 
	*- passing by reference avoid       |- passing by address requires verify
	*  access violation (read nullptr)  |  if the pointer is nullptr
	*  because always is binded         |
	* 
	*/

}



void print(const int* x) {
	//*x = 10;							// error
	std::cout << "X: " << *x << "\n";
}
void print(const int& x) {
	//x = 10;							// error
	std::cout << "X: " << x << "\n";
}
//function that returns by value
std::string get_temporary(const char* p) {
	std::string temp("Inside");
	return temp;            // return lvalue by value
	return p;               // create a temporary that will be returned by value
	return "same as above"; // same as above
}

void const_qualifier() {
				/* Const Qualifier */
	/*
	*It always need an initializer
	*They replace macros
	*	- Macros are not type-safe
	*	- Macros does not have a scope
	*/

				/* Pointer to Constant*/
	/*
	* The pointer shold also be pointed to a constant
	* We cannot modify the value through the pointer
	* 
	* The pointer IS NOT CONSTANT
	*		- It can save different values
	* 
	* Assigning the address of a non-constant variable
	*		- We cannot modify the value through the pointer
	*		- Useful as arguments to functions
	* 
	* Read a pointer declaration
	*		- From Right-to-Left
	*/
	const double PI{ 3.1415 };                       // Contant Variable
	double eps{ 1e-6 };                              // Variable
	const double* ptrd{ &PI };                       // Pointer to a constant 
	ptrd = &eps;
	std::cout << "*ptrd (eps): " << *ptrd << "\n";
	//*ptrd = 1e-2;						             // ERROR
	eps = 1e-2;
	std::cout << "*ptrd (eps): " << *ptrd << "\n";
	int x1{ 10 };
	print(&x1);

			/* Constant Pointer */
	/*
	* - We cannot change the address (the value of the pointer) once
	*   it is assigned during declaration
	*/
	int* const ptr_const{&x1};                        // Needs to be initialized

	/*Const with References*/
	/*
	*	-- Assigning a const reference to a literal --
	*   References qualified with const, it can be created to a literal
	*   The compiler internally creates a temporary object initialized with
	*   the literal, and makes the reference point to it. This object will 
	*   be destroyed when the referenced is destroyed.
	* 
	*   -- Assigning a 'temporary' returned from a function
	*	It is known a "life extension", it only applies with const references
	*	and is used for any function that returns by value, the const reference
	*	will extend the lifetime of the 'temporary' that is created from the
	*	return value of the function
	* 
	*   -- Useful as arguments to functions --
	*   To avoid modifying an object, better syntax than pointers to constant
	*	They are more suitable when used with objects
	*/
	const int& INF = 1e9;
	const std::string& out =  get_temporary("Hi");
	print(x1);

}

void auto_keyword() {
				/* Auto keyword*/
	/*
	* Used to declare a variable without specifying the type
	* They are useful with lambda expressions and templates
	*/

				/* Used  With Pointers*/
	int x = 10;

	auto ptr = &x;              // int*
	auto* ptr1 = &x;            // int*

	const auto ptr2 = &x;   // int *const
	const auto* ptr3 = &x; // const int *

				/* Initializer List*/
	auto l= { 1,2,3,4,5 };
	auto i{ 1 };
}

void rangebased_for() {
				/* Range-Based For*/
	/*
	* Allows iteration over arrays and containers
	* Each iteration returns a copy of the element
	* It can be used with l-values and r-values
	* 
	*  -- It can be used for any object that behaves like a range --
	* It is necessary to provide iterators
	* begin() and end() functions suppported that return iterators
	* Operations required for the iterations: !=,++
	*/

				/*Using Range-Based for*/
	int arr[]{ 2,4,6,8,10 };
	for (int &v : arr) {
		v+=2;
	}
				/*Internally Working for arrays*/
	/*
	* It is used forwarding reference to accept l-values and r-values
	* 
	*    --forwarding reference (auto && or T &&) --
	* It is an r-value reference, that is declared in context of automatic
	* type deduction. the final type will depend on the source type. If the
	* source is r-value, the type will be r-value, it also preserves any
	* qualifiers
	* 
	*/
	auto&& range = arr;

	/*
	* begin() and end() are usually provided by ranges, a simple array
	* is a range, all containers in c++ have their own functions.
	*/
	auto begin = std::begin(range);
	auto end = std::end(range);
	for (; begin != end; ++begin) {
		auto v = *begin;
		std::cout << v << ",";
	}

}

void print_over(int* x) {
	std::cout << "int* " << x << "\n";
}

void print_over(const int* x) {
	std::cout << "const int* " << x << "\n";
}

class Car {
public:
	Car() {

	}

	void print()const {
		std::cout << "print const\n";
	}
	void print() {
		std::cout << "print\n";
	}
};

void function_overloading() {
	/*
	* It allows to create two or more functions can have the same name
	* - the arguments should differ in type and/or number
	* - For pointers and references, qualifers participate in overload
	* - For member functions(classes), quialifers participate in overload
	* 
	* Different implementation of the same behaviour
	* It is resolved at compile-time
	* - the compiler is able to choose the correct function that has to be invoked 
	*   at compile time (static polymorphism)
	*/

	//different type of arguments
	std::cout << add(12.33, 424.33) << "\n";
	std::cout << add(1233, 42433) << "\n";

	//one of the functions uses const qualifer in the argument
	const int x1 = 10;
	int x2 = 10;
	print_over(&x1);
	print_over(&x2);

	//member function with quialifer
	Car c1{};
	const Car c2{};
	c1.print();
	c2.print();
	
	/** NAME MANGLING
	* 
	* It is a process of the compiler to generate UNIQUE NAME for the functions
	* It allows the LINKER to link the call with the correct overloaded function
	* The NAME MANGLING algorithm varies from compiler to compiler
	* 
	* 
	*   MAP FILE 
	* - A file generated by the LINKER and contains information about the program that is
	*   being linked
	* - In the Map File we can see the names generated for our functions
	* - Creation in Visual Studio
	*		* Project >  Properties
	*		* Linker > Debugging > Generate Map File
	*/
}