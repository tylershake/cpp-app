# Copyright [year] [organization]
#
# Build file for cpp tests
#

add_executable(test_example test_example.cpp)
target_link_libraries(test_example cpputils gtest boost_log pthread boost_thread boost_system boost_log_setup boost_program_options boost_filesystem)
