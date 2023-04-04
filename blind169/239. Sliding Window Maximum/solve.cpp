class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> index;
        vector<int> ans;
        for(int i=0;i<k;++i)
            index.insert(nums[i]);
        if(index.size()<k)
        {
            ans.push_back(*index.end());
            return ans;
        }
        
        for(int i=k;i<nums.size();++i)
        {
            ans.push_back(*(--index.end()));
            auto it = index.find(nums[i-k]);
            index.erase(it);
            index.insert(nums[i]);
        }
        ans.push_back(*(--index.end()));
        return ans;
    }
};