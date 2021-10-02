#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        bool isNegative = num < 0;
        if (isNegative) {
            num = 2147483647 + num + 1;
        }
        int offset = 28;
        string ret;
        int temp = (num >> 28) | (isNegative ? 8 : 0);
        if (temp > 0) {
            ret.push_back(toChar(temp));
        }
        for (int i = 0;i < 7;i++) {
            offset -= 4;
            temp = (num >> offset) & 15;
            if (!(temp == 0 && ret.empty())) {
                ret.push_back(toChar(temp));
            }
        }
        return ret;
    }

    char toChar(int num) {
        return num < 10 ? char(48 + num) : char(97 + num - 10);
    }
};

struct Suite {
    int num;
    string ret;
};

TEST(toHex, Simple) {
    Suite suites[] = {
        {
            26,
            "1a"
        },
        {
            -1,
            "ffffffff"
        },
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.toHex(su.num));
    }
}