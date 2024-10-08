#include <stdio.h>


#include <Basic.h>
#include <CUnit.h>

#include<function.h>
#include<testfunctions.h>

int init_calc(void)
{
    return 0;
}


int clean_calc(void)
{
    return 0;
}


int main(int argc, char *argv[])
{


	CU_pSuite pSuite = NULL;

    /* Register  */
    if (CUE_SUCCESS != CU_initialize_registry())
       return CU_get_error();

	 /* Add init and cleanup handlers */
    pSuite = CU_add_suite("Calc  SUITE",init_calc,clean_calc);

	if (NULL == pSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

/* Add test case */
    if(NULL == CU_add_test(pSuite,"Mytestfunction_add_ID_1", Mytestfunction_add))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }

    if(NULL == CU_add_test(pSuite,"Mytestfunction_sub_ID_1", Mytestfunction_sub))
    {
       CU_cleanup_registry();
        return CU_get_error();
    }
	/* Set the mode and  invoke test(s) */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    /* unregister and do cleanup */
    CU_cleanup_registry();

    return CU_get_error();
}

