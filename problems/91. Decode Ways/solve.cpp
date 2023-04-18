class Solution {
public:
    int dp[101];
    int find(string &s, int now)
    {
        if(now==s.size()) return 1;
        else if(now>s.size()) return 0;
        else if(dp[now]!=-1) return dp[now];

        int ans=0;
        // get 1
        if(s[now]=='0')
        {
            dp[now] = 0;
            return 0;
        }
        ans += find(s, now+1);
        // get 2
        if(now+1<s.size())
        {
            if (s[now]=='1')
                ans+=find(s, now+2);
            else if(s[now]=='2' && s[now+1]<='6')
                ans+=find(s, now+2);
        }
        dp[now] = ans;
        return ans;
    }
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return find(s, 0);
    }
};