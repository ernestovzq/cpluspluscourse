#include "Integer0.h"
#include <iostream>
/*                     COPY CONSTRUCTOR
* 
* A copy constructor is used to create a copy of an object. The copy is created
* by copying the values of the member variables into another objects. It means
* it copies the object's STATE into another object.
* 
* SYNTEHSIZED AUTOMATICALLY.
* The copy constructor is synthesized automatically if it is not provided by the user
* but the default implementation will copy only the values in a SHALLOW way, behaviour
* undesirable in some cases, specially if we have pointers as members of the class.
* 
* WHEN A COPY OF AN OBJECT IS CREATED? 
* 1. When an object is being passed by value into a function
* 2. When a function returns the object by value
* 3. When we manually create a new object using another one in the constructor
*/


Integer0::Integer0()
{
	std::cout << "Integer0()" << std::endl;
	ptr = new int{0};
}

Integer0::Integer0(int value)
{
	std::cout << "Integer0(int)" << std::endl;
	ptr = new int{ value };
}

int Integer0::get_value() const
{
	return *ptr;
}

void Integer0::set_value(int value)
{
	if (ptr == nullptr) {
		ptr = new int{};
	}
	ptr = new int{ value };
}

void Integer0::test() const
{
	std::cout << "ptr: " << ptr << std::endl;
	std::cout << "*ptr: " << *ptr << std::endl;
}

Integer0::~Integer0()
{
	std::cout << "~Integer0()" << std::endl;
	delete ptr;
}

void print(Integer0 i) {
	//A copy constructor synthesized will be called because we are passing by value
	std::cout << i.get_value() << std::endl;
	std::cout << "Call of test, inside print:" << std::endl;
	i.test();
	//The copy object will be destroyed
}

Integer0 add_integer0(int x, int y) {
	//An object is created here
	return Integer0{ x + y };
	//the destructor of the object created is called here 
}