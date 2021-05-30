#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
      if (n <= 0) return false;
      return (n & (n - 1)) == 0;
    }
};

struct Suite {
  int n;
  int ret;
};

TEST(IsPowerOfTwo, SIMPLE) {
  vector<Suite> suites = {
    {
      1,
      true,
    },
    {
      16,
      true,
    },
    {
      3,
      false
    },
    {
      4,
      true
    },
    {
      5,
      false
    }
  };

  Solution s;
  for (auto su:suites) {
    ASSERT_EQ(su.ret, s.isPowerOfTwo(su.n));
  }
}


