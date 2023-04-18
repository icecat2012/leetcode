class Solution {
public:
    map<pair<int, int>, bool> dp;
    bool find(vector<int> &nums, int now, int left, int tt)
    {
        if(left==tt) return true;
        if(left>tt) return false;
        if(now==nums.size()) return false;
        if(dp.count(make_pair(now, left))) return dp[make_pair(now, left)];
        

        bool ans;
        ans = find(nums, now+1, left+nums[now], tt);
        if (ans)
        {
            dp[make_pair(now, left)] = true;
            return true;
        }
        ans |= find(nums, now+1, left, tt);
        dp[make_pair(now, left)] = ans;
        return ans;
    }
    bool canPartition(vector<int>& nums) {
        int tt = 0;
        for(auto &p:nums)
            tt+=p;
        if (tt%2)
            return false;
        sort(nums.begin(), nums.end(), greater<int>());
        return find(nums, 0, 0, tt/2);
    }
};