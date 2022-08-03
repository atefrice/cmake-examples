cmake_minimum_required(VERSION 3.5)

# Set the project name
project (third_party_include)

# list(APPEND CMAKE_PREFIX_PATH "/usr/local/lib/")
message("-----> ${CMAKE_MODULE_PATH} ==> ${CMAKE_PREFIX_PATH}")

# find a boost install with the libraries filesystem and system
find_package(Boost 1.46.1 REQUIRED COMPONENTS filesystem system)
if(Boost_FOUND)
    message ("boost found,version:version:${Boost_VERSION}")
else()
    message (FATAL_ERROR "Cannot find Boost")
endif()

find_package(glog REQUIRED)
if(glog_FOUND)
    message("glog found ${glog_INCLUDE_DIRS},version:${glog_VERSION},libs:${glog_LIBRARIES}...")
else()
    message(FATAL_ERROR "glog not found...")
endif()

# not find var, but can -ljsoncpp link  for work normal 
find_package(jsoncpp REQUIRED)
if(jsoncpp_FOUND)
    message("--> find jsoncpp ${jsoncpp_INCLUDE_DIRS}...")
    message("--> find jsoncpp version:${jsoncpp_VERSION}")
    message("--> find jsoncpp LIBs:${jsoncpp_LIBRARIES}")
else()
    message(FATAL_ERROR "jsoncpp not found...")
endif()
# include_directories("/usr/include/jsoncpp")


# Add an executable
add_executable(third_party_include main.cpp)

# link against the boost libraries
target_link_libraries( third_party_include
    PRIVATE
        Boost::filesystem
        glog::glog
        -ljsoncpp
)
