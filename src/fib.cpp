#include "gtest/gtest.h"

class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int dp[] = { 0 , 1 };
        for (int i = 2;i <= n;i++) {
            dp[i & 1] = (dp[0] + dp[1]) % 1000000007;
        }
        return dp[n&1];
    }
};

struct Suite  {
    int n;
    int ret;
};

TEST(fib, Simple) {
    Suite suites[] = {
        {
            2,
            1,
        },
        {
            5,
            5,
        },
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.fib(su.n));
    }
}