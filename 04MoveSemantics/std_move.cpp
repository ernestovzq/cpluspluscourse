/*                                std::move
* std::move is always used with l-values, it forces the compiler to use the move operations instead
* of the copy ones. It forces the compiler to use Move Semantics instead of Copy Semantics
* 
* But in some cases we may not want to create a copy of the object, instead you want to move it.
* But because it is an l-value. By function overload resolution, the compiler will choose always
* Copy Operation. We can force the compiler to use Move operations
* 
* 
*  1. TYPE CASTING
* Instead of passing the object we can pass it with a 'static_cast<Class &&>(obj)'... the the 
* compiler will choose the Move Constructor, instead of the Copy Constructor. The proble with this
* solution is that it is not readable, and does not communicate the intent clearly.  
* 
* 
* 2. std::move
* It helps to aboid ambiguity and increased credibility. We are saying that we want to 'move' an object
* Internally std::move performs the same casting
* 
*/

/*                                 USES
* 1. When an object used, is no longer required in that part of the code, but the state of that object
*    is required for another object
* 
* 2. Used in non-copyable objects. non-copyable objects don't provide Copy Operations. Non-Copyable objects
*    are created to protect resources that cannot be copied (e.g threads, unique pointer, file stream, etc)
*/

#include "Integer03.h"
#include <iostream>

/* Pass the object 'val' with std::move
* If we pass the object with std::move the local object 'val'
* will own the resources, and at the end of the function the
* object will be destroyed.
*/
void external_function(Integer03 val) {
	
}
void std_move() {
	//DEFAULT BEHAVIOUR
	Integer03 a{ 1 };
	auto b{ a };
	/*
	* Calls:
	*  - Integer(int)
	*  - Integer(const Integer&)  
	*  - ~Integer()
	*  - ~Integer()
	* By default, an l-value will trigger the Copy Operations.
	*/

	//TYPE-CASTING SOLUTION
	Integer03 c{ 1 };
	auto d{ static_cast<Integer03&&>(c) };
	/*
	* CALLS:
	*  - Integer(int)
	*  - Integer(Integer&&)
	*  - ~Integer()
	*  - ~Integer()
	*/

	//STD::MOVE SOLUTION
	Integer03 e{ 1 };
	auto f{std::move(e)};
	/*
	* CALLS:
	*  - Integer(int)
	*  - Integer(Integer&&)
	*  - ~Integer()
	*  - ~Integer()
	*/

	Integer03 g{ 1 };
	external_function(std::move(g));
	//at this point, the object 'g' does not own the resources, but we can reinizialize it
	
}