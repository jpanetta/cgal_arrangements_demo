# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.

cmake_minimum_required(VERSION 3.1...3.23)
project( arrangements_demo )

find_package(CGAL REQUIRED QUIET OPTIONAL_COMPONENTS Core )

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

create_single_source_cgal_program( "point_location_demo.cpp" )
create_single_source_cgal_program( "sphere_arrangement_demo.cpp" )
