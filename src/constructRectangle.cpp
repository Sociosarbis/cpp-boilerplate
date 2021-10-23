#include <vector>
#include <math.h>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int root = sqrtf(area);
        while (area % root != 0) {
            root -= 1;
        }
        return { area / root, root };
    }
};

struct Suite {
    int area;
    vector<int> ret;
};

TEST(constructRectangle, Simple) {
    Suite suites[] = {
        {
            4,
            {2, 2},
        },
        {
            37,
            {37, 1},
        },
        {
            122122,
            { 427, 286 }
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.constructRectangle(su.area));
    }
}