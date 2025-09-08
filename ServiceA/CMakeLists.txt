project(ServiceA)

add_executable(service-a src/main.cpp)
target_link_libraries(service-a pthread)