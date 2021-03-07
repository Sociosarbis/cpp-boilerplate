#include <vector>
#include <string>
#include <map>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    map<string, bool> dp;
    vector<vector<string>> partition(string s) {
      vector<vector<string>> ret;
      vector<string> tmp;
      for (int i = 0;i + 3 < s.size();i++) {
        for (int j = i + 3;j < s.size();j++) {
          string tmpS = s.substr(i, j - i + 1);
          if (dp.find(tmpS) == dp.end()) {
            dp.insert({ tmpS, isPalindrome(s, i, j)});
          }
        }
      }
      dfs(s, 0, tmp, ret);
      return ret;
    }

    void dfs(string s, int i, vector<string> &tmp, vector<vector<string>> &ret) {
      for (int j = i;j < s.size();j++) {
        int l = j - i + 1;
        if (l < 4 ? isPalindrome(s, i, j) : dp.find(s.substr(i, l))->second) {
          tmp.push_back(s.substr(i, l));
          if (j == s.size() - 1) {
            ret.push_back(vector<string>(tmp.begin(), tmp.end()));
          } else {
            dfs(s, j + 1, tmp, ret);
          }
          tmp.pop_back();
        }
      }
    }

    bool isPalindrome(string s, int i, int j) {
      while (i < j) {
        if (s[i] != s[j]) {
          return false;
        }
        i++;
        j--;
      }
      return true;
    }
};

struct Suite {
  string s;
  vector<vector<string>> ret;
};

TEST(Partition, Simple) {
  vector<Suite> suites = {
    {
      "aab",
      {{"a","a","b"},{"aa","b"}}
    },
    {
      "a",
      {{"a"}}
    }
  };

  Solution s;

  for (auto su:suites) {
    ASSERT_EQ(s.partition(su.s), su.ret);
  }
}