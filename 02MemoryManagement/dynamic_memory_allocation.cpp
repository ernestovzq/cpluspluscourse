/*
* 
***********  MEMORY AREAS  ***************
* 1. STACK
*	Allocated automatically for local variables
*	Managed by the runtime
* 
* 2. DATA SECTION
*	Allocated for global and static data
*	Managed by the runtime 
* 
* 3.HEAP
*	Allocated memory at runtime
* 
* 
* All the memory is taken from the PROCESS-ADDRESS-SPACE. The process address
* space is automatically created when a program is run.
* 
***********  DYNAMIC MEMORY  *************
* - Support for memory allocation at runtime
* - It happens in the heap, and has to be managed by the programmer
* 
*/


/* DYNAMIC MEMORY ALLOCATION IN C
* C provides various functions for allocating memory from the heap
* 
* malloc
*	- Allocates raw memory on the heap 
*	- It accepts a size and returns a pointer to the allocated memory
*	- It does not initialize the memory, it only returns the raw memory 
*	- Returns NULL if it fails to allocate memory
* 
* calloc
*	- Same as malloc
*	- Initialize the memory to the default value (0)
* 	- Returns NULL if it fails to allocate memory
* 
* realloc
*	- It allocates a larger chunck of memory for an existing allocation
* 	- Returns NULL if it fails to allocate memory
* 
* free
*	- Deallocates / releases the memory allocated throuh the above functions
*/

#include <iostream>
#include <cstdlib>                          //memory allocation functions

void c_dynamic_memory_functions() {
	//malloc:
	int* ptr1 = (int*)malloc(sizeof(int));   //returns a void pointer, needs a cast
	*ptr1 = 12;								 //malloc does not initialize the memory
	std::cout << *ptr1 << "\n";
	free(ptr1);                              //after freeing the memory, ptr1 still holds the same address,
	                                         //ptr1 points to an invalid address,ptr1 is a dangling pointer
	ptr1 = nullptr;                          //after freeing it, assign to NULL

	/* DANGLING POINTER
	* A dangling pointers points to an invalid address, and is very dangerous
	* - If we try to free again that pointer, the program crashes
	* 
	* After freeing the memory, we have to assign NULL to the pointer
	* - If we try to free a null pointer, it will be ignored
	*/

	//calloc:
	ptr1 = (int*)calloc(1, sizeof(int));     //Accepts the number of elements and the size of the element
	std::cout << *ptr1 << "\n";              //It initializes the memory to the default value
	free(ptr1);
	ptr1 = nullptr;


	//arrays
	ptr1 = (int*)malloc(5 * sizeof(int));    //Allocates a 1D array of size 5
	free(ptr1);
	ptr1 = nullptr;

	ptr1 = (int*)calloc(10, sizeof(int));    //Allocates a 1D array of size 10
	free(ptr1);
	ptr1 = nullptr;

	/* MEMORY LEAK
	* If we forget to call free and reuse the pointer, the memory cannot be released
	* this casues a MEMORY LEAK. That is why any memory allocated on the heap has to
	* be freed manually by the programmer.
	*/
}