project(ServiceB)

add_executable(service-b src/main.cpp)
target_link_libraries(service-b pthread)