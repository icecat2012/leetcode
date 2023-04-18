class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()<2) {return;}
        else if(nums.size()==2)
        {
            swap(nums[0], nums[1]);
            return;
        }
        int i=nums.size()-2, j=nums.size()-1;
        while (i>=0 && nums[i]>=nums[i+1]) --i;
        if (i>=0)
        {
            while(j>=0 && nums[j]<=nums[i]) --j;
            swap(nums[i], nums[j]);
        } 
        reverse(nums.begin()+i+1, nums.end());
    }
};