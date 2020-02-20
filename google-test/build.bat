mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE="C:/tools/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build .
ctest
