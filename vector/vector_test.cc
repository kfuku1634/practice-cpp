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
  for( int i=0; i < 10; i++){
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
    EXPECT_EQ( vec1.back(), "c" );
    EXPECT_EQ( vec1.at(1), "b" );

    vec1.push_back("d");

}

TEST(VectorTest, VectorInsert){
    kf::vector<std::string> vec = {"a", "b", "c"};

    vec.insert(1, "d");
    EXPECT_EQ( vec.at(1), "d" );
    vec.insert(0, "k");
    EXPECT_EQ( vec.at(0), "k" );
    vec.insert(4, "n");
    EXPECT_EQ( vec.at(4), "n" );
}


TEST(VectorTest, VectorInsertWithFirstElement){
    kf::vector<std::string> vec;

    vec.insert(0, "b");
    vec.insert(0, "a");
    EXPECT_EQ( vec.back(), "b" );
}

TEST(VectorTest, VectorPushBackWithFirstElement){
    kf::vector<std::string> vec;
    vec.push_back("b");
    EXPECT_EQ( vec.back(), "b" );
}
