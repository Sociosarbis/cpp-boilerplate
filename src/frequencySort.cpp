#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
      int counts[75] = { 0 };
      for (auto c:s) {
        counts[c - 48]++;
      }
      string ret;
      for (int i = 0;i < 75;i++) {
        if (counts[i] != 0) {
          int l = 0;
          int r = ret.size() - 1;
          string group = string(counts[i], (char)(i + 48));
          while (l <= r) {
            int mid = (l + r) / 2;
            if (counts[ret[mid] - 48] > counts[i]) {
              l = mid + 1;
            } else if (counts[ret[mid] - 48] < counts[i]) {
              r = mid - 1;
            } else {
              l = mid;
              while (l < ret.size() && ret[l] == ret[mid]) {
                l++;
              }
              break;
            }
          }
          if (l >= ret.size()) {
            ret.append(group);
          } else {
            ret.insert(l, group);
          }
        }
      }
      return ret;
    }
};

struct Suite {
  string s;
  string ret;
};


TEST(frequencySort, Simple) {
  Suite suites[] = {
    Suite {
      "tree",
      "eert",
    },
    Suite {
      "cccaaa",
      "aaaccc"
    },
    Suite {
      "Aabb",
      "bbAa"
    }
  };

  Solution s;
  for (auto su:suites) {
    ASSERT_EQ(su.ret, s.frequencySort(su.s));
  }
}