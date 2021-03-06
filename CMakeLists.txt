cmake_minimum_required(VERSION 3.2)

project(HW2_IP_FILTER VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in version.h)

add_executable(HW2_IP_FILTER ip_filter.cpp ip_filter.h main.cpp)

add_library(version_lib version.cpp)

set_target_properties(HW2_IP_FILTER PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(HW2_IP_FILTER version_lib)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(version_test test.cpp)
target_link_libraries(version_test
  ${GTEST_BOTH_LIBRARIES}
  version_lib
  pthread
)

set_target_properties(HW2_IP_FILTER version_test PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(version_test PROPERTIES
  INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT elektronchikone@mail.ru)

include (CPack)

add_test(test_version_valid version_test)