cmake_minimum_required(VERSION 3.20)
project(CPP_HW1)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)
add_executable(CPP_HW1 main.cpp src/BigInteger.cpp src/BigInteger.h tests/BigIntTests.cpp)
target_link_libraries(CPP_HW1 gtest)
