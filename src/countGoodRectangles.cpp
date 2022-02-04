#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        auto ret = 0;
        auto temp = 0;
        for (auto &rect:rectangles) {
            auto size = rect[0] < rect[1] ? rect[0] : rect[1];
            if (size > temp) {
                ret = 1;
                temp = size;
            } else if (size == temp) {
                ret++;
            }
        }
        return ret;
    }
};


struct Suite {
    vector<vector<int>> rectangles;
    int ret;
};



TEST(countGoodRectangles, Simple) {
    Suite suites[] = {
        {
            {{5,8},{3,9},{5,12},{16,5}},
            3
        },
        {
            {{2,3},{3,7},{4,3},{3,7}},
            3
        },
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.countGoodRectangles(su.rectangles));
    }
}