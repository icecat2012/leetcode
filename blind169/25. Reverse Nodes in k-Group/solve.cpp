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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || k<=1) return head;

        ListNode *p=head;
        int i=0;
        while (i<k && p!=nullptr)
        {
            p = p->next;
            ++i;
        }
        if(p==nullptr && i<k) return head;

        ListNode *a=head, *tail=head, *pre=nullptr, *tmp;
        i=0;
        while(i<k)
        {
            tmp = a->next;
            a->next = pre;
            pre = a;
            a = tmp;
            ++i;
        }
        tail->next = reverseKGroup(p, k);
        return pre;
    }
};