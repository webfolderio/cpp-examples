vcpkg install gtest
mkdir build
cd build
cmake ..
cmake --build .
ctest
