#include <vector>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        int ret = 0;
        vector<Node*> bfs;
        bfs.push_back(root);
        unsigned int i = 0;
        unsigned int n = bfs.size();
        while (i != n) {
            for (;i < n;i++) {
                auto node = bfs[i];
                for (auto child:node->children) {
                    bfs.push_back(child);
                }
            }
            i = n;
            n = bfs.size();
            ret++;
        }
        return ret;
    }
};