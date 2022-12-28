#include <iostream>
/*
*                  l-values                            ||                 r-values
*                                                      ||
* > They have a name, (all variables are               || > They don't have a name
*   l-values)                                          ||
*                                                      || > They are temporary values
* > You can assign other values to them                || > Cannot be assign other values to them
*                                                      ||
* > Some expressions return l-value                    || > Some expressions return r-value
*   l-value persists beyond the expression             ||   r-value doesn't persist beyond the expression
*                                                      ||
* > Functions that return by reference                 || > Functions that return by value return r-value
*   return l-value                                     ||
*                                                      ||
* > We can create a reference to an l-value            || > We can create a reference to an r-value
*   (l-value reference)                                ||   (r-value reference)
*   l-value reference always need an l-value           ||   r-value reference is always created to an r-value
*   l-value reference will always bind to an l-value   ||   Used to implement MOVE SEMANTICS
*   l-value may bind to a temporary if the reference   ||
*      is constant                                     ||
*/


/*                                            r-value refernces
* 
*  They were include in C++11 to implement Move Semantics. It is always created to a temporary
*  It represents a temporary value. It is created with '&&' (r-value reference operator)
*  They cannot bind to an l-value, they will always bind to a temporaries
* 
*  USES:
*	>They allow us to detect temporaries in expressions, now we can overlodad functions with
*   l-values and r-values references and treat them in a different way
* 
*   >Detecting temporaries will help us to implement MOVE SEMANTICS (faster way of copying temporary
*   objects)
*/


/* Function that returns by value (r-value)
*    The value that it returns is temporary
*/
int add(int x, int y) {
	return x + y;
}

/* Function that returns by reference (l-value)
*    -The call of the function can be written on the left side
*     of the assignment operator
*/
int& transform(int& x) {
	x *= x;
	return x;
}

void detect_reference(int& x) {
	std::cout << "int&" << std::endl;
}
void detect_reference(const int& x) {
	std::cout << "const int&" << std::endl;
}
void detect_reference(int&& x) {
	std::cout << "int&&" << std::endl;
}
void lvalues_rvalues() {
	// x,y,z are l-values
	// 15,10,8 are r-values
	int x = 15;
	int y = 10;
	int z = 8;

	/*Expression that returns an r-value
	*	'(x + y) * z' expression that returns an r-value
	*   '(x + y) another expression that returns r-value
	*
	*   The r-value that the expression returns, will no persist
	*   beyond the expression. It will be lost in the next line.
	*/
	int result = (x + y) * z;

	/* Expression that returns an l-value
	*   '++x' preincrement operator applied to 'x'
	*
	*   It can occur in the left side of the assignment operator,
	*   that means we can assign some value to it
	*/
	++x = 6;

	std::cout << "r-value: (function returns by value): " << add(x, y) << "\n";
	std::cout << "l-value: (function returns by reference): " << transform(x) << "\n";


	/*Examples of r - value references*/
	int&& r1 = 10;                     // r-value reference to 10
	int&& r2 = add(5, 8);          // add returns by value (temporary)
	int&& r3 = 7 * (3 + 2);            // Expression that returns a temporary
	//int&& r4 = x;                    // ERROR -> an rvalue reference cannot be bound to an lvalue

	/*Examples of l-value references*/
	int& l1 = x;                        // an lvalue reference will always bind to an lvalue
	int& l2 = transform(x);           // An lvalue reference can be bound to a function that returns by reference
	//int& l3 = add(x, y);              // ERROR -> It cannot bind to a temporary (initial value of reference to non-const must me an l-value)
	const int& l4 = 33;                 // An lvalue reference may bind to a temporary if the reference is constant

	/*detection of types of references
	*   If we wouldn't have implemented the function with 'int&&' parameter, the 3rd call 'detect_reference(55)' 
	*   would have called the function with the parameter 'const int&' and we would never had known 
	*   that '55' was a temporary.
	* 
	*	With the function with int&& parameter implemented it is sure, because the temporaries always
	*   bind to rvalue reference(&&).
	*/
	
	detect_reference(x);              // int &
	detect_reference(l4);             // const int&
	detect_reference(55);             // int&&
};