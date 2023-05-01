/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *pre;
        while(node->next!=nullptr)
        {
            node->val = node->next->val;
            pre = node;
            node = node->next;
        }
        pre->next = nullptr;
        delete node;
    }
};