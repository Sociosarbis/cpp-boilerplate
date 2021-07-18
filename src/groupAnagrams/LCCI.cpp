#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
#include "gtest/gtest.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        vector<vector<string>> ret;
        for (auto str:strs) {
            string key = str;
            sort(key.begin(), key.end());
            if (map.find(key) == map.end()) {
                map.insert({key, ret.size()});
                ret.push_back({});
            }
            ret[map[key]].push_back(str);
        }
        return ret;
    }
};

TEST(GroupAnagrams, Simple) {
  vector<string> strs1 = { "eat","tea","tan","ate","nat","bat" };
  Solution s;
  ASSERT_EQ(
    vector<vector<string>>({
    { "bat" },
    { "eat", "tea", "ate" },
    { "tan", "nat" }
    }), s.groupAnagrams(strs1));
}