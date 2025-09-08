cmake_minimum_required(VERSION 3.15)
project(opus_l_prep LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main service
add_executable(microservice src/main.cpp)
target_include_directories(microservice PRIVATE include)
find_package(Threads REQUIRED)
target_link_libraries(microservice PRIVATE Threads::Threads)
# GoogleTest
enable_testing()
add_subdirectory(tests)