#include <gtest/gtest.h>
#include "vector.h"

TEST(VectorTest, VectorPush) {
  kf::vector vec;
  EXPECT_EQ(vec.size(), 0);
  EXPECT_EQ(vec.empty(), true);
  for( int i=0; i < 1000; i++){
      vec.push_back(i);
  }
  for( int i=0; i < 1000; i++){
    EXPECT_EQ(vec.at(i), i);
  }
}

