cmake_minimum_required(VERSION 3.10)

# project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
project(helloworld VERSION 0.0.10)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_subdirectory(version)
add_subdirectory(ip_filter)

configure_file(version/src/include/version.h.in version.h)
