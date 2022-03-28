#include "gtest/gtest.h"

class Solution {
public:
    bool hasAlternatingBits(int n) {
        auto prev = n & 1;
        n >>= 1;
        while (n != 0) {
            auto temp = n & 1;
            if (temp == prev) {
                return false;
            }
            prev = temp;
            n >>= 1;
        }
        return true;
    }
};


struct Suite {
    int n;
    bool ret;
};

TEST(hasAlternatingBits, Simple) {
    Suite suites[] = {
        {
            5,
            true,
        },
        {
            7,
            false,
        },
        {
            11,
            false,
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.hasAlternatingBits(su.n));
    }
}

