cmake_minimum_required(VERSION 3.15)
project(Microservices)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include httplib globally (adjust path if needed)
include_directories(include)

# Include each service's CMakeLists.txt
add_subdirectory(ServiceB)
add_subdirectory(ServiceA)
add_subdirectory(ServiceC)
add_subdirectory(ServiceD)