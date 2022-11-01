#include <gtest/gtest.h>
#include <string>
#include "vector.h"

TEST(VectorTest, VectorPush) {
  kf::vector<int> vec;
  EXPECT_EQ(vec.size(), 0);
  EXPECT_EQ(vec.empty(), true);
  for( int i=0; i < 1000; i++){
      vec.push_back(i);
  }
  for( int i=0; i < 1000; i++){
    EXPECT_EQ(vec.at(i), i);
  }
  for( int i=0; i < 1000; i++){
    int& x=vec.back();
    EXPECT_EQ(x, 999 - i);
    vec.pop_back();
  }

}

TEST(VectorTest, VectorIter){
    kf::vector<int> vec = {1,2,3,4,5};
    int n = 0;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        n++;
        EXPECT_EQ(*it, n);
    }
}

TEST(VectorTest, VectorEqual){
    kf::vector<int> vec1 = {1,2,3,4,5};
    kf::vector<int> vec2 = {1,2,3,4,5};

    EXPECT_TRUE( vec1 == vec2 );

    kf::vector<int> vec3 = {1,1,1,1,1};
    EXPECT_FALSE( vec1 == vec3 );

}

TEST(VectorTest, VectorVariousType){
    kf::vector<std::string> vec1 = {"a", "b", "c"};
    kf::vector<std::string> vec2 = {"a", "b", "c"};

    EXPECT_EQ( vec1, vec2 );

}
