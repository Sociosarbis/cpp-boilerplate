#include <string>
#include <vector>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        auto hasLower = false;
        auto hasUpper = false;
        auto hasDigit = false;
        auto repeats = vector<int>();
        password.push_back('\0');
        auto prev = '\0';
        auto count = 0;
        for (auto c:password) {
            if (c >= 48 && c <= 57) {
                if (!hasDigit) {
                    hasDigit = true;
                }
            } else if (c >= 97 && c <= 122) {
                if (!hasLower) {
                    hasLower = true;
                }
            } else if (c >= 65 && c <= 90) {
                if (!hasUpper) {
                    hasUpper = true;
                }
            }

            if (c == prev) {
                count++;
            } else {
                prev = c;
                if (count >= 3) {
                    repeats.push_back(count);
                }
                count = 1;
            }
        }
        auto missing = 0;
        if (!hasLower) {
            missing++;
        }
        if (!hasUpper) {
            missing++;
        }
        if (!hasDigit) {
            missing++;
        }
        count = password.size() - 1;
        auto ret = 0;
        // 对3n + 2的数进行替换是最高效的，3n+1次之，所有如果有多余的字符，优先转换成这些数
        for (auto k = 0;k < 2;k++) {
            for (auto &item:repeats) {
                if (count < 21 + k) {
                    break;
                }
                if (item % 3 == k) {
                    count -= k + 1;
                    item -= k + 1;
                    ret += k + 1;
                }
            }
        }

        for (auto item:repeats) {
            auto changes = item;
            while (count < 6 && changes != 0) {
                count++;
                if (missing > 0) {
                    missing--;
                }
                changes -= 2;
                ret++;
            }
            while (changes > 2) {
                if (count - 18 >= changes) {
                    count -= changes - 2;
                    ret += changes - 2;
                    break;
                } else {
                    if (missing > 0) {
                        missing--;
                    }
                    changes -= 3;
                    ret++;
                }
            }
        }

        if (count > 20) {
            ret += count - 20;
        }

        while (count < 6) {
            count++;
            if (missing > 0) {
                missing--;
            }
            ret++;
        }

        ret += missing;

        return ret;
    }
};


struct Suite {
    string password;
    int ret;
};

TEST(strongPasswordChecker, Simple) {
    Suite suites[] = {
        {
            "a",
            5
        },
        {
            "aA1",
            3
        },
        {
            "1337C0d3",
            0
        },
        {
            "bbaaaaaaaaaaaaaaacccccc",
            8
        },
        {
            "FFFFFFFFFFFFFFF11111111111111111111AAA",
            23
        }
    };

    Solution s;

    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.strongPasswordChecker(su.password));    
    }
}

