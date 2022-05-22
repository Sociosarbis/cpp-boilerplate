#include "gtest/gtest.h"
#include <map>

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
         if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
            return false;
        }
        if (desiredTotal <= maxChoosableInteger) {
            return true;
        }
        return dfs(0, maxChoosableInteger, desiredTotal, 0, 0, unordered_map<int, bool>());
    }

    bool dfs(int mask, int maxChoosableInteger, int  desiredTotal, int temp, int turn, unordered_map<int, bool>& dp) {
        if (dp.find(mask) != dp.end()) {
            return dp[mask];
        }
        auto target = (turn & 1) == 0 ? true : false;
         for (auto i = 1;i <= maxChoosableInteger;i++) {
                if ((mask & (1 << (i - 1))) == 0) {
                    auto nextTemp = temp + i;
                    if (nextTemp >= desiredTotal) {
                        dp.insert({ mask, target });
                        return target;
                    }
                    auto nextMask = mask | (1 << (i - 1));
                    auto ret = dfs(nextMask, maxChoosableInteger, desiredTotal, nextTemp, turn + 1, dp);
                    if (ret == target) {
                        dp.insert({ mask, target });
                        return target;
                    }
                }
        }
        dp.insert({ mask, target });
        return !target;
    }
};


struct Suite {
    int maxChoosableInteger;
    int desiredTotal;
    bool ret;
};

TEST(canIWin, Simple) {
    Suite suites[] = {
        {
            10,
            11,
            false
        },
        {
            10,
            0,
            true
        },
        {
            10,
            1,
            true
        },
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.canIWin(su.maxChoosableInteger, su.desiredTotal));
    }
};

