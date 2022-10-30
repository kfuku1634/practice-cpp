#include <gtest/gtest.h>
#include "priority_queue.h"

TEST(PriorityQueueTest, PriorityQueueEmpty) {
  kf::priority_queue pq;
  EXPECT_EQ(pq.size(), 0);
  EXPECT_EQ(pq.empty(), true);
}
