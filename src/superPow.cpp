#include <vector>
#include "gtest/gtest.h"

using namespace std;


class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int base = a % 1337;
        int ret = 1;
        for (int i = b.size() - 1;i>=0;i--) {
            int temp = 1;
            for (int j = b[i];j > 0;j--) {
                temp = (temp * base) % 1337;
            }
            ret = (ret * temp) % 1337;
            for (int j = b[i];j < 10;j++) {
                temp = (temp * base) % 1337;
            }
            base = temp;
        }
        return ret;
    }
};

struct Suite{
    int a;
    vector<int> b;
    int ret;
};


TEST(superPow, Simple) {
    Suite suites[] = {
        {
            2,
            {3},
            8
        },
        {
            2,
            {1,0},
            1024
        },
        {
            1,
            {4,3,3,8,5,2},
            1
        },
        {
            2147483647,
            {2,0,0},
            1198
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.superPow(su.a, su.b));
    }

}


