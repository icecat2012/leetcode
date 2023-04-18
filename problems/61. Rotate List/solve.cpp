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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        else if(k==0) return head;
        int a=0;
        ListNode *p=head;
        while(p!=nullptr)
        {
            ++a;
            p = p->next;
        }
        k %= a;
        if(k==0) return head;
        ListNode *tail=head, *h=head;
        for(;k>0;--k)
            h = h->next;
        while(h->next!=nullptr)
        {
            tail = tail->next;
            h = h->next;
        }
        p = tail->next;
        tail->next = nullptr;
        h->next = head;
        return p;
    }
};