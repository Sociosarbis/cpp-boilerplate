#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ret = 0;
        for (unsigned int i = 0;i < board.size();i++) {
            auto row = board[i];
            for (unsigned int j = 0;j < row.size();j++) {
                if (row[j] == 'X') {
                    if ((i == 0 || board[i - 1][j] == '.')
                        && (j == 0 || board[i][j - 1] == '.')
                        && ((i + 1 == board.size() || board[i + 1][j] == '.')
                            || ((i + 1 != board.size() && board[i + 1][j] == 'X')
                                && (j + 1 == board[i].size() || board[i][j + 1] == '.')))) {
                        ret++;
                    }
                }
            }
        }
        return ret;
    }
};

struct Suite {
    vector<vector<char>> board;
    int ret;
};


TEST(countBattleships, Simple) {
    Suite suites[] = {
        {
            {{'X','.','.','X'},{'.','.','.','X'},{'.','.','.','X'}},
            2
        },
        {
            {{'.'}},
            0
        }
    };

    Solution s;
    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.countBattleships(su.board));
    }
}