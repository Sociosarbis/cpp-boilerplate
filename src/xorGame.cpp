#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
      int res = nums[0];
      for (int i = 1;i < nums.size();i++) {
        res ^= nums[i];
      }
      int player = 0;
      while (res != 0) {
        int n = nums.size();
        for (int i = 0;i < nums.size();i++) {
          if ((res ^ nums[i]) != 0) {
            res ^= nums[i];
            nums.erase(nums.begin() + i);
            break;
          }
        }
        if (n == nums.size()) {
          res = 0;
        }
        player = 1 - player;
      }
      return player == 0;
    }
};

struct Suite {
  vector<int> nums;
  bool ret;
};

TEST(xorGame, Simple) {
  vector<Suite> suites = {
    {
      {1, 1, 2},
      false
    }
  };

  Solution s;

  for (auto su:suites) {
    ASSERT_EQ(s.xorGame(su.nums), su.ret);
  }
}