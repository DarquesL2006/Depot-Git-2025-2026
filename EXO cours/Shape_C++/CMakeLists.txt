cmake_minimum_required (VERSION 3.9)

project(Shape)

if(NOT MSVC)
    link_libraries(m) #to link with libm on Unix 
endif()

add_executable (Shape "shape.cpp" "main.cpp")
