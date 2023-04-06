class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(nums[(mid+1)%nums.size()]>=nums[mid] && nums[(nums.size()+mid-1)%nums.size()]>=nums[mid]) return nums[mid];
            if (nums[mid]<nums[l])
                r=mid-1;
            else if (nums[l]<nums[r])
                r=mid-1;
            else
                l=mid+1;
        }
        return nums[l];
    }
};