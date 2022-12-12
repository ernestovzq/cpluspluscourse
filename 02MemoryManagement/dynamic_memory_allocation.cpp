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


/* DYNAMIC MEMORY ALLOCATION IN C++
* new
*	- Operator that allocates the memory on the heap
*	- It only requires the type name, not the size
*	- It includes initialization, but it is optional
*	- Used with classes, new can call the constructors during allocation
*	- It throws ans exception if it fails to allocate memory
* 
* delete
*	- Deallocates the memory from the heap
*/

void dynamic_memory_operators() {
	int* ptr = new int(12);			//initialize the memory during allocation
	std::cout << *ptr << "\n";
	delete ptr;                     //freeing the memory, ptr is a dangling pointer now
	ptr = nullptr;                  //to avoid leak memory
}

/**
* malloc:                              |  new:
* - function                           | - operator
* - requires size during allocation    | - size is ascertained from the type
* - cannot initialize memory           | - can initialize memory
* - cannot call constructors           | - it can call constructors
* - returns void pointer and needs to  | - returns the correct type of pointer
*   be type casted                     |
* - cannot be customized               | - Customized (through operator overloading)
* - if fails allocation returns NULL   | - if fails allocation throws and exception
* - malloc/realloc/calloc              | - new, new[]
*/


/*                    new[] / delete[]
* 
* Used for allocationg dynamic arrays 
*/

void new_arrays() {
	int* p = new int[5]{ 1,2,3,4,5 }; //array immediately initalized
	//delete p;                       //without [] may not delete the entire array
	delete[] p;                       //now p is a dangling pointer
	p = nullptr;                      //because is the last line, it is no necessary,
	                                  // the pointer 'p' is gonna be destroyed
	
	char* s = new char[4];
	strcpy_s(s,4,"C++");
	std::cout << s << "\n";
	delete[] s;
}


void new_2Darrays() {
	//2D arrays 
	/*
	* - In the memory are represented as a contiguous 1D array
	* - Because of the creation syntax [][], the compiler allows
	*	us to use the row-column syntax to access individual elements
	*/
	int data[2][3]{ 1,2,3,4,5,6 }; 
	int* p_data = &data[0][0];
	int size_data = sizeof(data) / sizeof(int);
	while (size_data--) {
		std::cout << *p_data << ",";
		++p_data;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	//2D arrays on the heap
	/*
	* - It is different, each row has to be an independent 1D array
	*   meaning all the elements are not contiguous
	* 
	* - To free the memory, we have to free it in the same order 
	*   in which you allocated it
	*	(The number of delete calls, should match the number of
	*	 new calls) 
	*/
	int* r1 = new int[3]{ 1,2,3 };
	int* r2 = new int[3]{ 4,5,6 };
	int** arr = new int* [2]{ r1,r2 };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr[i][j] << " ";
		}
		std:: cout << "\n";
	}
	std::cout << std::endl;

	delete[] r1;          // delete[] arr[0];
	delete[] arr[1];      // delete[] r2;
	delete[] arr;
	r1 = nullptr;
	r2 = nullptr; 

	//generic 2D array
	int N = 10, M = 5;
	arr = new int* [N];
	for (int i = 0; i < N; i++) {
		int* r = new int[M];
		arr[i] = r;
		for (int j = 0; j < M; j++) {
			arr[i][j] = M * i + j + 1;
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}