# Comments | Program by:

cmake_minimum_required(VERSION "3.16")

# Project Name
project(Homework-4)

# C++ Compiler Version
set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

#include directories with opencv headers
include_directories( ${OpenCV_INCLUDE_DIRS} )

#unnecessary to show the includes
message( ${OpenCV_INCLUDE_DIRS} )

# -o output option for makefiles
add_executable(homework4.o homework4.cpp)


target_link_libraries(homework4.o ${OpenCV_LIBS})
