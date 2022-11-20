#include <iostream>
#include "mymath.h"

void uniform_initialization();
void pointers_references();

int main() {
	//uniform_initialization();
	pointers_references();
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