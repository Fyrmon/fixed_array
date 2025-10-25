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

TEST_F(FixedArrayTest, FrontCheck)
{
  EXPECT_EQ(a.front(),1);
  EXPECT_NE(a.front(),2);

  EXPECT_EQ(b.front(),6);
  EXPECT_NE(b.front(),7);
}

TEST_F(FixedArrayTest, BackCheck)
{
  EXPECT_EQ(a.back(),5);
  EXPECT_NE(a.back(),4);

  EXPECT_EQ(b.back(),9);
  EXPECT_NE(b.back(),10);
}

TEST_F(FixedArrayTest, BeginCheck)
{
  EXPECT_EQ(a.begin(), &a.front());
  EXPECT_NE(a.begin(),&a[1]);
  EXPECT_NE(a.begin(), b.begin());
  EXPECT_NE(a.begin(), a.end());

  EXPECT_EQ(b.begin(), &b.front());
  EXPECT_NE(b.begin(), &b[1]);
  EXPECT_NE(b.begin(), a.begin());
  EXPECT_NE(b.begin(), b.end());
}

TEST_F(FixedArrayTest, EndCheck)
{
  EXPECT_EQ(a.end(), &a.back()+1);
  EXPECT_NE(a.end(), a.begin());
  EXPECT_NE(a.end(), b.end());

  EXPECT_EQ(b.end(), &b.back()+1);
  EXPECT_NE(b.end(), b.begin());
  EXPECT_NE(b.end(), a.end());
}

TEST_F(FixedArrayTest, EmptyCheck)
{
  FixedArray<int,0> arr;
  EXPECT_EQ(arr.empty(),1);
  EXPECT_EQ(a.empty(),0);
}

TEST_F(FixedArrayTest, FillCheck)
{
  TestArrA filled;
  filled.fill(6);
  EXPECT_EQ(filled, (TestArrA{6,6,6,6,6}));

  a.fill(3);
  EXPECT_EQ(a, (TestArrA{3,3,3,3,3}));

  filled.fill(4);
  EXPECT_NE(filled,(TestArrA{2,2,2,2,2}));
}

TEST_F(FixedArrayTest, SwapCheck)
{
  TestArrA c{5,4,3,2,1};
  a.swap(c);
  EXPECT_EQ(a,(TestArrA{5,4,3,2,1}));
  EXPECT_EQ(c, (TestArrA{1,2,3,4,5}));
}