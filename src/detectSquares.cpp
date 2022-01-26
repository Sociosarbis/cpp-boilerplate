#include <vector>
#include <map>

using namespace std;

class DetectSquares {
    map<int, map<int, int>> _x_map;
public:
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        auto x = point[0];
        auto y = point[1];
        if (_x_map.find(x) == _x_map.end()) {
            _x_map[x] = map<int, int>();
        }
        if (_x_map[x].find(y) == _x_map[x].end()) {
            _x_map[x][y] = 1;
        } else {
            _x_map[x][y]++;
        }
    }
    
    int count(vector<int> point) {
        auto x = point[0];
        auto y = point[1];
        auto count = 0;
        for (auto &item1:_x_map[x]) {
            if (item1.first != y) {
                vector<int> target_x_list = { x + item1.first - y, x - item1.first + y };
                for (auto &target_x:target_x_list) {
                    if (_x_map.find(target_x) != _x_map.end()
                        && _x_map[target_x].find(y) != _x_map[target_x].end()
                        && _x_map[target_x].find(item1.first) != _x_map[item1.first].end()
                    ) {
                        count += item1.second
                            * _x_map[target_x][y]
                            * _x_map[target_x][item1.first];
                    }
                }
            }
        }
        return count;
    }
};