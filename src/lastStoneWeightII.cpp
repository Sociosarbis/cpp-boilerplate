#include <vector>
#include <unordered_set>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    // 石头相消的结果，可以看成是加或减各石头的总和
    int lastStoneWeightII(vector<int>& stones) {
      unordered_set<int> dp = { 0 };
      int ret = -1;
      for (auto stone:stones) {
        unordered_set<int> newDp;
        for (auto num:dp) {
          int n1 = num + stone;
          int n2 = num - stone;
          newDp.insert(n1);
          newDp.insert(n2);
        }
        dp = newDp;
      }

      for (auto num:dp) {
        if (num >= 0 && (num < ret || ret == -1)) {
          ret = num;
          if (ret == 0) break;
        }
      }

      return ret;
    }
};


struct Suite {
  vector<int> stones;
  int ret;
};


TEST(lastStoneWeightII, Simple) {
  Suite suites[] = {
    {
      { 2,7,4,1,8,1 },
      1,
    },
    {
      {
        31,26,33,21,40
      },
      5
    },
    {
      {
        1, 2
      },
      1
    }
  };

  Solution s;

  for (auto su:suites) {
    ASSERT_EQ(su.ret, s.lastStoneWeightII(su.stones));
  }
}


