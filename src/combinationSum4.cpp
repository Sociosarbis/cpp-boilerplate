#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int min = nums.front();
      if (target < min) {
        return 0;
      }
      vector<int> dp = vector<int>(target - min + 1, 0);
      for (int n:nums) {
        if (n > target) break;
        dp[n - min] = 1;
      }
      int num = min;
      while (num <= target) {
        for (int n:nums) {
          int rest = num - n;
          if (rest >= min) {
            if (dp[rest - min] > 0) {
              if (2147483647 - dp[num - min] >= dp[rest - min]) {
                dp[num - min] += dp[rest - min];
              }
            }
          } else {
            break;
          }
        }
        num++;
      }
      return dp.back();
    }
};


struct Suite {
  vector<int> nums;
  int target;
  int ret;
};

TEST(CombinationSum4, Simple) {
  vector<Suite> suites = {
    Suite {
      { 1, 2, 3 },
      4,
      7,
    },
    Suite {
      { 9 },
      3,
      0
    },
    Suite {
      {1,2},
      10,
      89
    },
    Suite {
      {10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300,310,320,330,340,350,360,370,380,390,400,410,420,430,440,450,460,470,480,490,500,510,520,530,540,550,560,570,580,590,600,610,620,630,640,650,660,670,680,690,700,710,720,730,740,750,760,770,780,790,800,810,820,830,840,850,860,870,880,890,900,910,920,930,940,950,960,970,980,990,111},
      999,
      1
    }
  };

  Solution s;
  for (auto su:suites) {
    ASSERT_EQ(s.combinationSum4(su.nums, su.target), su.ret);
  }
}