#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
      int dict[1000] = {0};
      int ret = 0;
      for (auto answer:answers) {
        if (dict[answer] == 0) {
          dict[answer] = answer;
          ret += answer + 1;
        } else {
          dict[answer]--;
        }
      }
      return ret;
    }
};


struct Suite {
  vector<int> answers;
  int ret;
};

vector<Suite> suites= {
  Suite {
    {1, 1, 2},
    5
  },
  Suite {
    {10, 10, 10},
    11
  },
  Suite {
    {},
    0
  },
  Suite {
    {1,0,1,0,0},
    5
  }
};

TEST(numRabbits, Simple) {
  Solution s;
  for (auto item:suites) {
    ASSERT_EQ(s.numRabbits(item.answers), item.ret);
  }
}