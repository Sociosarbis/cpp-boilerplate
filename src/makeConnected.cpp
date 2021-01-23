#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (n - 1 > (int)connections.size()) return -1;
        vector<int> c_to_g = vector<int>(n, 0);
        vector<vector<int>> groups;
        groups.push_back({});
        for (auto conn:connections) {
          int l = conn[0];
          int r = conn[1];
          int g_id = c_to_g[l];
          if (g_id == 0) {
            if (c_to_g[r] == 0) {
              g_id = groups.size();
              c_to_g[l] = g_id;
              c_to_g[r] = g_id;
              groups.push_back({ l, r });
            } else {
              g_id = c_to_g[r];
              c_to_g[l] = g_id;
              groups[g_id].push_back(l);
            }
          } else {
            if (c_to_g[r] == 0) {
              c_to_g[r] = g_id;
              groups[g_id].push_back(r);
            } else if (g_id != c_to_g[r]) {
              int old_g_id = c_to_g[r];
              for (auto m:groups[old_g_id]) {
                groups[g_id].push_back(m);
                c_to_g[m] = g_id;
              }
              groups[old_g_id].clear();
            }
          }
        }
        int ret = 0;
        int total = 0;
        for (auto g:groups) {
          if (!g.empty()) {
            if (total != 0) {
              ret++;
            }
            total += g.size();
          }
        }
        return ret + n - total;
    }
};

struct Suite {
  int n;
  vector<vector<int>> connections;
  int ret;
};


TEST(makeConnected, Simple) {
  Solution s;
  vector<Suite> suites {
    {
      4,
      {{0,1},{0,2},{1,2}},
      1
    },
    {
      6,
      {{0,1},{0,2},{0,3},{1,2},{1,3}},
      2
    },
    {
      6,
      {{0,1},{0,2},{0,3},{1,2}},
      -1
    },
    {
      5,
      {{0,1},{0,2},{3,4},{2,3}},
      0
    }
  };

  for (auto suite:suites) {
    ASSERT_EQ(s.makeConnected(suite.n, suite.connections), suite.ret);
  }
}