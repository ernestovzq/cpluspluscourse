#include "oop.h"
#include <iostream>

/*                    Object Oriented Programming
* Objects: 
* Fundamental building blocks, rather than algorithms. A program is created as 
* a collection of objects. Every object is an instance of a class.
* 
* Relationships of objects:
*  - via inheritance "is a"
*  - via composition "has a "
* 
* OOP simulate interactions of objects in real-world systems, it decreases the
* complexity of software systems making code reusable, extensible and maintainable
* 
*							OOP PRINCIPLES
* 
* > Abstraction
*       It focuses only on the important and necessary details of an an object, the
*       unwanted or not necessary features are left out. It avoid the complexity of
*       the objects in the real world. They are represented via:
*       - struct
*       - class
*       - interface
*       - union
*       - enum
* 
* > Encapsulation
*       It helps to hide how the objects are internally implemented. The class provides
*       the behaviour without revealing the implementation. The objects become easy to use
*       by the users and the internal implementation can be change without the user's 
*       knowledge. Encapsulation is implemented through ACCESS MODIFIERS:
*       - public
*       - private
*       - protected
* 
* > Inheritance
*       It creates a hierarchy of classes, allowing to create relationships between classes
*       It is an 'IS A' relationship. The CHILD CLASS inheritances the behaviour and implementation
*       from the BASE CLASS, the CHILD CLASS can provide a different implementation
* 
*       Inheritance promotes REUSE & EXTENSIBILITY
* 
* > Composition
*       Another form of relationship between classes, it also promotes REUSE of objects
*       Represented as 'HAS A' or 'PART OF' relationship
* 
* > Polymorphism (many forms)
*       It represents common behaviour of different objects with different implementations
*       The response of those behaviours will be different for each object, it depends on
*         how the object have implemented that behaviour. 
*       Implemented through:
*       - Function overloading  (at compile time)
*       - Templates             (at compile time)
*       - Virtual functions     (at runtime)
*       Polymorphism promotes REUSE, SCALABILITY & EXTENSIBILITY
* 
*/


/*					CLASS
* A class represent a BLUEPRINT/TEMPLATE or a set of instructions that build a specific type
* of object. A class contains
*  - Variables (attributes)
*  - Functions (methods)
*  - Classes 
*/


/*                 HEADER FILE(.h)
* 
*         #pragma once
* It is called header guard, it prevents redeclaration errors, when the same HEADER FILE (.h) 
* is included more than once in the same SOURCE FILE(.cpp)
* 
*         Funcions defined in the HEADER FILE
* Any function defined in the HEADER FILE(.h) is automatically an INLINE FUNCTION, but in most
* cases we only declare the functions in the HEADER FILE(.h) and define the function in the 
* SOURCE FILE(.cpp)
*/



/*                CONSTRUCTOR
* 
* Special function invoked when the instance is created. It is used no initialize the state of 
* the object during creation. There are different types of constructors:
* 
*	> Default       T()
*        It does not accepts any arguments, it is automatically invoked when the object is created 
*        without any arguments
*        
*        It can be synthesized by the compiler. This is only true if there are no other user-defined
*        constructors in the class
* 
*   - Parameterized T(...)
*        Constructor that accepts one or more arguments
*        
*        It is used to initialize the object with user-defined values
* 
*        Never synthesized by the compiler and having a parameterized constructor blocks auto
*        generation of default constructor. 
* 
*	- Copy          T(T obj)
*	- Delegating    T():(...)
*	- Inheriting
*/

/*                DESTRUCTOR
* Function that is invoked automatically when an object is destroyed. A constructor may acquire
* some resources when the object is created, the constructor can be used for realeasing those
* resources
*
* If the user has not provided any destructor, then the compiler will synthesize one if required
*/

/*                STRUCTURES
* Exact same as classes, but the default access is public, if no modifider is specified
* 
* USES:
* > To represent simple Abstract Types (points,vectors, etc)
* > For implementing Function Objects (they are used as callbacks in the StandardTemplateLibrary)
*/


/*                NON-STATIC Data Member Initializer
* 
* We can initialize class members with values during declaration, instead of the constructor
* We can initialize any type
*	 -> variable
*	 -> array
*	 -> pointer
*	 -> user-defined object
* 
* HOW DOES IT WORK?
*    The compiler automatically generates initialization code and the code is inserted into the 
*    constructors. The member variables initialized in user-defined constructors will have precedence
*    over the initialization in the class declaration
* 
* LIMITATION
*    We can't use 'auto'
*/

/*                this POINTER
* All the member functions of a class accepts a hidden parameters called 'this'. A hidden pointer that
* the compiler automatically passes to the member functions
* 
* The pointer contains the address of the object that invokes the member function, allowing the member
* function to differentiate between different objects that invoke it.
* 
* Constant Pointer, we cannot assing any other address to this pointer
* 
* DISASSEMBLY:
* BEFORE every member function call, there is a statement:  lea       ecx,[c]
* lea stands for Load Effective Address, it will take the addres of 'c' and put it into the register 'ecx'
* ecx is accessed inside the member function to get hold of the object
* 
* INSIDE every member function call, ther is a statment:  mov        dword ptr [this],ecx
* It moves the address of the register 'ecx' into 'this' And all the statementes inside the 
* member function that access the members of the class will always take the addres from 'this' pointer
* 
* USES
* 1. Avoid confussion of local and member objects with the same name
* 2. To pass the object or the adress of the object FROM a member function TO another function
* 3. To return the current object in a member function (e.g. increment, decrement operator, assignment operator)
*/

/*                  STATIC CLASS MEMBER
* 
* They belong to the class, and only one copy of the member exists, shared with all the objects of the class
* 
* INITIALIZATION
*     They cannot be initialized in the CLASS DECLARATION
*     If they are not initialized, their default value will be assigned
* 
* ACCESS
*     They can be access from any member function of the class
*     NON-STATIC members cannot be access from STATIC member functions
*/

/*                    CONSTANT MEMBER FUNCTIONS
* 
* Read-Only functions, cannot change the value of any member variables
* If we create a CONST Object, it can invoke only constant member functions
* Cont member functions can only invoke other const member functions
* 
* HOW DOES IT WORK?
* The const qualifier, qualifies the 'this' pointer, making it a const pointer,
* and any object which address is in a const pointer, behaves like a const object
*/

int Car::total_cars{ 0 };

Car::Car()
{
	total_cars++;
	std::cout << "Car()" << std::endl;
}

Car::~Car()
{
	--total_cars;
	std::cout << "~Car()" << std::endl;
}

Car::Car(float fuel)
{
	total_cars++;
	std::cout << "Car(float)" << std::endl;
	this->fuel = fuel;
}

void Car::fill_fuel(float amount)
{
	fuel = amount;
}

void Car::accelerate()
{
	speed++;
	fuel -= 0.5f;
}

void Car::brake()
{
	speed = 0;
}

void Car::add_passengers(int count)
{
	passengers += count;
}

void Car::dashboard() const
{
	std::cout << "Number of Cars: " << this->total_cars << std::endl;
	std::cout << "Fuel: " << fuel << std::endl;
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Passengers: " << passengers << std::endl;
}

void Car::print_this() const
{
	std::cout << "this: " << this << "\n";
}

int Car::get_total_cars()
{
	return total_cars;
}

