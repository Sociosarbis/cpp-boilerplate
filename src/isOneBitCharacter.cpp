#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        size_t i = 0;
        auto ret = false;
        while (i < bits.size()) {
            if (bits[i] == 1) {
                i += 2;
            } else {
                i += 1;
                if (i == bits.size()) {
                    ret = true; 
                }
            }
        }
        return ret;
    }
};


struct Suite {
    vector<int> bits;
    bool ret;
};


TEST(isOneBitCharacter, Simple) {
    Suite suites[] = {
        {{1,0,0}, true},
        {{1,1,1,0}, false}
    };

    Solution s;
    for (auto &su:suites) {
        ASSERT_EQ(su.ret, s.isOneBitCharacter(su.bits));
    }
}