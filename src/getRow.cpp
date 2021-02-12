#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<vector<int>> rows = vector<vector<int>>(2, vector<int>(rowIndex + 1, 1));
      for (int i = 2;i <= rowIndex;i++) {
        int prev = (i & 1) == 0 ? 0 : 1;
        int cur = (i & 1) == 0 ? 1 : 0;
        for (int j = 1;j < i;j++) {
          rows[cur][j] = rows[prev][j - 1] + rows[prev][j];
        }
      }
      return rows[(rowIndex & 1) == 0 ? 1 : 0];
    }
};

struct Suite {
  int rowIndex;
  vector<int> ret;
};

TEST(GetRow, Simple) {
  vector<Suite> suites = {
    {
      3,
      { 1, 3, 3, 1 }
    },
    {
      0,
      { 1 }
    },
    {
      1,
      { 1, 1 }
    }
  };

  Solution s;

  for (auto su:suites) {
    ASSERT_EQ(s.getRow(su.rowIndex), su.ret);
  }
}

