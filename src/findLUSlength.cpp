#include <string>
#include "gtest/gtest.h"

using namespace std;


class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : a.size() > b.size() ? a.size() : b.size();
    }
};


struct Suite {
    string a;
    string b;
    int ret;
};

TEST(findLUSlength, Simple) {
    Suite suites[] = {
        {
            "aba",
            "cdc",
            3
        },
        {
            "aaa",
            "bbb",
            3
        },
                {
            "aaa",
            "aaa",
            -1
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.findLUSlength(su.a, su.b));
    }
}
