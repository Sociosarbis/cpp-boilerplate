#include <vector>
#include <set>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
      set<int> daySet = { bloomDay.begin(), bloomDay.end()};
      vector<int> uniqDayList = { daySet.begin(), daySet.end() };
      int left = 0;
      int right = uniqDayList.size() - 1;
      int ret = -1;
      while (left <= right) {
        int mid = (left + right) / 2;
        int res = countBouquets(bloomDay, k, uniqDayList[mid]);
        if (res >= m) {
          ret = uniqDayList[mid];
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      }
      return ret;
    }

    int countBouquets(vector<int>& bloomDay, int k, int day) {
      int count = 0;
      int tempCount = 0;
      for (auto d:bloomDay) {
        if (d <= day) {
          tempCount++;
          if (tempCount == k) {
            count++;
            tempCount = 0;
          }
        } else {
          tempCount = 0;
        }
      }
      return count;
    }
};

struct Suite {
  vector<int> bloomDay;
  int m;
  int k;
  int ret;
};

TEST(minDays, Simple) {
  vector<Suite> suites = {
    {
      {
        1,10,3,10,2
      },
      3,
      1,
      3
    },
    {
      {
        1,10,3,10,2
      },
      3,
      2,
      -1
    },
    {
      {
        7,7,7,7,12,7,7
      },
      2,
      3,
      12
    },
    {
      {
        1,10,2,9,3,8,4,7,5,6
      },
      4,
      2,
      9
    }
  };

  Solution s;
  for (auto su:suites) {
    ASSERT_EQ(su.ret, s.minDays(su.bloomDay, su.m, su.k));
  }
}


