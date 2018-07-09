source /home/eugene/SGX/linux-sgx/sgxsdk/environment
make clean
make
sudo dmesg -c
./app
sudo dmesg -c
make clean
