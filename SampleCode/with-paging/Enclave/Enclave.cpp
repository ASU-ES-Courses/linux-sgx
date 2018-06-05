#include "Enclave_t.h"

int generate_random_number() {
 
    int i = 0;
    int j = 0;

    //approx 90 MB array
    int size = 4857;

    int orig[size][size];
    int work[size][size];

    for (i=0;i<size;i++){
        for (j=0;j<size;j++){
                orig[j][i] = work[j][i] - work[size-j-1][size-i-1];
        }
    }

    ocall_print("Processing random number generation...");
    return 42;
}
