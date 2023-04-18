class Solution {
public:

    int characterReplacement(string s, int k) {
        if (s.size()<2)
            return s.size();
        
        int dp[256];
        memset(dp, 0, sizeof(dp));
        int start=0, longest=0;
        for(int i=0;i<s.size();++i)
        {
            ++dp[s[i]];
            longest = max(longest, dp[s[i]]);
            if (i-start+1-longest>k)
            {
                --dp[s[start]];
                ++start;
            }
        }

        return s.size()-start;
    }
};