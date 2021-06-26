#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
      bool visited[543211] = { false };
      vector<vector<vector<int>>> queue;
      int hash = getHash(board);
      int round = 0;
      if (hash == 123450) return round;
      visited[getHash(board)] = true;
      queue.push_back(board);
      int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
      while (!queue.empty()) {
        round++;
        int n = queue.size();
        for (int k = 0;k < n;k++) {
          int pos[2];
          auto b = queue[k];
          for (int i = 0;i < 2;i++) {
            for (int j = 0;j < 3;j++) {
              if (b[i][j] == 0) {
                pos[0] = i;
                pos[1] = j;
                break;
              }
            }
          }
          for (int i = 0;i < 4;i++) {
            int x = pos[0] + dirs[i][0];
            int y = pos[1] + dirs[i][1];
            if (x >= 0 && x < 2 && y >= 0 && y < 3) {
              int a = b[x][y];
              b[x][y] = 0;
              b[pos[0]][pos[1]] = a;
              int hash = getHash(b);
              if (hash == 123450) {
                return round;
              }
              if (!visited[hash]) {
                visited[hash] = true;
                queue.emplace_back(b);
              }
              b[x][y] = a;
              b[pos[0]][pos[1]] = 0;
            }
          }
        }
        queue = vector<vector<vector<int>>>(queue.begin() + n, queue.end());
      }
      return -1;
    }

    int getHash(vector<vector<int>> &board) {
      int ret = 0;
      int unit = 100000;
      for (int i = 0;i < 2;i++) {
        for (int j = 0;j < 3;j++) {
          ret += board[i][j] * unit;
          unit /= 10;
        }
      }
      return ret;
    }
};

struct Suite {
  vector<vector<int>> board;
  int ret;
};

TEST(slidingPuzzle, Simple) {
  vector<Suite> suites = {
    /*{
      {{1,2,3},{4,0,5}},
      1
    },
    {
      {{1,2,3},{5,4,0}},
      -1
    },
    {
      {{4,1,2},{5,0,3}},
      5
    },*/
    {
      {{1,2,3},{5,4,0}},
      -1
    }
  };

  Solution s;
  for (auto su:suites) {
    ASSERT_EQ(su.ret, s.slidingPuzzle(su.board));
  }
}