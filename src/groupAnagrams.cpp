#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include "gtest/gtest.h"


using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> groups;
      int sharedCounter[26];
      for (auto s: strs) {
        memset(sharedCounter, 0, sizeof sharedCounter);
        for (auto c:s) {
          sharedCounter[c - 97]++;
        }
        string tmp;
        tmp.reserve(s.size());
        for (int i = 0;i < 26;i++) {
          if (sharedCounter[i] != 0) {
            tmp.append(sharedCounter[i], (char)(i + 97));
          }
        }
        auto it = groups.find(tmp);
        if (it == groups.end()) {
          it = groups.insert({ tmp, {} }).first;
        }
        it->second.push_back(s);
      }
      vector<vector<string>> ret;
      for (auto it:groups) {
        ret.push_back(it.second);
      }
      return ret;
    }
};

TEST(GroupAnagrams, Simple) {
  vector<string> strs1 = { "eat","tea","tan","ate","nat","bat" };
  vector<string> strs2 = { "" };
  vector<string> strs3 = { "a" };
  Solution s;
  ASSERT_EQ(s.groupAnagrams(strs1).size(), 3);
  ASSERT_EQ(s.groupAnagrams(strs2).size(), 1);
  ASSERT_EQ(s.groupAnagrams(strs3).size(), 1);
}