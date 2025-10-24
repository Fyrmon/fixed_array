#include <gtest/gtest.h>
#include "fixedArray.hpp"

// Demonstrate some basic assertions.
TEST(FixedArrayTest, Creation)
{
  // creation of the fixedarray?
  FixedArray<int,3> arr{1,2,3};
  EXPECT_EQ(arr.size(),3);
}
