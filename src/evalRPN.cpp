#include <vector>
#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      vector<int> stack;
      for (auto token:tokens) {
        char lastChar = token.at(token.size() - 1);
        if (lastChar >= 48 && lastChar <= 57) {
          stack.push_back(stoi(token));
        } else {
          int r = stack.back();
          stack.pop_back();
          int l = stack.back();
          stack.pop_back();
          switch (lastChar) {
            case '+':
              stack.push_back(l + r);
              break;
            case '-':
              stack.push_back(l - r);
              break;
            case '*':
              stack.push_back(l * r);
              break;
            case '/':
              stack.push_back(l  / r);
              break;
            default:;
          }
        }
      }
      return stack[0];
    }
};

struct Suite {
  vector<string> tokens;
  int ret;
};

vector<Suite> suites = {
  {
    {"2","1","+","3","*"},
    9
  },
  {
    {"4","13","5","/","+"},
    6,
  },
  {
    {"10","6","9","3","+","-11","*","/","*","17","+","5","+"},
    22
  }
};


TEST(EvalRPN, Simple) {
  Solution s;
  for (auto item:suites) {
    ASSERT_EQ(s.evalRPN(item.tokens), item.ret);
  }
}
