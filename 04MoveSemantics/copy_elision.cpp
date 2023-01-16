/*                                    COPY ELISION
* 
* A technique that is used by the compiler to eliminate temporary objects
* Visual Studio Automatically implements Copy Elision for temporary Objects
* 
* To deactivate the Copy Elision in Linux Compiler:
*       g++ -fno-elide-constructors main.cpp Integer.cpp
* 
* For copy-elision to work the class should have the copy and the move constructors
*/

/*                                    ELISION
* elide(verb): to omit or leave out. It is used to represent an omission of
*              a vowel, consonant or a syllable in pronunciation
* 
* elision(noun): the act or an instance of omission
*/

/*                                    COPY/MOVE Elision
*  Depending on whether the expression requires a COPY or MOVE, the compiler may either use COPY ELISION 
*  (where the Copy Constructor is ommited) or MOVE ELISION (where the Move Constructor is ommited)
*/

#include "Integer03.h"

/*
* Function that returns an object by value (it means we create a temporary object)
* then the compiler may implement Copy Elision
*/
Integer03 add(int a, int b) {
	Integer03 temp(a + b);
	return temp; 
	/*           Named Returned Value Optimization
	* The Copy Elision Mechanism Based in this optimization elides the temporary object 
	* returned in this functions
	*
	*/
}

Integer03 substract(int a, int b) {
	return Integer03(a - b);
	/*           Return Value Optimization
	* The Copy Elision Mechanism Based in this optimization elides the temporary object
	* returned in this function AND also the object created in the function.
	* 
	* It is a better implementation for this kind of functions
	*/
}

void test1() {
	Integer03 a = 3;
		/*DESCRIPTION*/
	/*
	* We are using the assignemnt opearator '=' to INITIALIZE an Integer03 object with
	* a primitive type, these are not compatible, then the compiler will expand the code:
	*      Integer03 a = Integer03(3)
	*
	* A temporary object will be created, and then will be moved to 'a'. The Move Elision
	* mechanism in the compiler will elide this temporary object, instead the 'parametrized
	* constructor' of the Integer03 class is directly invoked
	*/

	/*Output Without Move Elision*/
	/*
	* 1. Integer(int)          - Integer(3), a temporary object created by the compiler
	* 2. Integer(Integer&&)    - from 'a', is created from a temporary object
	* 3. ~Integer()            - the temporary object
	* 4. ~Integer()            - 'a' object
	*/

	/*Output With Move Elision*/
	/*
	* 1. Integer(int)
	* 2. ~Integer()
	*/
}

void test2() {
	Integer03 a = add(3, 5);
	                        /*Output without Move Elision*/
	/*
	* 1. Integer(int)             - 'temp' object in add function
	* 2. Integer(Integer&&)       - temporary object created by returning by value
	* 3. ~Integer()               - 'temp' object in add function
	* 4. Integer(Integer&&)       - Move Constructor from 'a'
	* 5. ~Integer()               - temporary object created by returning by value
	* 6. ~Integer()               - from 'a'
	*/

	/*Output with Move Elision (Linux)*/
	/*
	*  1. ~Integer()               - from 'a'
	*  2. ~Integer()               - from 'a'
	*/
	                        /*Output with Move Elision (Visual Studio - Debug Mode)*/
	/*
	*  1. Integer(int)             - 'temp' object in add function
	*  2. ~Integer()               - 'temp' object in add function
	*  3. Integer(Integer&&)       - Move Constructor from 'a'
	*  4. ~Integer()               - from 'a'
	* 
	*/

}

void test3() {
	Integer03 a = substract(3,5);
	                        /*Output with Move Elision (Visual Studio - Debug Mode)*/
	/*
	*  1. Integer(int)             - from a
	*  2. ~Integer()               - from 'a'
	*/
}


void copy_elision() {
	test3();
}