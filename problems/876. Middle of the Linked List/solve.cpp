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
    ListNode* middleNode(ListNode* head) {
        int n=1;
        ListNode *a=head;
        while(a->next!=nullptr)
        {
            ++n;
            a = a->next;
        }
        n/=2;
        while(n>0)
        {
            --n;
            head = head->next;
        }
        return head;
    }
};