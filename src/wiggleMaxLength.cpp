#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
      if (nums.size() < 2) return nums.size();
      int dp[3] = { 1, nums[0], 0 };
      for (int i = 1;i < nums.size();i++) {
        int num = nums[i];
        int nextDp[3] = { 0, num, 0 };

        int prevDiff = dp[2];
        int curDiff = num - dp[1];
        if (curDiff != 0 && (prevDiff == 0 || (curDiff ^ prevDiff) < 0)) {
        if (nextDp[0] < dp[0] + 1) {
            nextDp[0] = dp[0] + 1;
            nextDp[2] = curDiff;
        }
        } else {
        if (nextDp[0] < dp[0]) {
            nextDp[0] = dp[0];
            nextDp[2] = curDiff + prevDiff;
        }
        }
        copy(&nextDp[0], &nextDp[0] + 3, &dp[0]);
      }
      return dp[0];
    }
};


TEST(WiggleMaxLength, Simple) {
  vector<int> nums1 = { 1,7,4,9,2,5 };
  vector<int> nums2 = { 1,17,5,10,13,15,10,5,16,8 };
  vector<int> nums3 = { 1,2,3,4,5,6,7,8,9 };
  Solution s;
  ASSERT_EQ(s.wiggleMaxLength(nums1), 6);
  ASSERT_EQ(s.wiggleMaxLength(nums2), 7);
  ASSERT_EQ(s.wiggleMaxLength(nums3), 2);
}