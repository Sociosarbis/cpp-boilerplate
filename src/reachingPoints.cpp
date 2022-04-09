#include "gtest/gtest.h"

class Solution {
public:
    // 从tx, ty反向推导sx, sy. 当tx > ty时, tx是ty经过若干转化而得, 因此求tx除以ty的余数
    // 当tx < ty时, ty是tx经过若干转化而得, 因此求ty除以tx的余数
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (sx < tx && sy < ty) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }
        if (sx > tx || sy > ty) {
            return false;
        }
        return (tx == sx && (ty - sy) % sx == 0) || (ty == sy && (tx - sx) % sy == 0);
    }
};

struct Suite {
    int sx;
    int sy;
    int tx;
    int ty;
    bool ret;
};

TEST(reachingPoints, Simple) {
    Suite suites[] = {
        {
            1,
            1,
            3,
            5,
            true,
        },
        {
            1,
            1,
            2,
            2,
            false,
        },
        {
            1,
            1,
            1,
            1,
            true,
        },
    };

    Solution s;

    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.reachingPoints(su.sx, su.sy, su.tx, su.ty));
    }
}