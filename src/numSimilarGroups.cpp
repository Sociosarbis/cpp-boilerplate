#include <vector>
#include <string>
#include <iostream>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
      int n = strs.size();
      bool** graph = new bool*[n]{};
      for (int i = 0;i < n;i++) {
        graph[i] = new bool[n]{ false }; 
      }
      for (int i = 0;i < n;i++) {
        string str1 = strs[i];
        for (int j = i + 1;j < n;j++) {
          string str2 = strs[j];
          if (str1 == str2) {
            graph[i][j] = true;
            graph[j][i] = true;
          } else {
            int mismatch = 0;
            for (unsigned i = 0;i < str1.size();i++) {
              if (str1[i] != str2[i]) {
                mismatch++;
                if (mismatch > 2) {
                  break;
                }
              }
            }
            if (mismatch <= 2) {
              graph[i][j] = true;
              graph[j][i] = true;
            }
          }
        }
      }
      vector<vector<int>> groups;
      for (int i = 0;i < n;i++) {
        int groupId = -1;
        for (int j = groups.size() - 1;j >= 0;j--) {
          auto group = &groups[j];
          for (unsigned k = 0;k < group->size();k++) {
            if (graph[i][(*group)[k]]) {
              if (groupId == -1) {
                group->push_back(i);
              } else {
                group->insert(group->end(), groups[groupId].begin(), groups[groupId].end());
                groups.erase(groups.begin() + groupId);
              }
              groupId = j;
              break;
            }
          }
        }
        if (groupId == -1) {
          groups.push_back({ i });
        }
      }
      return groups.size();
    }
};

struct Suite {
  vector<string> strs;
  int ret;
};

TEST(numSimilarGroups, simple) {
  Solution s;
  vector<Suite> suites = {
    {
      {"tars","rats","arts","star"},
      2
    },
    {
      {"omv","ovm"},
      1
    }，
    {
      {"nmiwx","mniwx","wminx","mnixw","xnmwi"},
      2
    }
  };

  for (Suite su:suites) {
    int ret = s.numSimilarGroups(su.strs);
    ASSERT_EQ(ret, su.ret);
  }
}