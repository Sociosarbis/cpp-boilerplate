#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
      int groupLen = row.size() / 2;
      vector<int> iToGroup = vector<int>(groupLen, -1);
      vector<vector<int>> groups = vector<vector<int>>(groupLen);
      for (int i = 0;i < groupLen;i++) {
        int index1 = i << 1;
        int index2 = index1 + 1;
        int first = row[index1];
        int second = row[index2]; 
        int coupleId1 = first >> 1;
        int coupleId2 = second >> 1;
        int groupId = -1;
        if (coupleId1 != coupleId2) {
          if (iToGroup[coupleId1] == -1) {
            if (iToGroup[coupleId2] == -1) {
              groupId = groups.size();
              groups.push_back(vector<int>{ coupleId1, coupleId2 });
              iToGroup[coupleId1] = groupId;
              iToGroup[coupleId2] = groupId;
            } else {
              groupId = iToGroup[coupleId2];
              groups[groupId].push_back(coupleId1);
              iToGroup[coupleId1] = groupId; 
            }
          } else {
            groupId = iToGroup[coupleId1];
            if (iToGroup[coupleId2] == -1) {
              groups[groupId].push_back(coupleId2);
              iToGroup[coupleId2] = groupId; 
            } else if (groupId != iToGroup[coupleId2]) {
              int oldGroupId = iToGroup[coupleId2];
              for (auto c:groups[oldGroupId]) {
                groups[groupId].push_back(c);
                iToGroup[c] = groupId;
              }
              groups[oldGroupId].clear();
            }
          }
        }
      }
      int ret = 0;
      for (auto g:groups) {
        if (!g.empty()) {
          ret += g.size() - 1;
        }
      }
      return ret;
    }
};


struct Suite {
  vector<int> row;
  int ret;
};

TEST(minSwapsCouples, Simple) {
  vector<Suite> suites = {
    {
      { 0, 2, 1, 3 },
      1,
    },
    {
      { 3, 2, 0, 1 },
      0 
    }
  };

  Solution s;

  for (auto su:suites) {
    ASSERT_EQ(s.minSwapsCouples(su.row), su.ret);
  }
}