                                            /*SMART POINTERS */

/*
*                                 
* When you are using pointers and allocating memory on the HEAP, it may not always be possible
* to remember to call delete on the pointer. that will lead to massive memory leaks in your program
* 
*                            RAII (Resource Acquisition Is Initialization)
* 
* We can prevent memory leaks outright and that is possible by using an idiom called RAII (Resource
* Acquisition Is Initialization)
* 
* With this IDIOM the lifetime of a resource is bound to a local object, so when the local object is destroyed
* in its destructor, it will automatically release the resource
* 
* To create the same 'pointer' behavior we need to OVERLOAD some operators {->, *} so we are going to be able
* to access the member functions of the underlying resource
* 
* 
*                            Smart Pointer
* 
* These local objects are known as Smart Pointers, local objects that behave like pointers and automatically 
* deletes the underlying memory. Modern C++ emphasizes the use of Smart Pointers rather than raw pointers
*/



#include "Integer.h"
#include <iostream>


//class with RAII
/*
* An object that behaves like a pointer and automatically
* deletes the underlying memory. It is a Smart Pointer
*/
class IntPtr {
public:
	Integer* ptr{};
	IntPtr(Integer* ptr) :ptr(ptr) {

	}
	~IntPtr() {
		delete ptr;
	}
	Integer* operator->() {
		return ptr;
	}

	Integer& operator*() {
		return *ptr;
	}

};


void memory_leak() {
	//integer created on the HEAP
	Integer* p = new Integer{ 22 };
	std::cout << (*p) << std::endl;
	//missing freeing the memory
}

void integer_raii() {
	/*  Integer created on the HEAP using RAII
	* The memory allocated on the HEAP using new is properly destroyed. At the end
	* of the scope, the local object is automatically destroyed and calls the
	* destructor, unrealising the underlying memory.
	*/
	IntPtr p{new Integer{22}};           //p is a local object 
	p->set_value(33);                    // -> overloaded
	p.ptr->set_value(44);
	std::cout << (*p) << std::endl;      //  * overloaded
}


/*SMART POINTERS provided in C++ <memory> library */
/*
* C++ provides different kind of smart pointers and they are defined in the header file "memory"
*
*                      UNIQUE POINTER
*
* This a class template, and it requires the type of the pointer that you want to manage. 
* Unique pointer is used when we don't want to share the underlying resource. We cannot create
* a copy of the unique pointer. We can still move it.
* 
* Unique pointer has Move Semantics, but it does not support Copy Semantics. We can move
* the ownership of the resource from a unique pointer to another. We can acomplish this using std::move
* 
* std::move involes the move constructor of its argument
* 
* 
*                      SHARED POINTER
* 
* Another class template that allows to share the underlying resource. It internally implements some kind of
* reference counting. Each time a copy of the shared pointer is created, it increments by one, when a shared
* ponter is destroyed the reference count decrements and if the reference count becomes ZERO, then it
* realeases the underlying resource
* 
*/

void moving_uniqueptr(std::unique_ptr<Integer> ptr) {
	std::cout << *ptr << std::endl;
}
//c++ smart pointer
void cpluplus_smartpointers() {
                                                 /* unique pointer */

	std::unique_ptr<Integer> up{ new Integer{} };
	up->set_value(33);
	std::cout << *up << std::endl;
	//COPY SEMANTICS
	//auto temp = up;                               //COMP Error, copy operations deleted in unique_ptr
	//moving_uniqueptr(up);                         //COMP Error, copy operations deleted in unique_ptr

	//MOVE SEMANTICS
	moving_uniqueptr(std::move(up));                //moving the ownership of the resource
	//std::cout << *up << std::endl;                //Runtime Error, up does not have any more the ownership of the resource

												 /* shared pointer */
	std::shared_ptr<Integer> sp{ new Integer{55} };
	//COPY SEMANTICS
	auto temp = sp;
	std::cout << *temp << std::endl;
	std::cout << *sp << std::endl;

}
void smart_pointers() {
	//memory_leak();
	//integer_raii();
	cpluplus_smartpointers();
}