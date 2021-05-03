#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int reverse(int x) {
      int min = -2147483648;
      if (x == min) {
        return 0;
      }
      int sign = x < 0 ? -1 : 1;
      x /= sign;
      vector<int> digits;
      int base = 1;
      while (x != 0) {
        digits.push_back(x % 10);
        x /= 10;
      }
      if (digits.size() == 10 && digits[0] > 2) {
        return 0;
      }
      int ret = 0;
      for (int i = digits.size() - 1;i >= 0;i--) {
        int digit = digits[i];
        if (i == 0 && digits.size() == 10 && digit == 2 && 147483647 < ret) {
          return 0;
        }
        ret += digit * base;
        if (i != 0) {
          base *= 10;
        }
      }
      return ret * sign;
    }
};

struct Suite {
  int x;
  int ret;
};


vector<Suite> suites = {
  {
    123,
    321
  },
  {
    -123,
    -321
  },
  {
    120,
    21
  },
  {
    0,
    0
  }
};


TEST(reverse, Simple) {
  Solution s;
  for (auto su:suites) {
    ASSERT_EQ(s.reverse(su.x), su.ret);
  }
}
