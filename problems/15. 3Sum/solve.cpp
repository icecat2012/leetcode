class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0, j=1, k=2;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        while (i<nums.size()-2)
        {
            if (nums[i]>0)
                break;
                
            j = i+1;
            k = nums.size()-1;
            while(j<k)
            {
                if (nums[i]+nums[j]+nums[k]==0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while (j<k && nums[k]==nums[k-1])
                        --k;
                    --k;
                    while (j<k && nums[j]==nums[j+1])
                        ++j;
                    ++j;
                }
                else if (nums[i]+nums[j]+nums[k]>0)
                {
                    while (j<k && nums[k]==nums[k-1])
                        --k;
                    --k;
                }
                else
                {
                    while (j<k && nums[j]==nums[j+1])
                        ++j;
                    ++j;
                }
            }

            while (i<nums.size()-2 && nums[i]==nums[i+1])
                ++i;
            ++i;
        }
        return ans;
    }
};