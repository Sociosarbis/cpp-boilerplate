#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution
{
public:
  bool isNumber(string s)
  {
    bool hasSign = false;
    bool hasDot = false;
    bool hasNum = false;
    bool hasE = false;
    for (auto c : s)
    {
      if (c == '+' || c == '-')
      {
        if (hasNum || hasSign || hasDot)
          return false;
        hasSign = true;
      }
      else if (c == '.')
      {
        if (hasDot || hasE)
          return false;
        hasDot = true;
      }
      else if (c == 'e' || c == 'E')
      {
        if (!hasNum || hasE)
          return false;
        hasSign = false;
        hasDot = false;
        hasNum = false;
        hasE = true;
      }
      else if (c >= 48 && c <= 57)
      {
        if (!hasNum)
          hasNum = true;
      }
      else
        return false;
    }
    return hasNum;
  }
};

struct Suite
{
  string s;
  bool ret;
};

TEST(isNumber, Simple)
{
  Suite suites[] = {
      {"0",
       true},
      {"e",
       false},
      {".",
       false},
      {".1",
       true},
      {"2", true},
      {"0089", true},
      {"-0.1", true},
      {"+3.14", true},
      {"4.", true},
      {"-.9", true},
      {"2e10", true},
      {"-90E3", true},
      {"3e+7", true},
      {"+6e-1", true},
      {"53.5e93", true},
      {"-123.456e789", true},
      {"abc", false},
      {"1a", false},
      {"1e", false},
      {"e3", false},
      {"99e2.5", false},
      {"--6", false},
      {"-+3", false},
      {"95a54e53", false}};

  Solution s;

  for (auto su : suites)
  {
    ASSERT_EQ(su.ret, s.isNumber(su.s));
  }
}