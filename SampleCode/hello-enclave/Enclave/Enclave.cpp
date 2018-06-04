#include "Enclave_t.h"

int generate_random_number() {

	int i = 0;
        int j = 0;

        // Approx 10GB for array
        int size = 51811;
/*
        int orig[size][size];
        int work[size][size];
*/

	int **orig = (int **)malloc(size*sizeof(int *));
	int **work = (int **)malloc(size*sizeof(int *));
	for (i=0;i<size;i++){
		orig[i] = (int *)malloc(sizeof(int)*size);
		work[i] = (int *)malloc(sizeof(int)*size);
	}

        for (i=0;i<size;i++){
                for (j=0;j<size;j++){
                        orig[j][i] = work[j][i] - work[size-j-1][size-i-1];
                }
        }
        return 0;
}
