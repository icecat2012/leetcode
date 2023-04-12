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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a=l1, *b=l2, *c=new ListNode;
        ListNode *hc;
        hc = c;
        int inc=0;
        while(a!=nullptr || b!=nullptr || inc)
        {
            c->next = new ListNode();
            c = c->next;
            if (a!=nullptr)
            {
                c->val += a->val;
                a = a->next;
            }
            if (b!=nullptr)
            {
                c->val += b->val;
                b = b->next;
            }
            c->val += inc;
            inc = c->val/10;
            c->val %= 10;
        }
        
        return hc->next;
    }
};