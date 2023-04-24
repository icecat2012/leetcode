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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> a;
        ListNode *p=headA;
        while(p!=nullptr)
        {
            a.insert(p);
            p = p->next;
        }
        p=headB;
        while(p!=nullptr)
        {
            if(a.count(p))
                return p;
            p=p->next;
        }
        return nullptr;
    }
};