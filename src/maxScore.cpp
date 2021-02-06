#include <vector>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int i = 0;
      int tmp = 0;
      int ret = 0;
      for (;i < k;i++) {
        tmp += cardPoints[i];
      }
      i--;
      ret = tmp;
      for (int j = 1;j <= k;j++) {
        tmp += cardPoints[cardPoints.size() - j] - cardPoints[i];
        if (tmp > ret) {
          ret = tmp;
        }
        i--;
      }
      return ret;
    }
};

struct Suite {
  vector<int> cardPoints;
  int k;
  int ret;
};

TEST(maxScore, Simple) {
  Solution s;
  vector<Suite> suites = {
    {
      {1,2,3,4,5,6,1},
      3,
      12
    },
    {
      {2,2,2},
      2,
      4
    },
    {
      {9,7,7,9,7,7,9},
      7,
      55
    },
    {
      {1,1000,1},
      1,
      1
    },
    {
      {1,79,80,1,1,1,200,1},
      3,
      202
    }
  };

  for (auto su:suites) {
    ASSERT_EQ(s.maxScore(su.cardPoints, su.k), su.ret);
  }
}