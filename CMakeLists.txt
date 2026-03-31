cmake_minimum_required(VERSION 3.10)
project(str_class)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the main executable (this will be the OJ code submission)
# The OJ expects a file named 'code' in the root directory
add_executable(code test.cpp)

# Optional: Add test executable for local testing
add_executable(test_local test.cpp)
