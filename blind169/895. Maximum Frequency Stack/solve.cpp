class FreqStack {
public:
    priority_queue<vector<int>> s;
    unordered_map<int, int> cnt;
    int t;
    FreqStack() {
        t=0;
    }
    
    void push(int val) {
        if (!cnt.count(val))
            cnt[val]=0;
        ++cnt[val];
        s.push({cnt[val], t, val});
        ++t;
    }
    
    int pop() {
        auto item = s.top();
        s.pop();
        --cnt[item[2]];
        return item[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */