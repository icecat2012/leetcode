class Solution {
public:
    int dp[13][10001];
    int find(vector<int> &coins, int amount, int now)
    {
        if(amount==0)
        {return 0;}
        else if(amount<0) 
        {return -1;}
        else if(dp[now][amount]!=0) 
        {return dp[now][amount];}

        int change=-1, best=INT_MAX;
        for(int i=now;i<coins.size();++i)
        {
            change = find(coins, amount-coins[i], i);
            if(change>=0)
                best = min(best, change+1);
        }
        dp[now][amount] = (best==INT_MAX)?-1:best;
        return dp[now][amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, 0, sizeof(dp));
        sort(coins.begin(), coins.end(), greater<int>());
        
        return find(coins, amount, 0);
    }
};