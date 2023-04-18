/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr) return true;
        if(head->next->next==nullptr)
            if(head->val!=head->next->val) return false;
            else return true;
        ListNode *slow=head, *fast=head;
        stack<int> a;
        while(fast->next!=nullptr && fast->next->next!=nullptr)
        {
            a.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next!=nullptr)
            a.push(slow->val);
        while(a.size()>0)
        {
            slow=slow->next;
            if(slow->val != a.top())
                return false;
            a.pop();
        }
        return true;
    }
};