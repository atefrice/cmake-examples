# cmake -S . -B build.clang -DCMAKE_CXX_COMPILER=clang++
# cmake --build build.clang -v -j 3

# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (hello_cmake)



# 总体同上,已过时,弃用
add_definitions(-DLIFE="wedh" -DCHINA -DROBOT_TYPE=1 -std=c++11 -g -s)
# 初步测试未作用 链接选项
# usr/bin/c++  -DCHINA -DLIFE=\"wedh\" -DROBOT_TYPE=1  -std=c++11 -g -s -o CMakeFiles/hello_cmake.dir/main.cpp.o -c /home/muyuan/code/github/my_project/cmake-examples/01-basic/I-compiling-with-clang/main.cpp
# /usr/bin/c++     CMakeFiles/hello_cmake.dir/main.cpp.o  -o hello_cmake




# 编译时自动加上 -D 关键字, 即编译 变量定义, 这变量定义会传入到代码的预处理器里使用
# add_compile_definitions(LIFE="wedh" CHINA ROBOT_TYPE=1)
# add_compile_options(-std=c++11 -g)   
# add_link_options(-s)
# /usr/bin/c++  -DCHINA -DLIFE=\"wedh\" -DROBOT_TYPE=1  -std=c++11 -g -o CMakeFiles/hello_cmake.dir/main.cpp.o -c /home/muyuan/code/github/my_project/cmake-examples/01-basic/I-compiling-with-clang/main.cpp
# /usr/bin/c++    -s CMakeFiles/hello_cmake.dir/main.cpp.o  -o hello_cmake

# CMAKE_CXX_COMPILER=clang++
# set(CMAKE_CXX_COMPILER "clang++")

# Add an executable
add_executable(hello_cmake main.cpp)

# add_subdirectory()