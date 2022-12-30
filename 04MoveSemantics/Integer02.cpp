#include "Integer02.h"
#include <iostream>

Integer02::Integer02()
{
	std::cout << "Integer02()" << std::endl;
	ptr = new int{ 0 };
}

Integer02::Integer02(int value)
{
	std::cout << "Integer02(int)" << std::endl;
	ptr = new int{ value };
}

Integer02::Integer02(const Integer02& obj)
{
	std::cout << "Integer02(const Integer02&)" << std::endl;
	ptr = new int{ *obj.ptr };
}

Integer02::Integer02(Integer02&& obj)
{
	std::cout << "Integer02(Integer02&&)" << std::endl;
	ptr = obj.ptr;            //shallow copy
	obj.ptr = nullptr;        //not in use anymore
	/*                             MOVE CONSTRUCTOR
	* - We steal the resource of 'obj', performing a shallow copy
	*   and the pointing to null all its resources, so when it get destroyed
	*   the resource are still allocated and our object will be pointing to them.
	*/
}

int Integer02::get_value() const
{
	return *ptr;
}

void Integer02::set_value(int value)
{
	if (!ptr) {
		ptr = new int{};
	}
	*ptr = value;
}

Integer02::~Integer02()
{
	std::cout << "~Integer02()" << std::endl;
	delete ptr;
}
