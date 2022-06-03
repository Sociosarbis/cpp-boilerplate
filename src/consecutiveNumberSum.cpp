#include "gtest/gtest.h"

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        auto ret = 1;
        auto target = n * 2;
        for (auto i = 2;i < n;i++) {
            auto temp = target + i - i * i;
            if (temp < 2 * i) {
                break;
            }
            if ((temp % (2 * i)) == 0) {
                ret++;
            }
        }
        return ret;
    }
};


struct Suite {
    int n;
    int ret;
};

TEST(consecutiveNumberSum, Simple) {

    Suite suites[] = {
        {
            5,
            2,
        },
        {
            9,
            3,
        },
        {
            15,
            4,
        },
    };

    Solution s;

    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.consecutiveNumbersSum(su.n));
    }

}