class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int k=0;k<nums.size();++k)
        {
            nums[k] = nums[k]*nums[k];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};