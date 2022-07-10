#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), mx = 2 * n - 1;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        dp[0][0] = grid[0][0];
        // 模拟两个人同时从0，0出发，到n-1,n-1时一共摘到的樱桃数量
        for (int k = 1; k < mx; ++k) {
            auto upper = k;
            if (upper > n - 1) {
                upper = n - 1;
            }
            auto lower = 0;
            if (k - n + 1 > 0) {
                lower = k - n + 1;
            }
            for (int i = upper; i >= lower; --i) {
                for (int p = upper; p >= lower; --p) {
                    int j = k - i, q = k - p;
                    if (grid[i][j] == -1 || grid[p][q] == -1) {
                        // 因为dp[i][p]可能是上一步的结果，所以需重置为-1
                        dp[i][p] = -1;
                        continue;
                    }
                    // i,p：都向右移动
                    // i-1,p：向下移动，向右移动
                    // i,p-1：向右移动，向下移动
                    // i-1,p-1： 向下移动，向下移动
                    if (i > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p]);
                    if (p > 0) dp[i][p] = max(dp[i][p], dp[i][p - 1]);
                    if (i > 0 && p > 0) dp[i][p] = max(dp[i][p], dp[i - 1][p - 1]);
                    if (dp[i][p] >= 0) dp[i][p] += grid[i][j] + (i != p ? grid[p][q] : 0);
                }
            }
        }
        return max(dp[n - 1][n - 1], 0);
    }
};


struct Suite {
    vector<vector<int>> grid;
    int ret;
};

TEST(cherryPickup, Simple) {
    Suite suites[] = {
        {
            {{0,1,-1},{1,0,-1},{1,1,1}},
            5
        },
        {
            {{1,1,-1},{1,-1,1},{-1,1,1}},
            0
        },
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.cherryPickup(su.grid));
    }
}