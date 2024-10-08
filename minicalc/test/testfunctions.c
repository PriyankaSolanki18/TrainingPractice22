
#include <stdio.h>
#include <stdlib.h> 
#include <CUnit.h> // for CU_ASSERT
#include <function.h> 
void Mytestfunction_add(void)
 {
	int a ;
	a = sum(5,2);
	//check if sum is as expected
 	CU_ASSERT(a == 7) 
	printf("\n sum:%d\n", a); 
}


void Mytestfunction_sub(void)
{
	int b;
	b = sub(6,2);
	CU_ASSERT(b == 4)
	printf("\n Difference:%d", b);

}


