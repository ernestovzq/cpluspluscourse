#include "Integer01.h"
#include <iostream>

Integer01::Integer01()
{
	std::cout << "Integer01()" << std::endl;
	ptr = new int{ 0 };
}

Integer01::Integer01(int value)
{
	std::cout << "Integer01(int)" << std::endl;
	ptr = new int{ value };
}

Integer01::Integer01(const Integer01& obj)
{
	std::cout << "Integer01(const Integer01&)" << std::endl;
	ptr = new int{ *obj.ptr };
}

int Integer01::get_value() const
{
	return *ptr;
}

void Integer01::set_value(int value)
{
	if (!ptr) {
		ptr = new int{};
	}
	*ptr = value;
}

Integer01::~Integer01()
{
	std::cout << "~Integer01()" << std::endl;
	delete ptr;
}
