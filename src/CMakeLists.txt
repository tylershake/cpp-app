# Copyright [year] [organization]
#
# Build file for cpp apps
#

add_executable(example_cpp_app example_cpp_app.cpp)
target_link_libraries(example_cpp_app cpputils boost_log pthread boost_thread boost_system boost_log_setup boost_program_options boost_filesystem)
install(TARGETS example_cpp_app DESTINATION bin)
