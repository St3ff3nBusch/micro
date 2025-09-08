#include "service.hpp"
#include <gtest/gtest.h>

TEST(ServiceTest, Hello) {
    EXPECT_EQ(hello(), "Hello from C++ Microservice!");
}
