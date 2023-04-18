class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN, cnt=0;
        for(auto &p:nums)
        {
            cnt+=p;
            ans = max(ans, cnt);
            cnt = cnt>0?cnt:0;
        }
        return ans;
    }
};