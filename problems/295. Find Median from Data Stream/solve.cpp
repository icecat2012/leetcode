struct cmp{
    inline bool operator()(const int &a, const int &b)
    {
        return a>b;
    }
};
class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int, vector<int>, cmp> big;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.size()==0)
            small.push(num);
        else if(small.top()>num)
            small.push(num);
        else
            big.push(num);
        
        if(big.size()>small.size())
        {
            small.push(big.top());
            big.pop();
        }
        else if(small.size()-2==big.size())
        {
            big.push(small.top());
            small.pop();
        }
    }
    
    double findMedian() {
        if((small.size()+big.size())%2==1)
        {
            return small.top();
        }
        else
        {
            return (small.top()+big.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */