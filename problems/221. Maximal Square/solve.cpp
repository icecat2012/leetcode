class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int ans=0;
        for(int i=0;i<matrix.size();++i)
        {
            dp[i][matrix[0].size()-1] = matrix[i][matrix[0].size()-1]-'0';
            if(matrix[i][matrix[0].size()-1]=='1')
                ans=1;
        }
        for(int i=0;i<matrix[0].size();++i)
        {
            dp[matrix.size()-1][i] = matrix[matrix.size()-1][i]-'0';
            if(matrix[matrix.size()-1][i]=='1')
                ans=1;
        }
        
        for(int i=matrix.size()-2;i>=0;--i)
            for(int j=matrix[0].size()-2;j>=0;--j)
            {
                if(matrix[i][j]=='0')
                {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = min({dp[i+1][j], dp[i+1][j+1], dp[i][j+1]})+1;
                ans = max(ans, dp[i][j]);
            }
        return ans*ans;
    }
};