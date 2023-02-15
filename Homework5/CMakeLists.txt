# Comments | Program by:

cmake_minimum_required(VERSION "3.16")

# Project Name
project(Homework5)

# C++ Compiler Version
set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

#include directories with opencv headers
include_directories( ${OpenCV_INCLUDE_DIRS} )

#unnecessary to show the includes
message( ${OpenCV_INCLUDE_DIRS} )
message(${CMAKE_CURRENT_LIST_DIR}/includes/video_base.cpp)
message(${CMAKE_CURRENT_LIST_DIR}/includes/video_base.h)

set(SOURCES homework5.cpp ${CMAKE_CURRENT_LIST_DIR}/includes/video_base.cpp)
set(HEADERS ${CMAKE_CURRENT_LIST_DIR}/includes/video_base.h)

# -o output option for makefiles
add_executable(homework5.o ${SOURCES} ${HEADERS})

target_link_libraries(homework5.o ${OpenCV_LIBS})
