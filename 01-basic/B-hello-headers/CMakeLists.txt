# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version
cmake_minimum_required(VERSION 3.5)

# Set the project name
project (hello_headers)


message("----------->${CMAKE_SOURCE_DIR}")
message("----------->${CMAKE_CURRENT_SOURCE_DIR}")
message("----------->${PROJECT_SOURCE_DIR}")

message("----------->${CMAKE_BINARY_DIR}")
message("----------->${CMAKE_CURRENT_BINARY_DIR}")
message("----------->${PROJECT_BINARY_DIR}")


find_package(jsoncpp REQUIRED)
if(jsoncpp_FOUND)
    message("--> find jsoncpp ${jsoncpp_INCLUDE_DIRS}...")
    message("--> find jsoncpp version:${jsoncpp_VERSION}")
else()
    message(FATAL_ERROR "jsoncpp not found...")
endif()

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/Hello.cpp
    src/main.cpp
)

file(GLOB CPPFILES src/*.cpp)

# 只包含源文件  无头文件 
aux_source_directory(src ALLCPPFILES)
message("----------> ${ALLCPPFILES}")
# ----------> src/Hello.cpp;src/main.cpp;src/test.c

# Add an executable with the above sources
add_executable(hello_headers ${SOURCES})
add_executable(${PROJECT_NAME}_node ${CPPFILES})
add_executable(${PROJECT_NAME}_node2 ${ALLCPPFILES})

# target_include_directories(${PROJECT_NAME}_node  PRIVATE  ${PROJECT_SOURCE_DIR}/include)

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
# target_include_directories(hello_headers PRIVATE  ${PROJECT_SOURCE_DIR}/include)

include_directories(${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}_node -ljsoncpp)
