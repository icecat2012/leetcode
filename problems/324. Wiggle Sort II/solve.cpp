class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()%2==0)
            reverse(nums.begin(), nums.begin()+(nums.size()/2));
        else
            reverse(nums.begin(), nums.begin()+(nums.size()/2)+1);

        vector<int> ans(nums);
        int l=0, r=nums.size()-1;
        for(int i=0;i<nums.size();++i)
        {
            if(i&1)
            {
                nums[i] = ans[r];
                --r;
            }
            else
            {
                nums[i] = ans[l];
                ++l;
            }
        }
    }
};