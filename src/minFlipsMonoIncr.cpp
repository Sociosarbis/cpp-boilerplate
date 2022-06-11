#include "gtest/gtest.h"
#include <string>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        auto n = s.size();
        auto count = 0;
        for (auto i = 0;i < n;i++) {
            if (s[i] == '1') {
                count++;
            }
        }
        auto ret = n - count;
        auto prefixCount = s[0] == '1' ? 1 : 0;
        for (auto i = 1;i <= n;i++) {
            auto temp = n - i - (count - prefixCount * 2);
            if (temp < ret) {
                ret = temp;
            }
            if (i < s.size() && s[i] == '1') {
                prefixCount++;
            }
        }
        return ret;
    }
};

struct Suite {
    string s;
    int ret;
};

TEST(minFlipsMnoIncr, Simple) {
    Suite suites[] = {
        {
            "00110",
            1
        },
        {
            "010110",
            2,
        },
        {
            "00011000",
            2
        },
        {
            "11011",
            1
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.minFlipsMonoIncr(su.s));
    }
}

