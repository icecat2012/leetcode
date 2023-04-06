class Solution {
public:
    bool mp[300][300];
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()) return;
        if (mp[i][j]==1) return;
        if (grid[i][j]=='1')
        {
            mp[i][j]=1;
            dfs(grid, i+1, j);
            dfs(grid, i-1, j);
            dfs(grid, i, j+1);
            dfs(grid, i, j-1);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        memset(mp, 0, sizeof(mp));
        int now=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]=='1' && mp[i][j]==0)
                {
                    ++now;
                    dfs(grid, i, j);
                }
            }
        }
        return now;
    }
};