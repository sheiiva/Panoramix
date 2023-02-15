mkdir -p build
cd build
cmake -DCMAKE_CXX_COMPILER=clang++ ..
cmake --build .