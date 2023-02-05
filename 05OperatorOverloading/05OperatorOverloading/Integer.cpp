#include "Integer.h"
#include <iostream>

Integer::Integer()
{
    std::cout << "Integer()" << std::endl;
    ptr = new int{ 0 };
}

Integer::Integer(int val)
{
    std::cout << "Integer(int)" << std::endl;
    ptr = new int{ val };
}

Integer::Integer(const Integer& obj)
{
    std::cout << "Integer(const Integer& obj)" << std::endl;
    ptr = new int{ *obj.ptr };
}

Integer::Integer(Integer&& obj)
{
    std::cout << "Integer(Integer&&)" << std::endl;
    ptr = obj.ptr;
    obj.ptr = nullptr;
}

Integer& Integer::operator=(const Integer& obj)
{
    std::cout << "operator=(const Integer&)" << std::endl;
    if (this == &obj) //to avoid own assignment
        return *this;
    if (!ptr)
        ptr = new int{};
    *ptr = *obj.ptr;
    return *this;
}

Integer& Integer::operator=(Integer&& obj)
{
    std::cout << "operator=(Integer&&)" << std::endl;
    if (this == &obj) {
        return *this;
    }
    delete ptr;
    ptr = obj.ptr;
    obj.ptr = nullptr;
    return *this;
}

Integer Integer::operator+(const Integer& obj) const
{
    Integer temp;
    *temp.ptr = *ptr + *obj.ptr;
    return temp;
}

Integer Integer::operator++(int)
{
    Integer temp{ *ptr };
    ++(* ptr);
    return temp;
    /*
    * Post-increment accepts an 'int' to have a different signature and allows the
    * compiler to distiguish bewteen the two '++'.
    * 
    * Post-increment returns a temporary, an r-value
    */
}

Integer& Integer::operator++()
{
    ++(*ptr);
    return *this;
    /*
    * Pre-Increment operator returns by reference, It returns an l-value
    */
}

bool Integer::operator==(const Integer& obj) const
{
    return *ptr == *obj.ptr;
}

void Integer::operator()() {
    std::cout << "operator()" << std::endl;
}
int Integer::get_value() const
{
    return *ptr;
}

void Integer::set_value(int val)
{
    if (!ptr)
        ptr = new int{ 0 };
    *ptr = val;
}

Integer::~Integer()
{
    std::cout << "~Integer()" << std::endl;
    delete ptr;
}

std::ostream& operator <<(std::ostream& out, const Integer& obj) {
    out << obj.get_value();
    return out;

}

std::istream& operator >>(std::istream& in, Integer& obj) {
    int value;
    in >> value;
    obj.set_value(value);
    return in;
}