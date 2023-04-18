struct Node{
    Node *a[26];
    bool end;
    Node(){
        end=false;
        for(int i=0;i<26;++i)
            a[i] = nullptr;
    }
};
class Trie {
public:
    Node *head;
    Trie() {
        head = new Node();
    }
    
    void insert(string word) {
        Node *p=head;
        char aa;
        for(auto &w:word)
        {
            aa = w-'a';
            if(p->a[aa]==nullptr)
                p->a[aa] = new Node();
            p = p->a[aa];
        }
        p->end = true;
    }
    
    bool search(string word) {
        Node *p=head;
        char aa;
        for(auto &w:word)
        {
            aa = w-'a';
            if(p->a[aa]==nullptr)
                return false;
            p = p->a[aa];
        }
        return p->end;
    }
    
    bool startsWith(string prefix) {
        Node *p=head;
        char aa;
        for(auto &w:prefix)
        {
            aa = w-'a';
            if(p->a[aa]==nullptr)
                return false;
            p = p->a[aa];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */