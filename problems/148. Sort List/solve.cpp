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
    ListNode* sortList(ListNode* head) {
        ListNode *h=head;
        vector<int> num;
        while(h!=nullptr)
        {
            num.push_back(h->val);
            h = h->next;
        }
        sort(num.begin(), num.end());
        h=head;
        for (int i=0;i<num.size();++i){
            h->val = num[i];
            h=h->next;
        }

        return head;
    }
};