class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> mp(grid);
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(i==0 && j==0) continue;
                int a=INT_MAX, b=INT_MAX;
                if(i-1>=0) a = mp[i-1][j];
                if(j-1>=0) b = mp[i][j-1];
                mp[i][j] = grid[i][j] + min(a, b);
            }
        }
        return mp[mp.size()-1][mp[0].size()-1];
    }
};