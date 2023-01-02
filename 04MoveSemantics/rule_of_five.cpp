/*                       RESOURCE MANAGEMENT
* Some classes own a resource (e.g. pointer, file handle, socket, etc)
* These resources may be acquired by the class in the constructor. We have to decide
* the action in case objects of such clasess are 
* - copied
* - moved
* - destroyed 
*/


/*                       RULE OF 5
* If a class has ownership semantics, then you must provide a user-defined implementation of 
* below functions to ensure proper handling of the underlying resource.
* 
* > Destructor: to release the memory allocated
* > Copy Constructor: we create a copy of the underlying resource
* > Copy Assignment Operator: we create a copy of the underlying resource
* > Move Constructor: we move the underlying resource from one object to the other
* > Move Assignment Operator: we move the underlying resource from one object to the other
*/


/*                       RULE OF 0
* If a class does not have ownership semantics, that means it does not acquire any resouce.
* the we must not provide any user-defined function from the Rule Of 5.
* 
* Because we don't provide any of those functions, the compiler will synthesize the necessary functions
* 
*    RISK OF IMPLAMENTING SOME OF THOSE FUNCTIONS
* If we provide the implementation of some functions fron the Rule Of 5, it will prevent the compiler
* from synthesizing others
*/

#include "Number.h"

Number01 get_number(int value) {
	Number01 temp{ value };    // Call (05) Integer03(int), Call (09) Integer03(int)
	return temp;
	// Call (07) ~Integer03(int)              synthesized for Number, local object
	// Call (11) ~Integer03(int)              synthesized for Number, local object
}

/* 
* Example where the compiler synthesizes the next functions for the Number01 class:
* - Number01(const Number01&)    -> copy constructor
* - Number01(Number01&&)         -> move constructor
* - operator=(const Number01&)   -> copy assignment operator
* - operator=(Number01&&)        -> move assignment operator
* - ~Number01()                  -> destructor
* 
* The compiler is able to synthesize these function as long as there are no CUSTOM IMPLEMENTATION
*/
void synthesize_functions() {
	Number01 a{ 33 };          // CALL (01) Integer03(int)
	Number01 b{};              // CALL (02) Integer03()
	/*
	* Number01 has not any user-defined implementation from the Rule of 5, then the compiler will 
	* synthesize the necessary (copy/move operations and destructor)
	* 
	* Any function that is synthesized (or implemented if it is one of the RuleOf5 functions) for the Number 
	* class will internally call the corresponding functions of the Integer class
	*/
	b = a;                    // Call (03) operator=(const Integer03&)   synthesized for Number
	auto c{ a };              // Call (04) Integer03(const Integer03&)   synthesized for Number
	get_number(33);           // Call (06) Integer03(Integer03&&)        synthesized for Number
    // Call (08) ~Integer03(int)               synthesized for Number, temporary object

	a = get_number(44);       // Call (10) Integer03(Integer03&&)        synthesized for Number
	                          // Call (12) operator=(Integer03&&)        synthesized for Number
    // Call (13) ~Integer03(int)               synthesized for Number, temporary object
	
	// Call (14) ~Integer03(int)               synthesized for Number, a
	// Call (15) ~Integer03(int)               synthesized for Number, b
	// Call (16) ~Integer03(int)               synthesized for Number, c

}


/*                                         TABLE OF OVERVIEW
* Table that let us know which functions are able to be synthesized by the compiler when custom implementation
* of some other functions are provided:
* 
*  _____________________________________________________________________________________________________
*  |If we provide (below)  |    Copy      |    Copy      |    Move      |    Move      |               |
*  |Is synthesized (right)?|  Constructor |  Assignment  |  Constructor |  Assignment  |  Destructor   |
*  -----------------------------------------------------------------------------------------------------
*  |       Copy            |     ___      |     YES      |    NO        |    NO        |    YES        |     
*  |     Constructor       |              |              |              |              |               |
*  |---------------------------------------------------------------------------------------------------|
*  |       Copy            |     YES      |     ___      |    NO        |    NO        |    YES        |
*  |     Assignment        |              |              |              |              |               |
*  |---------------------------------------------------------------------------------------------------|
*  |       Move            |      NO      |      NO      |     ___      |    NO        |    YES        |
*  |     Constructor       |              |              |              |              |               |
*  |---------------------------------------------------------------------------------------------------|
*  |       Move            |      NO      |      NO      |      NO      |     ___      |    YES        |
*  |     Assignment        |              |              |              |              |               |
*  |---------------------------------------------------------------------------------------------------|
*  |                       |      YES     |      YES     |      NO      |      NO      |    ___        |
*  |     Destructor        |              |              |              |              |               |
*  |---------------------------------------------------------------------------------------------------|
*  |                       |      YES     |      YES     |     YES      |     YES      |    YES        |
*  |        NONE           |              |              |              |              |               |
*  ----------------------------------------------------------------------------------------------------|
* 
*/

                                           /*default keyword*/
/* How to force the compiler to synthesize those functions?
* If we have to custom implement one of the RuleOf5 functions for extra funcionallity, and still we want
* the compiler to synthesize the other ones, to be able to  call the corresponding ones for the member variables
* we can force the compiler to synthesize using the 'default' keyword.
* 
* The default keyword only works for those RuleOf5 functions AND the default constructor
* In general the default function can only be used for those functions that are synthesized by the compiler
* 
*   Number(const Number&) = default;
*   Number(Number&&) = default;
*   operator=(const Number&) = default;
*   operator=(Number&&) = default;
*   ~Number() = default;
*   Number() = default;
* 
* Even if we are using the default specifier, they are still considered a CUSTOM IMPLEMENTATION of the functions
* and they will still block the synthesization of the other RuleOf5 functions
* 
*                                           Default Constructor
* The default constructor is also synthesized by the compiler except when a parametrized constructor is implemeneted
* but still we can use the keyword 'default' so the compiler can implement it. 
* 
*/