#include <map>;
#include <vector>;

using namespace std;

class RandomizedSet {
public:
    map<int, size_t> s;
    vector<int> v;
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if (s.find(val) == s.end()) {
            v.push_back(val);
            s.insert({ val, v.size() - 1 });
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if (s.find(val) != s.end()) {
            auto i = s[val];
            if (i + 1 < v.size()) {
                auto b = v.back();
                v[i] = b;
                s[b] = i;
            }
            s.erase(val);
            v.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};