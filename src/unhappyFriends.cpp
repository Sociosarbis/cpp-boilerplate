#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> wToN = vector<vector<int>>(n, vector<int>(n, 0));
        vector<vector<int>> nToW = vector<vector<int>>(n, vector<int>(n, 0));
        vector<int> pairMap = vector<int>(n, 0);
        for (int i = 0;i < n;i++) {
            auto p = preferences[i];
            int weight = n - 1;
            for (auto it:p) {
                nToW[i][it] = weight;
                wToN[i][weight] = it;
                weight--;
            }
        }
        for (auto &p:pairs) {
            pairMap[p[0]] = p[1];
            pairMap[p[1]] = p[0];
        }
        int ret = 0;
        for (auto &p:pairs) {
            for (int i = 0;i < 2;i++) {
                int x = p[i];
                int y = p[1 - i];
                int w = nToW[x][y];
                for (int j = n - 1;j > w;j--) {
                    int u = wToN[x][j];
                    int v = pairMap[u];
                    if (nToW[u][x] > nToW[u][v]) {
                        ret += 1;
                        break;
                    }
                }
            }
        }
        return ret;
    }
};


struct Suite {
  int n;
  vector<vector<int>> preferences;
  vector<vector<int>> pairs;
  int ret;
};

TEST(unhappyFriends, Simple) {
  Solution s;
  Suite suites[] = {
    {
      4,
      {{1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}},
      {{0, 1}, {2, 3}},
      2
    },
    {
      2,
      {{1}, {0}},
      {{1, 0}},
      0
    },
    {
      4,
      {{1, 3, 2}, {2, 3, 0}, {1, 3, 0}, {0, 2, 1}},
      {{1, 3}, {0, 2}},
      4
    }
  };

  for (auto su: suites) {
    ASSERT_EQ(su.ret, s.unhappyFriends(su.n, su.preferences, su.pairs));
  }
}