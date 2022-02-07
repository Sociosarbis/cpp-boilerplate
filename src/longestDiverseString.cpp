#include <string>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, int>> heap = {{a, 0}, {b, 1}, {c,2}};
        sort(heap.begin(), heap.end());
        string ret;
        while (heap.back().first != 0) {
            auto n = heap.back().first == 1 ? 1 : 2;
            if (!ret.empty()) {
                auto max = 2;
                for (int i = ret.size() - 1;i >= 0;i--) {
                    if (heap.back().second + 97 != ret[i]) {
                        break;
                    } else {
                        max--;
                    }
                }
                if (n > max) {
                    n = max;
                }
            }
            for (auto i = 0;i < n;i++) {
                ret.push_back(heap.back().second + 97);
                heap.back().first--;
            }
            if (heap[1].first != 0) {
                ret.push_back(heap[1].second + 97);
                heap[1].first--;
            } else if (n == 0) {
                break;
            }
            if (heap[1].first < heap[0].first) {
                heap[0].swap(heap[1]);
            }
            if (heap[2].first < heap[1].first) {
                heap[2].swap(heap[1]);
                if (heap[1].first < heap[0].first) {
                    heap[0].swap(heap[1]);
                }
            }
        }
        return ret;
    }
};


struct Suite {
    int a;
    int b;
    int c;
    string ret;
};


TEST(longestDiverseString, Simple) {
    Suite suites[] = {
        {
            1,
            1,
            7,
            "ccbccacc"
        },
        {
            7,
            1,
            0,
            "aabaa"
        }
    };

    Solution s;

    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.longestDiverseString(su.a, su.b, su.c));
    }
}


