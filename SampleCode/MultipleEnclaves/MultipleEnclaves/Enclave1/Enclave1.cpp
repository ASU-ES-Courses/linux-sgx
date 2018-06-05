#include "sgx_eid.h"
#include "Enclave1_t.h"
#include "EnclaveMessageExchange.h"
#include "error_codes.h"
#include "sgx_thread.h"
#include "sgx_dh.h"
#include <map>

#define UNUSED(val) (void)(val)

std::map<sgx_enclave_id_t, dh_session_t>g_src_session_info_map;

static uint32_t e1_foo1_wrapper(ms_in_msg_exchange_t *ms, size_t param_lenth, char** resp_buffer, size_t* resp_length);

uint32_t test_create_session(sgx_enclave_id_t src_enclave_id,sgx_enclave_id_t dest_enclave_id){
    return 0;
}

uint32_t test_enclave_to_enclave_call(sgx_enclave_id_t src_enclave_id,sgx_enclave_id_t dest_enclave_id){
    return 0;
}

uint32_t test_message_exchange(sgx_enclave_id_t src_enclave_id,sgx_enclave_id_t dest_enclave_id){
    return 0;
}
uint32_t test_close_session(sgx_enclave_id_t src_enclave_id,sgx_enclave_id_t dest_enclave_id){
    return 0;
}

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
