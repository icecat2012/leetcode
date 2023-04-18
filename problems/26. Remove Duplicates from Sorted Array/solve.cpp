class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int t=nums[0], now=1;
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]!=t)
            {
                t = nums[i];
                nums[now] = t;
                ++now;
            }
        }
        return now;
    }
};