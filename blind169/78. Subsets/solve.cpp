class Solution {
public:
    vector<int> build(vector<int> &nums, int i, int n)
    {
        vector<int> ans;
        for(int j=0;j<n;++j)
        {
            if(i&1)
                ans.push_back(nums[j]);
            i>>=1;
        }
        
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int lim=1;
        lim<<=n;
        
        vector<vector<int>> ans;
        for (int i=0;i<lim;++i)
            ans.push_back(build(nums, i, n));
        return ans;
    }
};