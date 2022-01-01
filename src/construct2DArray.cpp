#include <vector>
#include "gtest/gtest.h"

using namespace std;


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m * n) return {};
        auto ret = vector<vector<int>>(m, vector<int>(n));
        auto it = original.begin();
        for (auto &row:ret) {
            for (auto &cell:row) {
                cell = *it++;
            }
        }
        return ret;
    }
};


struct Suite {
    vector<int> orignial;
    int m;
    int n;
    vector<vector<int>> ret;
};


TEST(contruct2DArray, Simple) {
    Suite suites[] = {
        {
            {1,2,3,4},
            2,
            2,
            {{1,2},{3,4}}
        },
        {
            {1,2,3},
            1,
            3,
            {{1,2,3}}
        },
        {
            {1,2},
            1,
            1,
            {}
        },
    };


    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.construct2DArray(su.orignial, su.m, su.n));
    }
}


