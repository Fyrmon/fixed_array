#include <gtest/gtest.h>
#include "fixedArray.hpp"


using TestArrA = FixedArray<int,5>;
using TestArrB = FixedArray<int,4>;
class FixedArrayTest : public ::testing::Test
{
  protected:
    TestArrA a{ 1, 2, 3, 4, 5};
    TestArrB b{ 6, 7, 8, 9 };

};

TEST_F(FixedArrayTest, CorrectSize)
{
  EXPECT_EQ(a.size(), 5);
  EXPECT_EQ(b.size(), 4);
}