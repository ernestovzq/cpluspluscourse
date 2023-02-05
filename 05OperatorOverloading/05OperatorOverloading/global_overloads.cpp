#include "Integer.h"
#include <iostream>


Integer operator+(int a, const Integer& b) {
	Integer temp;
	temp.set_value(a + b.get_value());
	return temp;
}

void primitive_argument() {
	Integer a{ 5 };
	//replacing second parameter with primitive
	Integer sum = a + 13;
	std::cout << sum.get_value() << std::endl;
	/*
	* It works, the int values gets converted into an Integer through a process
	* called Type Conversion
	* 
	* CALLS:
	* Integer(int)         from 'a'
	* Integer(int)         from '13'
	* Integer()            from 'temp' in operator+
	* Integer(Integer&&)   from the r-value returned
	* Integer(Integer&&)   from 'sum', it does not show ELISION
	*/


	//replacing first parameter with primitive
	/*It does not work with only the member operator overloaded, because the first
	* operand is the one that calls the function, that means it has to be an object 
	* since the beginning:
	* 
	*            a + 13   <=>   a.operator+(13);
	* 
	* If the first operand of an overloaded operator has to be a primitive type, then
	* the operator overloaded has to be as a global function
	* 
	*/
	sum = 13 + a;
	std::cout << sum.get_value() << std::endl;
	/*
	*	CALLS:
	* Integer()              from 'temp'
	* Integer(Integer&&)     from the r-value returned
	* operator=(Integer &&)  from 'sum'
	*/
	
}

void insertion_overloading() {
	//Insertion Operator
	/* std::cout << Integer(2) << std::endl;
	* To make the insertion operator work for our user-defined object is necessary to overload
	* the operator '<<' because it has to know how to insert it into cout 
	* 
	* The insertion operator '<<' is already overloaded for all primitive types. It is overloaded in
	* the ostream class. We need to overload it as a global function
	*/
	Integer a{ 12 };
	std::cout << a << std::endl;
	operator << (std::cout, a).operator <<(std::endl);
	/* How does it work? 
	* 
	* The compiler makes the call:
	*   operator <<(std::cout, a) 
	* 
	* That expression returns an ostream object, and that can invoke again the operator '<<' and pass the 'end' manipulator
	*   operator <<(std::cout,a).operator <<(std::endl);
	* 
	*/

	//Extraction Operator
	Integer b;
	std::cin >> b;
	std::cout << b << std::endl;
}

void call_operator() {
	// ()
	/*
	* It is used extensively in STL
	* We can overload this operator to perform any operation that we want in the object
	* It can accept any number of arguments
	* It looks like a function call and can be used with templates to implement callbacks
	*/
	Integer temp{ 12 };
	temp();
}
void global_overloads() {
	//primitive_argument();
	//insertion_overloading();
	call_operator();
}