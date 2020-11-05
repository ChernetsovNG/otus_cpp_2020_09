cmake_minimum_required(VERSION 3.10)

project(HW2)

add_executable(program program.cpp allocator.cpp vector.cpp)

add_executable(timus_1409 timus/problem_1409.cpp)
add_executable(timus_1877 timus/problem_1877.cpp)
add_executable(timus_2001 timus/problem_2001.cpp)
add_executable(timus_1264 timus/problem_1264.cpp)
add_executable(timus_1787 timus/problem_1787.cpp)

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
