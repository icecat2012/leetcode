class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left, right;
        left.push_back(1);
        int now=1;
        for (auto &p:nums)
        {
            now*=p;
            left.push_back(now);
        }
        now=1;
        right.push_back(1);
        for (int i=nums.size()-1;i>=0;--i)
        {
            now*=nums[i];
            right.push_back(now);
        }
        
        for (int i=0;i<nums.size();++i)
        {
            nums[i] = left[i]*right[nums.size()-i-1];
        }
        return nums;
    }
};