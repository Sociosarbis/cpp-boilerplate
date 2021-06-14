#include "gtest/gtest.h"

int targetNum = 0;

int guess(int num) {
  return num < targetNum ? 1 : num > targetNum ? -1 : 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int64_t left = 1;
        int64_t right = n;
        while (left <= right) {
          int mid = (left + right) / 2;
          int cmp = guess(mid);
          if (cmp == 0) {
            return mid;
          } else if (cmp == -1) {
            right = mid - 1;
          } else {
            left = mid + 1;
          }
        }
        return n;
    }
};

struct suite {
  int n;
  int pick;
};

TEST(guessNumber, Simple) {
  suite suites[] = {
    suite {
      10,
      6
    },
    suite {
      1,
      1
    },
    suite {
      2,
      1
    },
    suite {
      2,
      2
    }
  };

  Solution s;

  for (auto su:suites) {
    targetNum = su.pick;
    ASSERT_EQ(su.pick, s.guessNumber(su.n));
  }
}