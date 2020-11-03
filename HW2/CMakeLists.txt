cmake_minimum_required(VERSION 3.10)

project(HW2)

add_executable(program program.cpp)

set_target_properties(program PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON)

if (MSVC)
    target_compile_options(program PRIVATE
            /W4
            )
else ()
    target_compile_options(program PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif ()
