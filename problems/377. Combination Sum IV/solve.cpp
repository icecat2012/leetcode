class Solution {
public:
    int dp[10001];
    int find(vector<int>& nums, int &t, int cur)
    {
        if (cur==t) return 1;
        else if(cur>t) return 0;
        if (dp[cur]!=-1) return dp[cur];

        int ans=0;
        for(int i=0;i<nums.size();++i)
        {
            if(cur+nums[i]>t)
                continue;
            ans+=find(nums, t, cur+nums[i]);
        }
        dp[cur] = ans;
        return ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return find(nums, target, 0);
    }
};