#include "gtest/gtest.h"
#include "practice03.cpp"
class MathUtilsTest : public ::testing::Test {};

TEST_F(MathUtilisTest, SumRangeTest)
{
    EXPECT_EQ(MathUtilis::sumRange(1,5), 10);
}
