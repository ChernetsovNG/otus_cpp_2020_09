cmake_minimum_required(VERSION 3.10)

project(version)

# version
add_executable(helloworld_cli src/main.cpp)
add_library(helloworld src/lib.cpp)
add_executable(test_version test/test_version.cpp)

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
endif ()

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

enable_testing()

add_test(test_version test_version)
