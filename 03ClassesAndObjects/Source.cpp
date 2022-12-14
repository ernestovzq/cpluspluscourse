#include "oop.h"
#include "Integer0.h"
#include "Integer.h"
#include <iostream>

void oop_example();
void delegating_constructor();
void copy_constructor_shallow_copy();
void copy_constructor_deep_copy();
void default_delete();

int main() {
	//oop_example();
	//delegating_constructor();
    //copy_constructor_shallow_copy();
	//copy_constructor_deep_copy();
	default_delete();
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

void delegating_constructor() {
	Car c{ 6 };
	/*       CALLS:       */
	// Car(float,passengers)
	// Car(float)
	c.dashboard();
}

void copy_constructor_shallow_copy() {
	/*                     Conditions of implementation/Test:
	*	- No copy constructor was implemented by the user
	*   - Running in Release Mode
	*/
	Integer0 i{ 5 };
	//We are calling the Copy Constructor Synthesized making a copy of 'i'
	Integer0 j{ i };
	i.test();                        //they share the same address
	j.test();                        //they share the same address
	std::cout << std::endl;

	//A copy will be created because we are passing by value 'i'
	std::cout << "Call of print:" << std::endl;
	print(i);                        //shallow copy of i is created in print
	std::cout << std::endl;

	// A copy of the object will be created because we are returning by value in 'add_integer0' 
	j = add_integer0(10, 20);        //copy assignment operator synthesized by the compiler
	std::cout << std::endl;
	std::cout << "j:" << std::endl;
	j.test();                        //this memory should have been deleted in 'add_integer0' function if we were using Debug Mode
	std::cout << j.get_value() << std::endl;


	/*                    Dangerous Code / Application Crash
	*	The reason it does not crash in Release Mode, is because in Release mode the compiler removes some 
	*   assert statements.
	* 
	*   It should crash because we are using SHALLOW COPY
	*/

	/*                    SHALLOW COPY
	* When we copy a pointer, it only copues the address, any change that we make to the original pointer
	* or the copy will be reflected in both and in any other pointer that holds the same address.
	*/
}

void copy_constructor_deep_copy() {

	Integer i{ 5 };
	//We are calling the Copy Constructor making a copy of 'i'
	Integer j{ i };
	std::cout << std::endl;

	//A copy will be created because we are passing by value 'i'
	std::cout << "Call of print:" << std::endl;
	print(i);
	std::cout << std::endl;

	// A copy of the object would be created because we are returning by value in 'add_integer' 
	add_integer(10, 20);

	//                   STILL CRASH
	// A copy of the object would be created if we save the returned value, but the 'COPY CONSTRUCTOR' is not called
	// The COPY ASSIGNMENT OPERATOR Synthesized is CALLED, and it is performing with SHALLOW COPY, because there isn't one defined

	//j = add_integer(10, 20);
	//std::cout << j.get_value() << std::endl;
}

void default_delete() {
	Integer temp;                                      //Using default constructor
	std::cout << temp.get_value() << std::endl;
	//temp.set_value(12.44f);                          //Implicity casting allow
	//std::cout << temp.get_value() << std::endl;      

	//deleting implicit casting
	temp.set_value(33);                                //Only Accepts int
	std::cout << temp.get_value() << std::endl;
}