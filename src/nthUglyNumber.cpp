#include <vector>
#include "gtest/gtest.h"
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
      if (n == 1) return 1;
      vector<int> dp = { 1 };
      // 维护2，3，5三个因数序列，每次从中取最小的那个作为下一个丑数
      int indices[] = {0, 0, 0};
      int nums[] = {2, 3, 5};
      while (dp.size() < n) {
        if (nums[0] <= nums[1] && nums[0] <= nums[2]) {
          if (dp.back() < nums[0]) {
            dp.push_back(nums[0]);
          }
          indices[0]++;
          nums[0] = dp[indices[0]] * 2;
        } else if (nums[1] <= nums[0] && nums[1] <= nums[2]) {
          if (dp.back() < nums[1]) {
            dp.push_back(nums[1]);
          }
          indices[1]++;
          nums[1] = dp[indices[1]] * 3;
        } else {
          if (dp.back() < nums[2]) {
            dp.push_back(nums[2]);
          }
          indices[2]++;
          nums[2] = dp[indices[2]] * 5;
        }
      }
      return dp.back();
    }
};


struct Suite {
  int n;
  int ret;
};

vector<Suite> suites = {
  {
    10,
    12
  },
  {
    1,
    1
  }
};


TEST(nthUglyNumber, Simple) {
  Solution s;
  for (auto item:suites) {
    ASSERT_EQ(s.nthUglyNumber(item.n), item.ret);
  }
}