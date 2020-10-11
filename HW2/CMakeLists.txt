cmake_minimum_required(VERSION 3.15)

project(HW2)

add_executable(auto_examples_1 auto_examples_2.cpp)
add_executable(auto_examples_2 auto_examples_2.cpp)
add_executable(tuple_examples_1 tuple_examples_1.cpp)

set_target_properties(auto_examples_1 auto_examples_2 tuple_examples_1 PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        )
