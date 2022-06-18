#include <cstddef>
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            auto ret = new Node(insertVal);
            ret->next = ret;
            return ret;
        }
        auto node = new Node(insertVal);
        auto cur = head;
        while (cur->next != head
            && ((cur->val > insertVal && cur->next->val >= cur->val)
            || (cur->next->val < insertVal && !(cur->val > cur->next->val && cur->val <= insertVal)))) {
            cur = cur->next;
        }
        auto oldNext = cur->next;
        cur->next = node;
        node->next = oldNext;
        return head;
    }
};