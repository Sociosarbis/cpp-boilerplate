#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int dp[2][3] = {{0,0,0},{0,0,0}};
        copy(costs[0].begin(), costs[0].end(), dp[0]);
        for (auto i = 1;i < costs.size();i++) {
            auto index = i & 1;
            auto prevIndex = 1 - index;
            for (auto j = 0;j < 3;j++) {
                for (auto k = 0;k < 3;k++) {
                    if (j != k) {
                        auto temp = dp[prevIndex][k] + costs[i][j];
                        if (dp[index][j] == 0 || dp[index][j] > temp) {
                            dp[index][j] = temp;
                        }
                    }
                }
            }
            memset(dp[prevIndex], 0, sizeof dp[prevIndex]);
        }
        auto index = (costs.size() - 1) & 1;
        auto ret = dp[index][0];
        for (auto i = 1;i < 3;i++) {
            if (dp[index][i] < ret) {
                ret = dp[index][i];
            }
        }
        return ret;
    }
};



struct Suite {
    vector<vector<int>> costs;
    int ret;
};


TEST(minCost, Simple) {
    Suite suites[] = {
        {
            {{17,2,17},{16,16,5},{14,3,19}},
            10,
        },
        {
            {{7,6,2}},
            2
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.minCost(su.costs));
    }
};

