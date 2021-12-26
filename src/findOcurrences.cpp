#include <string>
#include <vector>
#include "gtest/gtest.h"

using namespace std;


class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        auto is_same = first == second;
        auto mask = 0;
        vector<string> ret;
        for (unsigned int i = 0;i < text.size();i++) {
            if (text[i] != ' ') {
                unsigned start_i = i;
                while (i < text.size() && text[i] != ' ') {
                    i++;
                }
                auto a = text.substr(start_i, i - start_i);
                if (mask == 3) {
                    ret.push_back(a);
                    mask = is_same ? 1 : 0;
                }
                if ((mask & 1) == 0) {
                    if (a == first) {
                        mask |= 1;
                    }
                } else {
                    if (a == second) {
                        mask |= 2;
                    } else {
                        mask = a == first ? 1 : 0;
                    }
                }
            }
        }
        return ret;
    }
};


struct Suite {
    string text;
    string first;
    string second;
    vector<string> ret;
};


TEST(findOcurrences, Simple) {
    Suite suites[] = {
        {
            "alice is a good girl she is a good student",
            "a",
            "good",
            {"girl","student"}
        },
        {
            "we will we will rock you",
            "we",
            "will",
            {"we","rock"}
        }
    };

    Solution s;
    for  (auto su:suites) {
        ASSERT_EQ(su.ret, s.findOcurrences(su.text, su.first, su.second));
    }
}

