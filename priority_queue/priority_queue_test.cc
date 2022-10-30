#include <gtest/gtest.h>
#include "priority_queue.h"

TEST(PriorityQueueTest, PriorityQueueHoge) {
  kf::priority_queue pq;
  EXPECT_EQ(pq.size(), 0);
}
