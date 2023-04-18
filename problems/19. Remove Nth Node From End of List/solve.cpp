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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head, *target=head, *pre=nullptr;
        --n;
        while(n>0)
        {
            fast=fast->next;
            --n;
        }
        while(fast->next!=nullptr)
        {
            fast=fast->next;
            pre=target;
            target=target->next;
        }
        
        if(pre!=nullptr)
        {
            pre->next = target->next;
        }
        else if (target->next!=nullptr)
        {
            head=target->next;
        }
        else
        {
            head=nullptr;
        }
        delete target;
        
        return head;
    }
};