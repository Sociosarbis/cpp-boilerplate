#include <vector>
#include <cmath>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int steps = abs(target[0]) + abs(target[1]);
        for (auto &ghost:ghosts) {
            int gSteps = abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]);
            if (gSteps <= steps) {
                return false;
            }
        }
        return true;
    }
};

struct Suite {
  vector<vector<int>> ghosts;
  vector<int> target;
  bool ret;
};

TEST(escapeGhosts, Simple) {
    Suite suites[] = {
        {
            {{1,0},{0,3}},
            {0,1},
            true
        },
        {
            {{1,0}},
            {2,0},
            false
        },
        {
            {{2,0}},
            {1,0},
            false
        },
        {
            {{5,0},{-10,-2},{0,-5},{-2,-2},{-7,1}},
            {7,7},
            false
        },
        {
            {{-1,0},{0,1},{-1,0},{0,1},{-1,0}},
            {0,0},
            true
        },
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.escapeGhosts(su.ghosts, su.target));
    }
};


