#include <iostream>
#include "gtest/gtest.h"

class MyEnvironment : public ::testing::Environment {
public:
    ~MyEnvironment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override {
        printf("start");
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {
        printf("end");
    }
};

int main(int argc, char** argv) {
    ::testing::AddGlobalTestEnvironment(new MyEnvironment);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
