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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *a=head, *b=head->next, *ha=head, *hb=head->next;
        head = head->next->next;
        bool i=0;
        while(head!=nullptr)
        {
            if(i)
            {
                b->next = head;
                b = b->next;
            }
            else
            {
                a->next = head;
                a = a->next;
            }
            head = head->next;
            i = (!i);
        }
        b->next = nullptr;
        a->next = hb;
        return ha;
    }
};