struct Node{
    Node *a[26];
    bool end;
    Node(){
        end=false;
        for(int i=0;i<26;++i)
            a[i] = nullptr;
    }
};
class WordDictionary {
public:
    Node *head;
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
        Node *p=head;
        int t;
        for(auto &w:word)
        {
            t = (int)(w-'a');
            if(p->a[t]==nullptr)
                p->a[t] = new Node();
            p = p->a[t];
        }
        p->end = true;
    }
    bool find(Node *p, string &word, int now)
    {
        if (p==nullptr)
        {
            return false;
        }
        else if (now==word.size())
        {
            if(p->end) return true;
            else return false;
        }
        
        if(word[now]=='.')
        {
            for(int i=0;i<26;++i)
            {
                if(find(p->a[i], word, now+1))
                    return true;
            }
        }
        else
        {
            int t = (int)(word[now]-'a');
            return find(p->a[t], word, now+1);
        }
        return false;
    }
    bool search(string word) {
        return find(head, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */