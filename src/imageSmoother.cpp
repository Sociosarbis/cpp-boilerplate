#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        auto ret = vector<vector<int>>(m, vector<int>(n, 0));
        for (auto i = 0;i < m;i++) {
            for (auto j = 0;j < n;j++) {
                auto count = 0;
                for (auto ii = -1;ii < 2;ii++) {
                    if (i + ii >= 0 && i + ii < m) {
                        for (auto jj = -1;jj < 2;jj++) {
                            if (j + jj >= 0 && j + jj < n) {
                                count++;
                                ret[i][j] += img[i + ii][j + jj];
                            }
                        }
                    }
                }
                ret[i][j] /= count;
            }
        }
        return ret;
    }
};

struct Suite {
    vector<vector<int>> img;
     vector<vector<int>> ret;
};

TEST(imageSmoother, Simple) {
    Suite suites[] = {
        {
            {{1,1,1},{1,0,1},{1,1,1}},
            {{0,0,0},{0,0,0},{0,0,0}}
        },
        {
            {{100,200,100},{200,50,200},{100,200,100}},
            {{137,141,137},{141,138,141},{137,141,137}}
        },
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.imageSmoother(su.img));
    }
}