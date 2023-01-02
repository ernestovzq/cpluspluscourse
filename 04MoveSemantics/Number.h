#pragma once
#include "Integer03.h"

class Number01 {
	Integer03 value{};
public:
	Number01(int value);
	Number01() = default;      
	Number01(Number01&& obj);  // it will prevent the compiler to synthesize:
	                           // {move assignment,copy constructor, copy assignment}
	Number01(const Number01& obj) = default;
	Number01& operator=(const Number01& obj) = default;
	Number01& operator=(Number01&&) = default;

};