#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        auto tempArr = vector<int>(arr);
        std::sort(tempArr.begin(), tempArr.end());
        auto ret = 0;
        auto t1 = 0;
        auto t2 = 0;
        auto index = 0;
        auto c1 = 0;
        auto c2 = 0;
        for (auto i = 0;i < arr.size();i++) {
            if (arr[i] > t1) {
                t1 = arr[i];
                c1 = 1;
            } else if (arr[i] == t1) {
                c1++;
            }

            if (tempArr[i] != t2) {
                t2 = tempArr[i];
                c2 = 1;
            } else {
                c2++;
            }

            if (t1 == t2 && c1 == c2) {
                ret++;
                index = i;
            }
        }
        if (index + 1 != arr.size()) {
            ret++;
        }
        return ret;
    }
};

struct Suite {
    vector<int> arr;
    int ret;
};

TEST(maxChunksToSorted, Simple) {
    Suite suites[] = {
        {
            {5,4,3,2,1},
            1,
        },
        {
            {2,1,3,4,4},
            4,
        }
    };

    Solution s;

    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.maxChunksToSorted(su.arr));
    }
}