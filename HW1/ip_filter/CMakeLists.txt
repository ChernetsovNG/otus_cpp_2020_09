cmake_minimum_required(VERSION 3.10)

project(ip_filter)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(ip_filter src/main.cpp)
add_library(ip_filter_lib src/lib.cpp)
add_executable(test_split test/test_split.cpp)
add_executable(test_check_ip test/test_check_ip.cpp)
add_executable(test_sort test/test_sort.cpp)

set_target_properties(ip_filter ip_filter_lib test_split test_check_ip test_sort PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_include_directories(ip_filter_lib
        PRIVATE "${CMAKE_BINARY_DIR}"
        )
set_target_properties(test_split test_check_ip test_sort PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_link_libraries(ip_filter PRIVATE
        ip_filter_lib
        )
target_link_libraries(test_split
        ${Boost_LIBRARIES}
        ip_filter_lib
        )
target_link_libraries(test_check_ip
        ${Boost_LIBRARIES}
        ip_filter_lib
        )
target_link_libraries(test_sort
        ${Boost_LIBRARIES}
        ip_filter_lib
        )

if (MSVC)
    target_compile_options(ip_filter PRIVATE
            /W4
            )
    target_compile_options(ip_filter_lib PRIVATE
            /W4
            )
    target_compile_options(test_split PRIVATE
            /W4
            )
    target_compile_options(test_check_ip PRIVATE
            /W4
            )
    target_compile_options(test_sort PRIVATE
            /W4
            )
else ()
    target_compile_options(ip_filter PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(ip_filter_lib PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(test_split PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(test_check_ip PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(test_sort PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
endif ()

enable_testing()

add_test(test_split test_split)
add_test(test_check_ip test_check_ip)
add_test(test_sort test_sort)
