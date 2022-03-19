#include <string>

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
    string tree2str(TreeNode *root) {
        if (root == nullptr) return "";
        auto ret = to_string(root->val);
        if (root-> left != nullptr || root -> right != nullptr) {
            ret.push_back('(');
            ret.append(tree2str(root->left));
            ret.push_back(')');
            if (root->right != nullptr) {
                ret.push_back('(');
                ret.append(tree2str(root->right));
                ret.push_back(')');
            }
        }
        return ret;
    }
};