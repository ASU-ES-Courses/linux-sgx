#include "sgx_eid.h"
#include "Enclave1_t.h"
#include "sgx_thread.h"
#include "sgx_dh.h"
#include <map>

#define UNUSED(val) (void)(val)


volatile void iterate_static(){
	
	volatile int i = 0;
        volatile int j = 0;

        volatile int size = 4579;

        volatile int orig[size][size];
        volatile int work[size][size];

        for (i=0;i<size;i++){
		for (j=0;j<size;j++){
                	orig[j][i] = work[j][i] - work[size-j-1][size-i-1];
		}
	}
}

volatile void iterate_dynamic(){

	volatile int size = 5838;

	volatile int i = 0;
	volatile int j = 0;

	volatile int **orig = (volatile int **)malloc(size*sizeof(int *));
	volatile int **work = (volatile int **)malloc(size*sizeof(int *));

	for (i=0;i<size;i++){
		orig[i] = (int *)malloc(sizeof(int)*size);
		work[i] = (int *)malloc(sizeof(int)*size);
	}

	for (i=0;i<size;i++){
		for (j=0;j<size;j++){
			orig[j][i] = work[j][i] - work[size-j-1][size-i-1];
		}
	}
}

uint32_t Enclave1_function(){

	iterate_static();
//	iterate_dynamic();

	return 0;
}

