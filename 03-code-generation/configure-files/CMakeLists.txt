cmake_minimum_required(VERSION 3.5)

# Set the project name
project (cf_example)

# set/option 定义的变量, 不能直接在 cpp中使用, 需要 configure_file 进行转换操作
# set(WORLD_VALUE "material and spiritual")
# -D 的 则可以
add_definitions(-DWORLD_VALUE="material and spiritual")


option(LIFE_VALUE "the value of life" ON)

# set a project version
set (cf_example_VERSION_MAJOR 0)
set (cf_example_VERSION_MINOR 2)
set (cf_example_VERSION_PATCH 1)
set (cf_example_VERSION "${cf_example_VERSION_MAJOR}.${cf_example_VERSION_MINOR}.${cf_example_VERSION_PATCH}")

# Call configure files on ver.h.in to set the version.
# Uses the standard ${VARIABLE} syntax in the file
configure_file(ver.h.in ${PROJECT_BINARY_DIR}/ver.h)

# configure the path.h.in file.
# This file can only use the @VARIABLE@ syntax in the file
configure_file(path.h.in ${PROJECT_BINARY_DIR}/path.h @ONLY)

# Add an executable
add_executable(cf_example
    main.cpp
)

# include the directory with the new files
target_include_directories( cf_example
    PUBLIC
        ${CMAKE_BINARY_DIR}
)
