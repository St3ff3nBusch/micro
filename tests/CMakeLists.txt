cmake_policy(SET CMP0135 NEW)
add_executable(test_service test_service.cpp)
target_include_directories(test_service PRIVATE ../include)

# GoogleTest via FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

target_link_libraries(test_service gtest_main)
add_test(NAME TestService COMMAND test_service)