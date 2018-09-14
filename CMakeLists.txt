cmake_minimum_required(VERSION 3.10)
project(Uni_INI)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(test)

set(SOURCE_FILES INI.cpp INI.h)
add_executable(INI_executable main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(INI_executable core)


