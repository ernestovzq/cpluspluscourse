#include "Integer.h"
#include <iostream>

/*                 USER-DEFINED COPY CONSTRUCTOR
* 
* We'll use a User-Define Copy Constructor any time we want to make a Deep Copy
* 
*            DEEP COPY
* We will copy the VALUE at the address of the pointer, rather than the pointer address
* To perform a DEEP COPY
* > Allocate new memory
* > Copy the value of the address
* 
*           WHEN THE COPY OF THE OBJECT IS CREATED? 
* 1. When you invoke the copy constructor directly
* 2. When the object is passed into a function by value
* 3. When a function returns a function by value
* 4. When one object is assigned to another object
*    Even if we have not provided any '=' assignment operator, the compiler will
*    synthesize, the synthesized function will make a SHALLOW COPY
* 
*          Implementation
* It recieves an object by reference. If it is passed by value AGAIN a copy of the object will be
* created and that would invoke the copy constructor again.(LOOP)
* 
*/


/*                     RULE OF 3
* 
* To know which kind of classes will require user-defined Copy Constructor & Assignment Operator
* 
* All should be defined if a user implements any of them
*  1. Destructor: It will free the resource allocated
*  2. Copy Constructor: It will perform a deep copy
*  3. Copy Assignment Operator:  It will perform a deep copy
* 
* The miss of the rule, could lead to
*  > Memory Leak
*  > Shallow Copy
*/
Integer::Integer()
{
	std::cout << "Integer()" << std::endl;
	ptr = new int{ 0 };
}

Integer::Integer(int value)
{
	std::cout << "Integer(int)" << std::endl;
	ptr = new int{ value };
}

Integer::Integer(const Integer& obj)
{
	std::cout << "Integer(const Integer&)" << std::endl;
	ptr = new int(*obj.ptr);
}

int Integer::get_value() const
{
	return *ptr;
}

void Integer::set_value(int value)
{
	if (ptr == nullptr) {
		ptr = new int{};
	}
	ptr = new int{ value };
}

Integer::~Integer()
{
	std::cout << "~Integer()" << std::endl;
	delete ptr;
}

void print(Integer i) {
	//A copy constructor will be called because we are passing by value
	std::cout << i.get_value() << std::endl;
	//The copy object will be destroyed
}

Integer add_integer(int x, int y) {
	//An object is created here
	return Integer{ x + y };
	//the destructor of the object created is called here 
}