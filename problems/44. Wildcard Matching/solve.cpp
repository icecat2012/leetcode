class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        s = '#' + s;
        p = '#' + p;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, 0));

        dp[0][0] = 1;
        for(int i=1;i<=n;++i)
        {
            if(p[i]!='*') break;
            dp[0][i] = 1;
        }

        for(int i=1;i<=m;++i)
            for(int j=1;j<=n;++j)
            {
                if(p[j]=='?' || p[j]==s[i])
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j]=='*')
                {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }

            }

        return dp[m][n];
    }
};