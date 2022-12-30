#include "Integer01.h"
#include "Integer02.h"

/*                                COPY & MOVE SEMANTICS
* 
*  In copy semantics the copy of the object is copied through copy constructor
*  This copy can be either:
*    - Shallow Copy
*    - Deep Copy: Used when the object contains pointer or other kinds of resources, a
*                 copy of the object state is created.
* 
*   In some ocassion the object has to be created from A TEMPORARY
*     - For example, a function that returns AN USER DEFINED OBJECT BY VALUE
*       then a copy of the object will be created when the function returns, in this case
*       a deep copy would be wastefull, instead WE CAN MOVE THE STATE from the source object
*       into the target object , this could be implemented through MOVE SEMANTICS
* 
*          COPY SEMANTICS                          ||             MOVE SEMANTICS
*                                                  ||
* If we want to make a deep copy of an object that || If the source of the object is a temporary object
* contains pointer, we need to:                    || for example the result of some expression, and we want its
*                                                  || state in some other object, instead of creating a deep copy:
*  1. Allocate new memory                          || 
*  2. Copy the value of the source object into the || 1. Point to the same address that the source object is pointing to
*     new memory address                           || 2. We assign nullptr to the pointer of the source object (temporary
*                                                  ||    object)
*                                                  || 3. When the temporary object (source object) is destroyed, the destructor
*                                                  ||    will call delete on a null pointer
* 
* 
* 
*   If an expression yields a temporary and that has to be copied in some other object then we should use MOVE SEMANTICS
* 
* 
*                              MOVE CONSTRUCTOR
* 
* By default copying an object would call the Copy Constructor, to be able to check if the argument is a TEMPORARY OBJECT
* we need to implement a constructor that accepts an rvalue reference (Move Constructor) the temporaries will automatically
* be bind to this constructor. In the implementation we can perform MOVE SEMANTICS
*/


                                              /* COPY SEMANTICS */
/*
* Function that calculates the sum of two Integer01 objects
* and returns the result BY VALUE.
* 
* It returns an Integer01 object BY VALUE, it means a Temporary 
* Object will be created, and by default it will call Copy Constructor
*/
Integer01 add(const Integer01& a, const Integer01& b) {
	Integer01 temp;                                  // Call (3): Integer01()
	temp.set_value(a.get_value() + b.get_value());
	return temp;
	//Call (5): ~Integer01()
}

void copy_semantics() {
	Integer01 a{ 4 };                                //Call (1): Integer01(int)
	Integer01 b{ 3 };                                //Call (2): Integer01(int)
	a.set_value(add(a, b).get_value());              //Call (4): Integer01(const Integer&) 
	//Call (6): ~Integer01()  from temporary object
	//Call (7): ~Integer01()  from a
	//Call (8): ~Integer01()  from b

	/*MOVE ELISION*/
	/*
	* In some cases the 'temporary object (Call 4)' may not be created, this is to the compiler
	* performing COPY Elision
	*/
}

                                             /* Move SEMANTICS */
/*
* Function that calculates the sum of two Integer02 objects
* and returns the result BY VALUE.
*
* It returns an Integer02 object BY VALUE, it means a Temporary
* Object will be created, using MOVE CONSTRUCTOR
* 
* Move Semantics is more efficient than Copy Semantics, because in Copy
* we have to allocate new memory, here we don't have to allocate. We also have
* to have implemented the Move Assignment Operator
*/
Integer02 add(const Integer02& a, const Integer02& b) {
	Integer02 temp;                                  // Call (3): Integer02()
	temp.set_value(a.get_value() + b.get_value());
	return temp;
	//Call (5): ~Integer02()
}

void move_semantics() {
	Integer02 a{ 4 };                                //Call (1): Integer02(int)
	Integer02 b{ 3 };                                //Call (2): Integer02(int)
	a.set_value(add(a, b).get_value());              //Call (4): Integer02(Integer&&) 
	//Call (6): ~Integer02()  from temporary object
	//Call (7): ~Integer02()  from a
	//Call (8): ~Integer02()  from b

	/*MOVE ELISION*/
	/*
	* In some cases the 'temporary object (Call 4)' may not be created, this is to the compiler
	* performing MOVE Elision
	*/
}

void move_semantics_test() {
	Integer02 a{ 3 };
	Integer02 b{ 4 };
	Integer02 c = add(a, b);

	/* CALLS WITHOUT MOVE ELISION
	* 
	* 01. Integer02(int)           from 'a'
	* 02. Integer02(int)           from 'b'
	* 03. Integer02()              from 'temp' in add function
	* 04. Integer02(Integer02&&)   from temporary object returned by add 
	* 05. ~Integer02()             from 'temp' destroyed in add 
	* 06. Integer02(Integer02&&)   from 'c' created from a temporary object
	* 07. ~Integer02()             from temporary object returned by add 
	* 09. ~Integer02()             from 'a'
	* 09. ~Integer02()             from 'b'
	* 10. ~Integer02()             from 'c'
	*/

	/* CALLS WITH MOVE ELISION
	*
	* 01. Integer02(int)           from 'a'
	* 02. Integer02(int)           from 'b'
	* 03. Integer02()              from 'temp' in add function
	* 05. Integer02(Integer02&&)   from 'c' created from a temporary object
	* 04. ~Integer02()             from 'temp' destroyed in add
	* 06. ~Integer02()             from 'a'
	* 07. ~Integer02()             from 'b'
	* 08. ~Integer02()             from 'c'
	* 
	*  Move Elision does not create the TEMPORARY OBJECT
	*/
}