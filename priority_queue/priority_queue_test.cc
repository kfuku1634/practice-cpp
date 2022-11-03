#include <gtest/gtest.h>
#include "priority_queue.h"
#include <string>

TEST(PriorityQueueTest, PriorityQueueString) {
  kf::priority_queue<std::string> pq;

  pq.push("b");
  pq.push("a");
  EXPECT_EQ(pq.top(), "b");
  
}

TEST(PriorityQueueTest, PriorityQueueInt) {
  kf::priority_queue<int> pq;
  EXPECT_EQ(pq.size(), 0);
  EXPECT_TRUE(pq.empty());
  pq.push(10);
  EXPECT_EQ(pq.top(), 10);
  EXPECT_EQ(pq.capacity(), 1);
  EXPECT_EQ(pq.size(), 1);
  EXPECT_FALSE(pq.empty());

  pq.push(20);
  EXPECT_EQ(pq.top(), 20);
  EXPECT_EQ(pq.size(), 2);
  EXPECT_EQ(pq.capacity(), 2);

  pq.push(5);
  EXPECT_EQ(pq.top(), 20);
  EXPECT_EQ(pq.size(), 3);
  EXPECT_EQ(pq.capacity(), 4);

}
