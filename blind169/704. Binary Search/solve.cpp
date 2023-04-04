class Solution {
public:
    int find(vector<int>& nums, int target, int left, int right)
    {
        if(left>right)
            return -1;

        int mid = (left+right)/2;
        if (nums[mid]==target)
            return mid;
        else if (target<nums[mid])
            return find(nums, target, left, mid-1);
        else
            return find(nums, target, mid+1, right);
    }
    int search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        
        return find(nums, target, i, j);
    }
};