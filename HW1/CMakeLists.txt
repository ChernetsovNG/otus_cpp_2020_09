cmake_minimum_required(VERSION 3.10)

# project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
project(helloworld VERSION 0.0.10)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_subdirectory(version)
add_subdirectory(ip_filter)

configure_file(version/src/include/version.h.in version.h)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT n.chernetsov86@gmail.com)

include(CPack)

enable_testing()
