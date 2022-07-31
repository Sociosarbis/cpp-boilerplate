#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> bfs = {root};
        auto ret = 1;
        auto max = root->val;
        auto level = 1;
        while (!bfs.empty()) {
            auto n = bfs.size();
            auto temp = 0;
            for (auto i = 0;i < n;i++) {
                temp += bfs[i]->val;
                if (bfs[i]->left != nullptr) {
                    bfs.push_back(bfs[i]->left);
                }

                if (bfs[i]->right != nullptr) {
                    bfs.push_back(bfs[i]->right);
                }
            }
            if (temp > max) {
                max = temp;
                ret = level;
            }
            level++;
            bfs.erase(bfs.begin(), bfs.begin() + n);
        }
        return ret;
    }
};