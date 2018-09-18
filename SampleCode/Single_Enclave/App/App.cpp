// App.cpp : Defines the entry point for the console application.
#include <stdio.h>
#include <map>
#include "../Enclave1/Enclave1_u.h"
#include "sgx_eid.h"
#include "sgx_urts.h"
#define __STDC_FORMAT_MACROS
#include <inttypes.h>


#define UNUSED(val) (void)(val)
#define TCHAR   char
#define _TCHAR  char
#define _T(str) str
#define scanf_s scanf
#define _tmain  main


sgx_enclave_id_t e1_enclave_id = 0;

#define ENCLAVE1_PATH "libenclave1.so"

uint32_t load_enclaves()
{
    uint32_t enclave_temp_no;
    int ret, launch_token_updated;
    sgx_launch_token_t launch_token;

    enclave_temp_no = 0;

    ret = sgx_create_enclave(ENCLAVE1_PATH, SGX_DEBUG_FLAG, &launch_token, &launch_token_updated, &e1_enclave_id, NULL);
    if (ret != SGX_SUCCESS) {
                return ret;
    }

    enclave_temp_no++;

    return SGX_SUCCESS;
}

void function1() {
	uint32_t ret_status;
	Enclave1_Enclave1_function(e1_enclave_id, &ret_status);
}

int _tmain(int argc, _TCHAR* argv[])
{
    uint32_t ret_status;
    sgx_status_t status;

    UNUSED(argc);
    UNUSED(argv);

    if(load_enclaves() != SGX_SUCCESS)
    {
        printf("\nLoad Enclave Failure");
    }
    
    do
    {

	printf("\n\nStarting Functions...\n\n");
	function1();

#pragma warning (push)
#pragma warning (disable : 4127)    
    }while(0);
#pragma warning (pop)
	
    // Hold function here before destroying enclave
	char hold[10000];
	printf("Program holding... Enter any key to continue.\n");
	scanf("%s", hold);

    printf("\n\nDestroying Enclaves\n\n");
    sgx_destroy_enclave(e1_enclave_id);

    return 0;
}
