#include "oop.h"
#include <iostream>

void oop_example();
int main() {
	oop_example();
}

void oop_example() {
	Car c(4);
	Car* c2 = new Car{};

	// this pointer:
	c.print_this();
	std::cout << "&c: " << &c << "\n\n";

	c.accelerate();
	c.accelerate();
	c.accelerate();
	
	//const object
	const Car c3;			
	//c3.accelerate();  // it cannot invoke non-const functions
	c3.dashboard();

	delete c2;
	std::cout << std::endl << "Number of Cars: " << Car::get_total_cars() << std::endl;
}