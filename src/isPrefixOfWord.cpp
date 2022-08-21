#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto i = 0;
        auto index = 1;
        while (i < sentence.size()) {
            auto j = i;
            while (j < sentence.size() && sentence[j] != ' ') {
                j++;
            }
            if (j - i >= searchWord.size()) {
                if (sentence.substr(i, searchWord.size()) == searchWord) {
                    return index;
                }
            }
            i = j + 1;
            index++;
        }
        return -1;
    }
};



struct Suite {
    string setence;
    string searchWord;
    int ret;
};

TEST(isPrefixOfWord, Simple) {
    Suite suites[] = {
        {
            "i love eating burger",
            "burg",
            4,
        },
        {
            "this problem is an easy problem",
            "pro",
            2,
        },
         {
            "i am tired",
            "you",
            -1,
        },
    };

    Solution s;

    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.isPrefixOfWord(su.setence, su.searchWord));
    }
}