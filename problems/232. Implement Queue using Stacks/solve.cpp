class MyQueue {
public:
    MyQueue() {
        
    }
    stack<int> data, tmp;
    void push(int x) {
        data.push(x);
    }
    
    int pop() {
        while(data.size()>0)
        {
            tmp.push(data.top());
            data.pop();
        }
        int a = tmp.top();
        tmp.pop();
        while(tmp.size()>0)
        {
            data.push(tmp.top());
            tmp.pop();
        }
        return a;
    }
    
    int peek() {
        while(data.size()>0)
        {
            tmp.push(data.top());
            data.pop();
        }
        int a = tmp.top();
        while(tmp.size()>0)
        {
            data.push(tmp.top());
            tmp.pop();
        }
        return a;
        
    }
    
    bool empty() {
        return data.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */