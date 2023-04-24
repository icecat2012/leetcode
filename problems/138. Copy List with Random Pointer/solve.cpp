/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        unordered_map<Node*, Node*> tb;
        tb[nullptr] = nullptr;
        Node *p, *q, *h;
        p=head;
        q=new Node(p->val);
        h=q;
        tb[p] = q;
        while(p->next!=nullptr)
        {
            q->next = new Node(p->next->val);
            p = p->next;
            q = q->next;
            tb[p] = q;
        }
        p=head;
        q=h;
        while(p!=nullptr)
        {
            q->random = tb[p->random];
            p=p->next;
            q=q->next;
        }
        return h;
    }
};