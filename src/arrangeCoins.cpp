#include "gtest/gtest.h"

class Solution {
public:
    int arrangeCoins(int n) {
        int l = 1;
        int r = 65535;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int sum = (mid & 1) == 1 ? ((mid + 1) >> 1) * mid : (mid >> 1) * (mid + 1);
            if (sum < n) {
                l = mid + 1;
            } else if (sum > n) {
                r = mid - 1;
            } else {
                return mid;
            }
        }
        return r;
    }
};

struct Suite {
    int n;
    int ret;
};

TEST(arrangeCoins, Simple) {
    Suite suites[] = {
        {
            5,
            2
        },
        {
            8,
            3
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.arrangeCoins(su.n));
    }
}


