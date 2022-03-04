cmake_minimum_required (VERSION 3.8)

project ("gmpl")

add_executable (gmpl "gmpl/gmpl.cpp" "gmpl/gmpl.h")

set_target_properties (gmpl PROPERTIES CXX_STANDARD 20)

