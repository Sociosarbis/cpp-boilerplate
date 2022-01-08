#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        auto ret = vector<int>(1 << n);
        auto temp = 0;
        unsigned int i = 1;
        dfs(ret, temp, i, 0);
        return ret;
    }

    void dfs(vector<int> &ret, int &temp, unsigned int &i, int j) {
        if (i < ret.size() && (unsigned int)(1 << j) < ret.size()) {
            temp |= 1 << j;
            ret[i++] = temp;
            dfs(ret, temp, i, j + 1);
            temp -= 1 << j;
            dfs(ret, temp, i, j + 1);
        }
    }
};


struct Suite {
    int n;
    vector<int> ret;
};


TEST(grayCode, Simple) {
    Suite suites[] = {
        {
            2,
            {0,1,3,2},
        },
        {
            1,
            {0,1},
        }
    };

    Solution s;

    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.grayCode(su.n));
    }
}