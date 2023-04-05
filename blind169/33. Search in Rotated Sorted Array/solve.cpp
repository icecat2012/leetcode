class Solution {
public:
    int find(vector<int> &nums, int &target, int left, int right)
    {
        cout<<left<<' '<<right<<endl;
        if(left>right)
            return -1;
        int mid=(left+right)/2;
        if(nums[mid]==target)
            return mid;
            
        if(nums[mid]>nums[right])
        {
            if(target>nums[mid] || target<nums[left])
                return find(nums, target, mid+1, right);
            else
                return find(nums, target, left, mid-1);
        }
        else
        {
            if(target>nums[mid] && target<=nums[right])
                return find(nums, target, mid+1, right);
            else
                return find(nums, target, left, mid-1);
        }
    }
    int search(vector<int>& nums, int target) 
    {
        int left=0, right=nums.size()-1;
        return find(nums, target, left, right);
    }
};