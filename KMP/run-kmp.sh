mkdir build
cd build
echo "making directory: build"
cmake ..
make -j8
echo "In build directory, if you want to set up configuration, remove build dir and modify the root CMakeLists.txt"
