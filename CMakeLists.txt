# Copyright [year] [organization]
#
# Top level build file for cpp
#

cmake_minimum_required (VERSION 3.0)
project (example_cpp_app VERSION 1.0.0.0 LANGUAGES CXX)

# Check dependencies
find_package(Boost 1.58 REQUIRED)
find_package(Doxygen 1.8.0 REQUIRED)
find_package(GTest REQUIRED)

# Configure CMAKE
set (CONFIG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/config)
configure_file ("${CONFIG_DIR}/config.hpp.in" "${PROJECT_BINARY_DIR}/config.hpp")
configure_file ("README.md" "${PROJECT_BINARY_DIR}/README.md" COPYONLY)
file(COPY "./html" DESTINATION "${PROJECT_BINARY_DIR}")
file(COPY "./latex" DESTINATION "${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_BINARY_DIR}")
install (FILES ${CONFIG_DIR}/cpp_app.conf DESTINATION ~/.config/${PROJECT_NAME}/ PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ GROUP_WRITE WORLD_READ WORLD_WRITE)

# Compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# add the utils library
add_subdirectory (src/utils)

# add the unit tests
add_subdirectory (tests)
enable_testing()
add_test (NAME test_example COMMAND test_example)

# add the executables
add_subdirectory (src)

# add the docs
configure_file (${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${PROJECT_BINARY_DIR}/Doxyfile)
add_custom_target (docs ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
