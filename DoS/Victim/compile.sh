make clean
rm file_out
source /home/eugene/SGX/linux-sgx/sgxsdk/environment
make
./app
make clean
cat file_out
