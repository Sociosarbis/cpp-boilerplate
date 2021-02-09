#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
      int n = A.size();
      vector<int> counter = vector<int>(n + 1, 0);
      int ret = 0;
      int tmp = 0;
      int j = 0;
      for (int i = 0;i < n;i++) {
        int num = A[i];
        counter[num]++;
        if (counter[num] == 1) {
          tmp++;
          while (tmp > K) {
            int removeNum = A[j];
            if (counter[removeNum] == 1) {
              tmp--;
            }
            j++;
            counter[removeNum]--;
          }
        }
        
        if (tmp == K) {
          int oldJ = j;
          while (j < i && counter[A[j]] > 1) {
            counter[A[j]]--;
            j++;
            ret++;
          }
          ret++;
          for (j = j - 1;j >= oldJ;j--) {
            counter[A[j]]++;
          }
          j = oldJ;
        }
      }
      return ret;
    }
};

struct Suite {
  vector<int> A;
  int K;
  int ret;
};

TEST(subarraysWithKDistinct, Simple) {
  Solution s;
  Suite suites[] = {
    {
      { 1,2,1,2,3 },
      2,
      7,
    },
    {
      { 1,2,1,3,4 },
      3,
      3,
    }
  };

  for (auto su: suites) {
    ASSERT_EQ(s.subarraysWithKDistinct(su.A, su.K), su.ret);
  }
}
