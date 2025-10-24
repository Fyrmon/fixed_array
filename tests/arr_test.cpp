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

TEST_F(FixedArrayTest, AccessingElements)
{
  EXPECT_EQ(a[0], 1);
  EXPECT_EQ(b[1], 7);
}

TEST_F(FixedArrayTest, AccessingElementsWithAt)
{
  EXPECT_EQ(a.at(0), 1);
  EXPECT_EQ(b.at(1), 7);

  EXPECT_NE(a.at(3), 13);
  EXPECT_NE(b.at(2), 66);
}

TEST_F(FixedArrayTest, ChangingElements)
{
  a[0] = 99;
  EXPECT_EQ(a[0], 99);

  b[1] = 33;
  EXPECT_EQ(b[1], 33);
}

TEST_F(FixedArrayTest, EqualityCheck)
{
  TestArrA arr{1,2,3,4,5};
  EXPECT_EQ( a, arr);

  arr[0] = 12;
  EXPECT_NE(a, arr);
}

TEST_F(FixedArrayTest, InequalityCheck)
{
  TestArrA arr{6,7,8,9,10};
  EXPECT_NE( a, arr);

  TestArrA b{1,2,3,4,5};
  EXPECT_EQ( a != b, 0);
}