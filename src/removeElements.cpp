struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    ListNode* cur = head;
    ListNode* ret = head;
    ListNode* prev = nullptr;
    while (cur != nullptr) {
      ListNode* nextCur = cur->next;
      if (cur->val == val) {
        if (prev != nullptr) {
          prev->next = nextCur;
        } else {
          ret = nextCur;
        }
      } else {
        prev = cur;
      }
      cur = nextCur;
    }
    return ret;
  }
};

