#include <gtest/gtest.h>
#include "vector.h"

TEST(VectorTest, VectorPush) {
  kf::vector vec;
  EXPECT_EQ(vec.size(), 0);
  EXPECT_EQ(vec.empty(), true);
  vec.push_back(10);
  EXPECT_EQ(vec.at(0), 10);

}
