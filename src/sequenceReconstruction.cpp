#include <vector>
#include <set>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        auto count = 0;
        auto childrenSet = vector<set<int>>(nums.size());
        auto parentCount = vector<int>(nums.size());
        for (const auto &seq:sequences) {
            auto prev = seq[0];
            for (auto i = 1;i < seq.size();i++) {
                const auto index = prev - 1;
                if (childrenSet[index].find(seq[i]) == childrenSet[index].end()) {
                    childrenSet[index].insert(seq[i]);
                    parentCount[seq[i] - 1]++;
                }
                prev = seq[i];
            }
        }
        auto next = 0;
        for (auto i = 0;i < parentCount.size();i++) {
            if (parentCount[i] == 0) {
                if (next != 0) {
                    return false;
                }
                next = i + 1;
            }
        }
        if (next != 0) {
            while (next != 0) {
                if (nums[count] != next) {
                    return false;
                }
                count++;
                auto tempNext = 0;
                for (const auto num:childrenSet[next - 1]) {
                    const auto index = num - 1;
                    parentCount[index]--;
                    if (parentCount[index] == 0) {
                        if (tempNext == 0) {
                            tempNext = num;
                        } else {
                            return false;
                        }
                    }
                }
                next = tempNext;
            }
        }
        return count == nums.size();
    }
};

struct Suite {
    vector<int> nums;
    vector<vector<int>> sequences;
    bool ret;
};

TEST(sequenceReconstruction, Simple) {
    Suite suites[] = {
        /*{
            {1,2,3},
            {{1,2},{1,3}},
            false,
        },
        {
            {1,2,3},
            {{1,2}},
            false,
        },*/
        {
            {1,2,3},
            {{1,2},{1,3},{2,3}},
            true,
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.sequenceReconstruction(su.nums, su.sequences));
    }
}