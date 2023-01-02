#include "Integer03.h"
#include <iostream>

Integer03::Integer03()
{
	std::cout << "Integer03()" << std::endl;
	ptr = new int{ 0 };
}

Integer03::Integer03(int value)
{
	std::cout << "Integer03(int)" << std::endl;
	ptr = new int{ value };
}

Integer03::Integer03(const Integer03& obj)
{
	std::cout << "Integer03(const Integer03&)" << std::endl;
	ptr = new int{*obj.ptr};
}

Integer03::Integer03(Integer03&& obj)
{
	std::cout << "Integer03(Integer03&&)" << std::endl;
	ptr = obj.ptr;
	obj.ptr = nullptr;
}

Integer03& Integer03::operator=(const Integer03& obj)
{
	std::cout << "operator=(const Integer03&)" << std::endl;
	if (&obj == this) {
		return *this;
	}
	*ptr = *obj.ptr;
	return *this;
}

Integer03& Integer03::operator=(Integer03&& obj)
{
	std::cout << "oprator=(Integer03&&)" << std::endl;
	if (this == &obj) {
		return *this;
	}
	delete ptr;
	ptr = obj.ptr;
	obj.ptr = nullptr;
	return *this;
}

Integer03::~Integer03()
{
	std::cout << "~Integer03()" << std::endl;
	delete ptr;
}

int Integer03::get_value() const
{
	return *ptr;
}

void Integer03::set_value(int value)
{
	if (!ptr) {
		ptr = new int{ 0 };;
	}
	*ptr = value;
}
