#include "Number.h"
#include <iostream>

Number01::Number01(int value):value{value}
{
}

Number01::Number01(Number01&& obj)
{
	std::cout << "Number01(Number01&&)" << std::endl;
}
