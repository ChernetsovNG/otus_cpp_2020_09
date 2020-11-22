cmake_minimum_required(VERSION 3.15)

project(print_ip VERSION 0.0.1)

add_executable(print_ip main.cpp)
add_library(print_ip_lib print_ip.cpp)

set_target_properties(print_ip print_ip_lib PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
        )
target_include_directories(print_ip_lib
        PRIVATE "${CMAKE_BINARY_DIR}"
        )

target_link_libraries(print_ip PRIVATE
        print_ip_lib
        )

if (MSVC)
    target_compile_options(print_ip PRIVATE
            /W4
            )
    target_compile_options(print_ip_lib PRIVATE
            /W4
            )
else ()
    target_compile_options(print_ip PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(print_ip_lib PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif ()

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT n.chernetsov86@gmail.com)

include(CPack)
