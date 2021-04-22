cmake_minimum_required(VERSION 3.8)
project(test)

set(CMAKE_CXX_STANDARD 14)
add_executable(test main.cpp)



find_package(boost REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(test ${Boost_LIBRARIES})
