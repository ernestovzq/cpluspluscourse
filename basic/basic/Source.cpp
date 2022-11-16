#include <iostream>
#include "mymath.h"

void uniform_initialization();

int main() {
	uniform_initialization();
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