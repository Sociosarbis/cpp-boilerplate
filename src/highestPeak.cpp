#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        auto m = isWater.size();
        auto n = isWater[0].size();
        auto ret = vector<vector<int>>(m, vector<int>(n, 0));
        auto visited = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<pair<unsigned int, unsigned int>> bfs;
        for (unsigned int i = 0;i < m;i++) {
            for (unsigned int j = 0;j < n;j++) {
                if (isWater[i][j] == 1) {
                    bfs.push_back({i, j});
                    visited[i][j] = true;
                }
            }
        }
        auto v = 0;
        while (!bfs.empty()) {
            auto l = bfs.size();
            for (unsigned int i = 0;i < l;i++) {
                auto item = bfs[i];
                if (item.first > 0 && !visited[item.first - 1][item.second]) {
                    bfs.push_back({item.first - 1, item.second});
                    visited[item.first - 1][item.second] = true;
                }
                if (item.first + 1 < m && !visited[item.first + 1][item.second]) {
                    bfs.push_back({item.first + 1, item.second});
                    visited[item.first + 1][item.second] = true;
                }
                if (item.second > 0 && !visited[item.first][item.second - 1]) {
                    bfs.push_back({item.first, item.second - 1});
                    visited[item.first][item.second - 1] = true;
                }
                if (item.second + 1 < n && !visited[item.first][item.second + 1]) {
                    bfs.push_back({item.first, item.second + 1});
                    visited[item.first][item.second + 1] = true;
                }
                ret[item.first][item.second] = v;
            }
            bfs.erase(bfs.begin(),  bfs.begin() + l);
            v++;
        }
        return ret;
    }
};


struct Suite {
    vector<vector<int>> isWater;
    vector<vector<int>> ret;
};

TEST(highestPeak, Simple) {
    Suite suites[] = {
        {
            {{0,1},{0,0}},
            {{1,0},{2,1}}
        },
        {
            {{0,0,1},{1,0,0},{0,0,0}},
            {{1,1,0},{0,1,1},{1,2,2}}
        },
        {
            {{0,0,1},{1,0,0},{0,0,0}},
            {{1,1,0},{0,1,1},{1,2,2}}
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.highestPeak(su.isWater));
    }
}