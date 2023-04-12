class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> index;
        for(auto &p:nums)
        {
            if(index.size()<k)
            {
                index.push(p);
                continue;
            }
            if(p>index.top())
            {
                index.pop();
                index.push(p);
            }
        }
        
        return index.top();
    }
};