sudo apt-get install build-essential ocaml automake autoconf libtool wget python
sudo apt-get install libssl-dev libcurl4-openssl-dev protobuf-compiler libprotobuf-dev
./download_prebuilt.sh
make DEBUG=1
make sdk_install_pkg DEBUG=1
make psw_install_pkg DEBUG=1
sudo apt-get install build-essential python
./linux/installer/bin/sgx_linux_x64_sdk_2.1.3.44322.bin
source /home/eugene/SGX/linux-sgx/sgxsdk/environment
sudo ./linux/installer/bin/sgx_linux_x64_psw_2.1.3.44322.bin
