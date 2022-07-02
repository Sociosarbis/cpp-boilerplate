#include <vector>
#include <map>
#include <queue>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        auto dp = map<int, long>();
        dp.insert({0, startFuel});
        auto prev = 0;
        for (auto station:stations) {
            auto nextDp = map<int, long>();
            for (auto item:dp) {
                if (item.second >= station[0] - prev) {
                    auto fuel = item.second - (station[0] - prev);
                    auto state = nextDp.find(item.first);
                    if (state != nextDp.end()) {
                        if (state->second < fuel) {
                            state->second = fuel;
                        }
                    } else {
                        nextDp.insert({item.first, fuel});
                    }
                    if (fuel < target - station[0]) {
                        fuel += station[1];
                        state = nextDp.find(item.first + 1);
                        if (state != nextDp.end()) {
                            if (state->second < fuel) {
                                state->second = fuel;
                            }
                        } else {
                            nextDp.insert({item.first +  1, fuel});
                        }
                    }
                }
            }
            if (nextDp.empty()) {
                return -1;
            }
            dp = nextDp;
            prev = station[0];
        }

        auto ret = -1;
        for (auto item:dp) {
            if (item.second >= target - prev && (ret == -1 || item.first < ret)) {
                ret = item.first;
            }
        }
        return ret;
    }

    int minRefuelStopsBest(int target, int startFuel, vector<vector<int>>& stations) {
        auto prev = 0;
        auto fuel = startFuel;
        auto queue = priority_queue<int>();
        auto ret = 0;
        for (auto station:stations) {
            fuel -= station[0] - prev;
            while (fuel < 0) {
                if (queue.empty()) {
                    return -1;
                }
                fuel += queue.top();
                ret++;
                queue.pop();
            }
            queue.push(station[1]);
            prev = station[0];
        }
         while (fuel < target - prev) {
            if (queue.empty()) {
                return -1;
            }
            fuel += queue.top();
            ret++;
            queue.pop();
        }
        return ret;
    }
};

struct Suite {
    int target;
    int startFuel;
    vector<vector<int>> stations;
    int ret;
};

TEST(minRefuelStops, Simple) {
    Suite suites[] = {
        {
            1,
            1,
            {},
            0
        },
        {
            100,
            1,
            {{10,100}},
            -1
        },
        {
            100,
            10,
            {{10,60},{20,30},{30,30},{60,40}},
            2
        }
    };

    Solution s;
    for (auto su:suites) {
        s.minRefuelStops(su.target, su.target, su.stations);
    }
}