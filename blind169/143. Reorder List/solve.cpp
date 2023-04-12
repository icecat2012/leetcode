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
    void reorderList(ListNode* head) {
        vector<ListNode*> a;
        ListNode *p=head;
        while(p!=nullptr)
        {
            a.push_back(p);
            p = p->next;
        }
        p=head;
        for(int i=1;i<a.size();++i)
        {
            if(i&1)
            {
                p->next = a[a.size()-1-i/2];
            }
            else
            {
                p->next = a[i/2];
            }
            p = p->next;
        }
        p->next = nullptr;
    }

};