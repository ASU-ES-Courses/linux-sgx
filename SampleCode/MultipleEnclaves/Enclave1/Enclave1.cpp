#include "sgx_eid.h"
#include "Enclave1_t.h"
#include "EnclaveMessageExchange.h"
#include "error_codes.h"
#include "Utility_E1.h"
#include "sgx_thread.h"
#include "sgx_dh.h"
#include <map>

#define UNUSED(val) (void)(val)

std::map<sgx_enclave_id_t, dh_session_t>g_src_session_info_map;

uint32_t Enclave1_function(){

	int i = 0;
        int j = 0;

        // Approx 50 MB for array
        int size = 3620;

        int orig[size][size];
        int work[size][size];

        for (i=0;i<size;i++){
		for (j=0;j<size;j++){
                	orig[j][i] = work[j][i] - work[size-j-1][size-i-1];
		}
	}
	return 0;
}

//**********************************************************************************************************************************************
// **Functions below appear to be required for compiled object files?**
extern "C" uint32_t verify_peer_enclave_trust(sgx_dh_session_enclave_identity_t* peer_enclave_identity){
    return 0;
}

extern "C" uint32_t enclave_to_enclave_call_dispatcher(char* decrypted_data,size_t decrypted_data_length,char** resp_buffer,size_t* resp_length){
    return 0;
}

uint32_t get_message_exchange_response(uint32_t inp_secret_data){
    return 0;
}

extern "C" uint32_t message_exchange_response_generator(char* decrypted_data,char** resp_buffer,size_t* resp_length){
   return 0;
}

static uint32_t e2_foo1(uint32_t var1, uint32_t var2){
    return 0;
}

static uint32_t e2_foo1_wrapper(ms_in_msg_exchange_t *ms,size_t param_lenth,char** resp_buffer,size_t* resp_length){
    return 0;
}
