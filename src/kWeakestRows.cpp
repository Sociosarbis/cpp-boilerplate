#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int* indexToCount = new int[mat.size()]{0};
        vector<int> ret;
        for (int i = 0;i < mat.size();i++) {
            int count = 0;
            for (int j = 0;j < mat[i].size();j++) {
                if (mat[i][j] == 1) {
                    count += 1;
                } else {
                    break;
                }
            }
            int l = 0;
            int r = ret.size() - 1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (count < indexToCount[ret[mid]]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            if (l < ret.size()) {
                ret.insert(ret.begin() + l, i);
                if (ret.size() > k) {
                    ret.pop_back();
                }
                indexToCount[i] = count;
            } else if (ret.size() < k) {
                ret.push_back(i);
                indexToCount[i] = count;
            }
        }
        return ret;
    }
};

struct Suite
{
    vector<vector<int>> mat;
    int k;
    vector<int> ret;
};

TEST(kWeakestRows, Simple)
{
    Suite suites[] = {
        {
            {{1, 1, 0, 0, 0},
             {1, 1, 1, 1, 0},
             {1, 0, 0, 0, 0},
             {1, 1, 0, 0, 0},
             {1, 1, 1, 1, 1}},
             3,
             { 2, 0, 3}
        },
        {
            {{1,0,0,0},
            {1,1,1,1},
            {1,0,0,0},
            {1,0,0,0}},
            2,
            { 0, 2 }
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.kWeakestRows(su.mat, su.k));
    }
}
