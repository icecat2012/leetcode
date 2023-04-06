class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& ans, int i, int j)
    {
        if(i<0||j<0||i>=matrix.size()||j>=matrix[0].size()) return 0;
        if(ans[i][j]!=0) return ans[i][j];

        int best=1;
        if(i+1<matrix.size() && matrix[i+1][j]>matrix[i][j])
            {best = max(best, dfs(matrix, ans, i+1, j)+1);}
        if(j+1<matrix[0].size() && matrix[i][j+1]>matrix[i][j])
            {best = max(best, dfs(matrix, ans, i, j+1)+1);}
        if(i-1>=0 && matrix[i-1][j]>matrix[i][j])
            {best = max(best, dfs(matrix, ans, i-1, j)+1);}
        if(j-1>=0 && matrix[i][j-1]>matrix[i][j])
            {best = max(best, dfs(matrix, ans, i, j-1)+1);}
        ans[i][j] = best;
        return best;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> ans(matrix);
        for(auto &p:ans)
            for(auto &v:p)
                v=0;
                
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[i].size();++j)
            {
                dfs(matrix, ans, i, j);
            }
        }
        
        int best=INT_MIN;
        for(int i=0;i<matrix.size();++i)
        {
            for(int j=0;j<matrix[i].size();++j)
            {
                best=max(best, ans[i][j]);
            }
        }
        return best;
    }
};