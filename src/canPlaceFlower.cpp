#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
      if (n == 0) {
          return true;
      }
      int num = flowerbed.size();
      for (int i = 0;i < num;i++) {
        if (flowerbed[i] != 1) {
          if (i == 0 || flowerbed[i - 1] == 0) {
            if (i == num - 1 || flowerbed[i + 1] == 0) {
              n--;
              flowerbed[i] = 1;
              if (n == 0) {
                return true;
              }
            }
          }
        }
      }
      return false;
    }

    bool canPlaceFlowersBest(vector<int>& flowerbed, int n) {
      if (n == 0) {
        return true;
      }
      int num = flowerbed.size();
      int zeroCount = 1;
      for (int i = 0;i < num;i++) {
        if (flowerbed[i] == 0) {
          zeroCount++;
        } else {
          if (zeroCount > 2) {
            n -= (zeroCount - 1) / 2;
            if (n <= 0) {
              return true;
            }
          }
          zeroCount = 0;
        }
      }
      zeroCount += 1;
      if (zeroCount > 2) {
        n -= (zeroCount - 1) / 2;
      }
      return n <= 0;
    }

};

struct Suite {
  vector<int> flowerbed;
  int n;
  bool ret;
};

vector<Suite> suites = {
  {
    { 1,0,0,0,1 },
    1,
    true
  },
  {
    { 1,0,0,0,1 },
    2,
    false
  },
  {
    { 1,0,0,0,0,1},
    2,
    false
  },
  {
    {0,0,0,0,0,1,0,0},
    0,
    true
  },
  {
    {0,0,1,0,1},
    1,
    true
  }
};

TEST(CanPlaceFlowers, Simple) {
  Solution s;
  for (auto item:suites) {
    ASSERT_EQ(s.canPlaceFlowers(item.flowerbed, item.n), item.ret);
  }
}

TEST(CanPlaceFlowers, Best) {
  Solution s;
  for (auto item:suites) {
    ASSERT_EQ(s.canPlaceFlowersBest(item.flowerbed, item.n), item.ret);
  }
}