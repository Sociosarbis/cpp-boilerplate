#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    TreeNode* cur;
    stack<TreeNode*> stack;
    BSTIterator(TreeNode* root) {
      cur = root;
    }
    
    int next() {
      if (cur != nullptr) {
        while (cur->left) {
          stack.push(cur);
          cur = cur->left;
        }
        int ret = cur->val;
        cur = cur->right;
        return ret;
      } else {
        TreeNode* top = stack.top();
        stack.pop();
        int ret = top->val;
        cur = top->right;
        return ret;
      }
    }
    
    bool hasNext() {
      return cur != nullptr || !stack.empty();
    }
};