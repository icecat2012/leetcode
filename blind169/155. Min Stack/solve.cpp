class MinStack {
public:
    MinStack() {
        
    }
    vector<pair<int, int>> data;
    void push(int val) {
        if(data.size()==0)
            data.push_back(make_pair(val, val));
        else
            data.push_back(make_pair(min(data[data.size()-1].first, val), val));    
    }
    
    void pop() {
        data.pop_back();        
    }
    
    int top() {
        return data[data.size()-1].second;
    }
    
    int getMin() {
        return data[data.size()-1].first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */