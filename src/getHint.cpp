#include <string>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int counter1[10] = {0};
        int counter2[10] = {0};
        int bull = 0;
        int cow = 0;
        for (int i = 0;i < secret.size();i++) {
            if (secret[i] != guess[i]) {
                counter1[secret[i] - 48]++;
                counter2[guess[i] - 48]++;
            } else {
                bull++;
            }
        }
        for (int i = 0;i < 10;i++) {
            cow += counter2[i] > counter1[i] ? counter1[i] : counter2[i];
        }
        stringstream s;
        s << bull << 'A' << cow << 'B';
        return s.str();
    }
};


struct Suite {
    string secret;
    string guess;
    string ret;
};

TEST(getHint, Simple) {
    Suite suites[] = {
        {
            "1807",
            "7810",
            "1A3B"
        },
        {
            "1123",
            "0111",
            "1A1B"
        },
        {
            "1",
            "0",
            "0A0B"
        },
        {
            "1",
            "1",
            "1A0B"
        }
    };

    Solution s;

    for (auto su:suites) {
        ASSERT_EQ(su.ret, s.getHint(su.secret, su.guess));
    }
}