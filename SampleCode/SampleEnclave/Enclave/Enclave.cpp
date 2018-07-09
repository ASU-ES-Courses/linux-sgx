#include <stdarg.h>
#include <stdio.h>      /* vsnprintf */

#include "Enclave.h"
#include "Enclave_t.h"  /* print_string */

/* 
 * printf: 
 *   Invokes OCALL to display the enclave buffer to the terminal.
 */
void printf(const char *fmt, ...)
{
/*
    int i = 0;
    int j = 0;

    // Ref. SGX Size Chart
    int size = 512;

    int orig[size][size];
    int work[size][size];

    for (i=0;i<size;i++){
	for (j=0;j<size;j++){
		orig[j][i] = work[j][i] - work[size-j-1][size-i-1];
	}
    }
*/
/*
    char buf[BUFSIZ] = {'\0'};
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buf, BUFSIZ, fmt, ap);
    va_end(ap);
    ocall_print_string(buf);
*/
}
