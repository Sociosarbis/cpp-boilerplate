#include <string>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int count = 0;
        int asterisk = 0;
        vector<pair<int, int>> asteriskStack;
        for (auto c:s) {
            switch (c) {
                case '(':
                    if (asterisk > 0) {
                        asteriskStack.push_back({asterisk, count});
                        asterisk = 0;
                        count = 0;
                    }
                    count += 1;
                    break;
                case ')':
                    count -= 1;
                    if (count < 0) {
                         if (!asteriskStack.empty()) {
                            for (int i = asteriskStack.size() - 1;i >= 0;i-=1) {
                                if (asteriskStack[i].second > 0) {
                                    asteriskStack[i].second -=1;
                                    if (asteriskStack[i].first == 0 && asteriskStack[i].second == 0) {
                                        asteriskStack.erase(asteriskStack.begin() + i);
                                    }
                                    count += 1;
                                    break;
                                }
                            }
                            if (count < 0) {
                                for (int i = 0;i < asteriskStack.size();i+=1) {
                                    if (asteriskStack[i].first > 0) {
                                        asteriskStack[i].first -=1;
                                        if (asteriskStack[i].first == 0 && asteriskStack[i].second == 0) {
                                            asteriskStack.erase(asteriskStack.begin() + i);
                                        }
                                        count += 1;
                                        break;
                                    }
                                }
                            }
                            break;
                        } else if (asterisk > 0) {
                            asterisk -= 1;
                            count += 1;
                            break;
                        }
                        return false;
                    }
                    break;
                default:
                    asterisk += 1;
            }
        }
        asteriskStack.push_back({ asterisk, count });
        count = 0;
        for (auto &it:asteriskStack) {
            count += it.first - it.second;
            if (count > 0) {
                count = 0;
            }
        }
        return count == 0;
    }
};


struct Suite {
    string s;
    bool ret;
};

TEST(checkValidString, Simple) {
    Suite suites[] = {
        {
            "()",
            true,
        },
        {
            "(*)",
            true,
        },
        {
            "(*))",
            true,
        }
    };

    Solution s;
    for (auto su:suites) {

    }
}