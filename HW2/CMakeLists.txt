cmake_minimum_required(VERSION 3.10)

project(HW2)

add_executable(auto_examples auto_examples_2.cpp)

set_target_properties(auto_examples PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        )
