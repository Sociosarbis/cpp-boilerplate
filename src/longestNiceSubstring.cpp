#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        auto ret = string("");
        for (unsigned int i = 0;i < s.size();i++) {
            if (ret.size() >= s.size() - i) {
                break;
            }
            auto mask = 0;
            int counter[58] = {0};
            for (unsigned int j = i;j < s.size();j++) {
                auto c = s[j]  - 65;
                counter[c]++;
                if (c >= 32) {
                    auto c1 = c - 32;
                    if (counter[c1] != 0) {
                        if ((mask & (1 << c1)) != 0) {
                            mask -= 1 << c1;
                        }
                    } else {
                        mask |= 1 << c1;
                    }
                } else {
                    auto c1 = c + 32;
                    if (counter[c1] != 0) {
                        if ((mask & (1 << c)) != 0) {
                            mask -= 1 << c;
                        }
                    } else {
                        mask |= 1 << c;
                    }
                }
                if (mask == 0 && j - i + 1 > ret.size()) {
                    ret = s.substr(i, j - i + 1);
                }
            }
        }
        return ret;
    }
};



struct Suite {
    string s;
    string ret;
};


TEST(longestNiceSubstring, Simple) {
    Suite suites[] = {
        {
            "YazaAay",
            "aAa"
        },
        {
            "Bb",
            "Bb"
        },
        {
            "c",
            ""
        }
    };

    Solution s;

    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.longestNiceSubstring(su.s));
    }
}

