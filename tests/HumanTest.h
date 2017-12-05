
#ifndef EX4_HUMANTEST_H
#define EX4_HUMANTEST_H
#include "../gtest_src/gtest.h"
#include "../include/Human.h"

class HumanTest: public testing::Test {
public:
    HumanTest();
    virtual void SetUp();
    virtual void TearDown();
};


#endif //EX4_HUMANTEST_H
