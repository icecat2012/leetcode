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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1==nullptr) return list2;
        else if(list2==nullptr) return list1;

        ListNode *h, *a;
        if (list1->val<list2->val)
        {
            a=list1;
            list1 = list1->next;
        }
        else
        {
            a=list2;
            list2=list2->next;
        }
        h=a;

        while(list1!=nullptr && list2!=nullptr)
        {
            if (list1->val <=list2->val)
            {
                a->next = list1;
                list1 = list1->next;
            }
            else
            {
                a->next = list2;
                list2 = list2->next;
            }
            a = a->next;
        }
        if (list1==nullptr)
            a->next = list2;
        else
            a->next = list1;
        return h;
    }
};