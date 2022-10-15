#include <vector>
#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        uint32_t i = 0;
        int j = 1;
        while (i < target.size()) {
             ret.push_back("Push");
            if (target[i] == j) {
                i++;
            } else {
                ret.push_back("Pop");
            }
            j++;
        }
        return ret;
    }
};


struct Suite {
    vector<int> target;
    int n;
    vector<string> ret;
};

TEST(buildArray, Simple) {
    Suite suites[] = {
        {
            {1,3},
            3,
            {"Push","Push","Pop","Push"},
        },
         {
            {1,3},
            3,
            {"Push","Push","Pop","Push"},
        },
        {
            {1,2,3},
            3,
            {"Push","Push","Push"},
        },
        {
            {1,2},
            4,
            {"Push","Push"},
        },
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.buildArray(su.target, su.n));
    }
};