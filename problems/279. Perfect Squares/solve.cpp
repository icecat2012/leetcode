class Solution {
public:
    int dp[10001];
    int find(vector<int> &coins, int n, int now)
    {
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];

        int ans = n;
        for(int i=now;i<coins.size()&&coins[i]<=n;++i)
            ans = min(ans, find(coins, n-coins[i], i)+1 );

        return dp[n] = ans;
    }
    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        vector<int> coins{1};
        for(int i=2;i*i<=n;++i)
            coins.push_back(i*i);
        return find(coins, n, 1);
    }
};