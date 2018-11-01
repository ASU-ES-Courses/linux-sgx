// App.cpp : Defines the entry point for the console application.
#include <stdio.h>
#include <map>
#include "../Enclave1/Enclave1_u.h"
#include "sgx_eid.h"
#include "sgx_urts.h"
#define __STDC_FORMAT_MACROS
#include <inttypes.h>
#include <time.h>

#define UNUSED(val) (void)(val)
#define TCHAR   char
#define _TCHAR  char
#define _T(str) str
#define scanf_s scanf
#define _tmain  main


sgx_enclave_id_t e1_enclave_id = 0;

#define ENCLAVE1_PATH "libenclave1.so"

int iterations = 1000000;
//int iterations = 10;

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

    unsigned long exit_flag, attack_rep, attack_size;
    unsigned long sec1,sec2,ns1,ns2;
    struct timespec time1;
    struct timespec time2;

    UNUSED(argc);
    UNUSED(argv);

    if(load_enclaves() != SGX_SUCCESS)
    {
        printf("\nLoad Enclave Failure");
    }
    
    do
    {

	FILE *fp;

	int i;
	for(i=0;i<iterations;i++){

		fp = fopen("file_out", "a");

		attack_rep = 1;
		if(attack_rep == 0)
			break;

		// Get timestamp before starting attack
		clock_gettime(CLOCK_REALTIME, &time1);\
//		for(i=0;i<attack_rep;i++){
			function1();
//		}

		// Get timestamp after starting attack
		clock_gettime(CLOCK_REALTIME, &time2);

		sec1 = time1.tv_sec;
		sec2 = time2.tv_sec;
		ns1 = time1.tv_nsec;
		ns2 = time2.tv_nsec;

		//int LEN = 47;
		//char time[LEN];
		fprintf(fp,"%lu%lu,%lu%lu\n", sec1,ns1,sec2,ns2);
		//fwrite(time, 1, LEN, fp);
		fclose(fp);

		printf("\n\n");
		printf("Start Victim: sec=%lu ns=%lu ; %lu%lu\n",sec1,ns1,sec1,ns1);
		printf("End Victim: sec=%lu ns=%lu ; %lu%lu\n",sec2,ns2,sec2,ns2);
	}
	


#pragma warning (push)
#pragma warning (disable : 4127)    
    }while(0);
#pragma warning (pop)
	
    printf("\n\nDestroying Attacker Enclave\n\n");
    sgx_destroy_enclave(e1_enclave_id);

    return 0;
}
