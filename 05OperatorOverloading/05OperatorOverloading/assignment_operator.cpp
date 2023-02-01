/*                     Assignment Operator
* Assignment Operators Overloaded are necessary if we are handling underlying resources (RuleOf5).
* 
* 1. Check for OWN Assignment
*    Usually the left-side variable first delete its own resources to avoid leak memory, we need to
*    check first if we are not assigning the same variable because we would be deleting the required
*    resources.
*/

#include "Integer.h"
void assignment_operator() {
	Integer a{ 3 }, b;
	b = a;
	/* 'b = a'
	* This will invoke the assignment operator, if none has been provided, the compiler will provide
	* a default implementation, performing shallow copy
	* 
	* CALLS:
	* Integer(int)               from 'a'
	* Integer()                  from 'b'
	* operator=(const Integer&)  from 'b = a'
	*/
}