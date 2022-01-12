#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        auto options = vector<vector<int>> {
            { nums[0] }
        };
        for (unsigned int i = 1;i < nums.size();i++) {
            auto used = false;
            for (auto &option:options) {
                if (option.back() < nums[i]) {
                    option.push_back(nums[i]);
                    used = true;
                    if (option.size() == 3) {
                        return true;
                    }
                } else if (option.back() > nums[i] && option[0] < nums[i]) {
                    option.back() = nums[i];
                    used = true;
                }
            }
            if (!used) {
                options.push_back({ nums[i] });
            }
            if (options.size() > 1 && options[0].size() == options[1].size()) {
                options.erase(options.begin());
            }
        }
        return false;
    }
};


struct Suite {
    vector<int> nums;
    bool ret;
};


TEST(increasingTriplet, Simple) {
    Suite suites[] = {
        {
            {1,2,3,4,5},
            true
        },
        {
            {5,4,3,2,1},
            false
        },
        {
            {2,1,5,0,4,6},
            true
        },
    };


    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.increasingTriplet(su.nums));
    }
}