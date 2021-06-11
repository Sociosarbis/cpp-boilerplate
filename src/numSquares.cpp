#include "gtest/gtest.h"

class Solution {
public:
    int numSquares(int n) {
      int i = 2;
      int iSquare = i * i;
      int* dp = new int[n + 1]{ 0 };
      dp[1] = 1;
      for (int j = 2;j <= n;j++) {
        if (j == iSquare) {
          dp[j] = 1;
          i += 1;
          iSquare = i * i;
        } else {
          int min = j;
          int halfJ = j >> 1;
          for (int k = 1;k < i;k++) {
            int square = k * k;
            if (square > halfJ) break;
            int nextMin = dp[square] + dp[j - square];
            if (nextMin < min) {
              min = nextMin;
            }
          }
          dp[j] = min;
        }
      }
      return dp[n];
    }
};

struct Suite {
  int n;
  int ret;
};


TEST(numSquares, Simple) {
  Suite suites[] = {
    {
      12,
      3
    },
    {
      13,
      2
    },
    {
      9999,
      4
    },
    {
      9998,
      3,
    },
    {
      10000,
      1
    },
    {
      5,
      2
    }
  };

  Solution s;

  for (auto su:suites) {
    ASSERT_EQ(su.ret, s.numSquares(su.n));
  }
}

