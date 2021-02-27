#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
      return dfs(s, 0, s.size() - 1, k);
    }

    int dfs(string &s, int start, int end, int k) {
      if (end + 1 - start < k) return 0;
      int counter[26][2];
      for (int i = 0;i < 26;i++) {
        counter[i][0] = 0;
      }
      for (int i = start;i <= end;i++) {
        int index = s[i] - 97;
        if (counter[index][0] == 0) {
          counter[index][0] = 1;
          counter[index][1] = i;
        } else {
          counter[index][0]++;
        }
      }

      for (int i = 0;i < 26;i++) {
        if (counter[i][0] != 0 && counter[i][0] < k) {
          char c = i + 97;
          int left = dfs(s, start, counter[i][1] - 1, k);
          int r = counter[i][1] + 1;
          while (r < end && s[r] == c) {
            r++;
          }
          int right = dfs(s, r, end, k);
          return left >= right ? left : right;
        }
      }
      return end + 1 - start;
    }
};


struct Suite {
  string s;
  int k;
  int ret;
};

TEST(LongestSubstring, Simple) {
  vector<Suite> suites = {
    {
      "aaabb",
      3,
      3
    },
    {
      "ababbc",
      2,
      5
    },
    {
      "weitong",
      2,
      0
    },
    {
      "baaabcb",
      3,
      3
    }
  };

  Solution s;

  for (auto su:suites) {
    ASSERT_EQ(s.longestSubstring(su.s, su.k), su.ret);
  }
}