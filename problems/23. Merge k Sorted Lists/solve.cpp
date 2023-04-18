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
struct cmp{
    inline bool operator()(const pair<int, ListNode*> &a, const pair<int, ListNode*> &b)
    {
        return a.first>b.first;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, cmp> p;
        ListNode *head=nullptr;
        for(int i=0;i<lists.size();++i)
            if(lists[i]!=nullptr)
                p.push(make_pair(lists[i]->val, lists[i]));
        
        if(p.size()==0) return head;

        ListNode *cur=p.top().second;
        head=cur;
        if(p.top().second->next!=nullptr)
            p.push(make_pair(p.top().second->next->val, p.top().second->next));
        p.pop();

        while(p.size()>0)
        {
            auto now = p.top();
            p.pop();
            if(now.second->next!=nullptr)
                p.push(make_pair(now.second->next->val, now.second->next));
            cur->next = now.second;
            cur = cur->next;
        }
        cur->next = nullptr;
        return head;
    }
};