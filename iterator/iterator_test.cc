#include <gtest/gtest.h>
#include "iterator.h"

TEST(IteratorTest, Iterator) {
  kf::iterator it;
  EXPECT_EQ(it.hoge(), 1);
}