#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> dp(nums.size());
        int maxLength = 1;
        for (int i = 0;i < nums.size();i++) {
            int r = nums[i];
            pair<int, int> &p = dp[i];
            p.first = 1;
            p.second = 1;
            for (int j = 0;j < i;j++) {
                if (r > nums[j]) {
                    if (dp[j].first + 1 > p.first) {
                        p.first = dp[j].first + 1;
                        p.second = dp[j].second;
                    } else if (dp[j].first + 1 == p.first) {
                        p.second += dp[j].second;
                    }
                }
            }
            if (p.first > maxLength) {
                maxLength = p.first;
            }
         }
        int ret = 0;
        for (int i = maxLength - 1;i < nums.size();i++) {
            if (dp[i].first == maxLength) {
                ret += dp[i].second;
            }
        }
        return ret;
    }
};

struct Suite {
    vector<int> nums;
    int ret;
};


TEST(findNumberOfLIS, Simple) {
    Suite suites[] = {
        {
            {1,3,5,4,7},
            2
        },
        {
            {2,2,2,2,2},
            5
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.findNumberOfLIS(su.nums));
    }
}