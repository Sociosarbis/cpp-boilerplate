#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
      int m = nums.size();
      int n = nums[0].size();
      if (m * n != r * c) return nums;
      vector<vector<int>> ret = vector<vector<int>>(r, vector<int>(c, 0));
      for (int i = 0;i < m;i++) {
        int base = i * n;
        for (int j = 0;j < n;j++) {
          int t = base + j;
          int t1 = t / c;
          int t2 = t % c;
          ret[t1][t2] = nums[i][j];
        }
      }
      return ret;
    }
};

struct Suite {
  vector<vector<int>> nums;
  int r;
  int c;
  vector<vector<int>> ret;
};

TEST(matrixReshape, Simple) {
  vector<Suite> suites = {
    {
      {{1,2},{3,4}},
      1,
      4,
      {{1,2,3,4}},
    },
    {
      {{1,2},{3,4}},
      2,
      4,
      {{1,2},{3,4}},
    }
  };

  Solution s;

  for (auto su:suites) {
    ASSERT_EQ(s.matrixReshape(su.nums, su.r, su.c), su.ret);
  }
}