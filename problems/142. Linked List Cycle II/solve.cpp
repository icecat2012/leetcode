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
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode *s=head, *f=head;
        do{
            s = s->next;
            f = f->next->next;
        } while(s!=f && f!=nullptr && f->next!=nullptr);
        if(s==f)
        {
            f = head;
            while(s!=f)
            {
                s = s->next;
                f = f->next;
            }
            return s;
        }
        return nullptr;
    }
};