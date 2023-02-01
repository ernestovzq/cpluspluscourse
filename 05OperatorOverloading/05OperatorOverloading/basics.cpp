		            /*Operator Overloading*/
/*
* It is a way to provide a custom implementation of primative operators for user-defined objects
* Allows us usage of user-defined objects in complex mathematical expression
* 
* OVERLOADING AS GLOBAL FUNCTIONS:
* It requires to be overloaded with the same number of arguments as the operands
* 
* OVERLOADING AS MEMBER FUNCTIONS:
* One of the arguments will be passed implicity as argument through 'this' pointer
*/

                    /* Returning *this*/
/*
* If any member function returns *this. It is an opportunity to return by reference
* and no temporary will be created. That is the reason why pre-increment operator is
* more efficient than post-increment
*/

#include "Integer.h"
#include <iostream>

//Global Function Implementation
Integer operator-(const Integer& a, const Integer& b) {
	Integer temp;
	temp.set_value(a.get_value() - b.get_value());
	return temp;
}

void arithmetic_operators() {
	Integer a{ 3 }, b{ 44 };
	Integer sum = a + b;
	std::cout << sum.get_value() << std::endl;
	/*
	* Operator overloading is just a Syntactic Sugar over function calls:
	* The compiler internally invoke the overloaded operator function (Integer::operator+)
	*
	* CALLS:
	* Integer(int)            from 'a'
	* Integer(int)            from 'b'
	* Integer()               from 'temp'
	* Integer(Integer&&)      from 'sum'
	*/

	Integer sub = a - b;
	std::cout << sub.get_value() << std::endl;
	/*
	* CALLS:
	* Integer()               from 'temp'
	* Integer(Integer&&)      from 'sub'
	*/
}


void post_pre_increment() {
	Integer a{ 3 };                                // a = 3
	(a++).set_value(222);                          // set_value is a call from the 'temporary' object created
	std::cout << a.get_value() << std::endl;       // a = 4
	std::cout << (++a).get_value() << std::endl;   // a = 5
}

void operator_overloading_basics() {
	post_pre_increment();
}