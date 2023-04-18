class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, zero_s=INT_MAX, nzero_s=INT_MAX;
        for(i=0;i<nums.size();++i)
        {
            if(zero_s==INT_MAX && nums[i]==0)
                zero_s = i;
            if(zero_s!=INT_MAX && nums[i]!=0)
            {
                nzero_s = i;
                break;
            }
        }
        while(nzero_s<nums.size() && zero_s<nums.size())
        {
            swap(nums[nzero_s], nums[zero_s]);
            ++zero_s;
            ++nzero_s;

            while(zero_s<nums.size() && nums[zero_s]!=0) ++zero_s;
            while(nzero_s<nums.size() && nums[nzero_s]==0) ++nzero_s;
        }
        
    }
};