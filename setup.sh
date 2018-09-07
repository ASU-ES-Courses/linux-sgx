echo "sudo apt-get install build-essential ocaml automake autoconf libtool wget python"
sudo apt-get install build-essential ocaml automake autoconf libtool wget python
echo "----------------------------------------------------------------------------------------------"

echo "sudo apt-get install libssl-dev libcurl4-openssl-dev protobuf-compiler libprotobuf-dev"
sudo apt-get install libssl-dev libcurl4-openssl-dev protobuf-compiler libprotobuf-dev
echo "----------------------------------------------------------------------------------------------"
echo "./download_prebuilt.sh"
./download_prebuilt.sh
echo "----------------------------------------------------------------------------------------------"

echo "make DEBUG=1"
make DEBUG=1
echo "----------------------------------------------------------------------------------------------"

echo "make sdk_install_pkg DEBUG=1"
make sdk_install_pkg DEBUG=1
echo "----------------------------------------------------------------------------------------------"

echo "make psw_install_pkg DEBUG=1"
make psw_install_pkg DEBUG=1
echo "----------------------------------------------------------------------------------------------"

echo "sudo apt-get install build-essential python"
sudo apt-get install build-essential python
echo "----------------------------------------------------------------------------------------------"

echo "./linux/installer/bin/sgx_linux_x64_sdk_2.1.3.44322.bin"
./linux/installer/bin/sgx_linux_x64_sdk_2.1.3.44322.bin
echo "----------------------------------------------------------------------------------------------"

echo "./linux/installer/bin/sgx_linux_x64_sdk_2.1.3.44322.bin"
source /home/eugene/SGX/linux-sgx/sgxsdk/environment
echo "----------------------------------------------------------------------------------------------"

echo "sudo ./linux/installer/bin/sgx_linux_x64_psw_2.1.3.44322.bin"
sudo ./linux/installer/bin/sgx_linux_x64_psw_2.1.3.44322.bin
echo "----------------------------------------------------------------------------------------------"

echo "chmod +x uninstall.sh"
chmod +x uninstall.sh
echo "----------------------------------------------------------------------------------------------"

