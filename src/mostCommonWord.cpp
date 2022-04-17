#include <string>
#include <map>
#include <set>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        set<string> bannedSet;
        map<string, int> counter;
        paragraph.push_back(' ');
        for (auto b:banned) {
            bannedSet.insert(b);
        }
        string temp;
        for (auto c:paragraph) {
            if (c >= 97 && c <= 122) {
                temp.push_back(c);
            } else if (c >= 65 && c <= 90) {
                temp.push_back(c + 32);
            } else {
                if (!temp.empty()) {
                    if (bannedSet.find(temp) == bannedSet.end()) {
                        if (counter.find(temp) == counter.end()) {
                            counter.insert({temp, 0});
                        }
                        counter[temp]++;
                    }
                    temp.clear();
                }
            }
        }

        string ret;
        auto max = 0;

        for (auto e:counter) {
            if (e.second > max) {
                max = e.second;
                ret = e.first;
            }
        }
        return ret;
    }
};


struct Suite {
    string paragraph;
    vector<string> banned;
    string ret;
};

TEST(mostCommonWord, Simple) {
    Suite suites[] = {
        {
            "Bob hit a ball, the hit BALL flew far after it was hit.",
            {"hit"},
            "ball"
        },
        {
            "a.",
            {},
            "a"
        },
    };

    Solution s;

    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.mostCommonWord(su.paragraph, su.banned));
    }
}