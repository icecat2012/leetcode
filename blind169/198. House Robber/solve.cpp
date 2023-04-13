class Solution {
public:
    int dp[100+1];
    int find(vector<int> &nums, int now)
    {
        if (now>=nums.size())
            return 0;
        if (dp[now]!=-1)
            return dp[now];
        
        int ans = INT_MIN;
        for (int i=now;i<nums.size();++i)
        {
            int tmp = find(nums, i+2);
            ans = (tmp+nums[i]>ans)?tmp+nums[i]:ans;
        }
        dp[now] = ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return find(nums, 0);
    }
};