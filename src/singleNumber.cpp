#include <vector>
#include <memory>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if (nums.size() == 2) return nums;
        int xOr = 0;
        for (auto num:nums) {
            xOr ^= num;
        }
        int i = 0;
        while ((xOr & (1 << i)) == 0) {
            i++;
        }
        int keyBit = 1 << i;
        int num1 = 0;
        for (auto num:nums) {
            if ((num & keyBit) != 0) {
                num1 ^= num;
            }
        }
        return { num1, xOr ^ num1 };
    }
};

struct Suite {
    vector<int> nums;
    vector<int> ret;
};

TEST(singleNumber, Simple) {
    Suite suites[] = {
        {
            {1,2,1,3,2,5},
            {3,5}
        },
        {
            {-1,0},
            {-1,0}
        },
        {
            {0,1},
            {0,1}
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.singleNumber(su.nums));
    }
};
