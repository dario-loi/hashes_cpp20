cmake_minimum_required(VERSION 3.10)

add_executable(test_hashes main.cpp include/hashes.h include/hashes_meta.h)
target_compile_features(test_hashes PRIVATE cxx_std_20)
target_compile_options(test_hashes PRIVATE -Wall -Wextra -Wpedantic -Werror)
target_include_directories(test_hashes PRIVATE include)



