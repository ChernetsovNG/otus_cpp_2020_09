cmake_minimum_required(VERSION 3.10)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
#project(helloworld VERSION 0.0.10)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version/version.h.in version.h)

# version
add_executable(helloworld_cli version/main.cpp)
add_library(helloworld version/lib.cpp)
add_executable(test_version version/test/test_version.cpp)

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        )
target_include_directories(helloworld
        PRIVATE "${CMAKE_BINARY_DIR}"
        )
set_target_properties(test_version PROPERTIES
        COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )

target_link_libraries(helloworld_cli PRIVATE
        helloworld
        )
target_link_libraries(test_version
        ${Boost_LIBRARIES}
        helloworld
        )

# ip_filter
add_executable(ip_filter ip_filter/main.cpp)
add_library(ip_filter_lib ip_filter/lib.cpp)
add_executable(test_split ip_filter/test/test_split.cpp)
add_executable(test_check_ip ip_filter/test/test_check_ip.cpp)
add_executable(test_sort ip_filter/test/test_sort.cpp)

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
    target_compile_options(helloworld_cli PRIVATE
            /W4
            )
    target_compile_options(helloworld PRIVATE
            /W4
            )
    target_compile_options(test_version PRIVATE
            /W4
            )
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
    target_compile_options(helloworld_cli PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(helloworld PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
    target_compile_options(test_version PRIVATE
            -Wall -Wextra -pedantic -Werror
            )
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


install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT n.chernetsov86@gmail.com)

include(CPack)

enable_testing()

add_test(test_version test_version)
add_test(test_split test_split)
add_test(test_check_ip test_check_ip)
add_test(test_sort test_sort)
