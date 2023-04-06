class Solution {
public:
    void dfs(vector<vector<int>>& h, vector<vector<bool>> &mp, int i, int j)
    {
        mp[i][j] = 1;
        if(i+1<h.size() && h[i+1][j]>=h[i][j] && mp[i+1][j]==0)
            dfs(h, mp, i+1, j);
        if(j+1<h[0].size() && h[i][j+1]>=h[i][j] && mp[i][j+1]==0)
            dfs(h, mp, i, j+1);
        if(i-1>=0 && h[i-1][j]>=h[i][j] && mp[i-1][j]==0)
            dfs(h, mp, i-1, j);
        if(j-1>=0 && h[i][j-1]>=h[i][j] && mp[i][j-1]==0)
            dfs(h, mp, i, j-1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> A, P;
        for(auto &p:heights)
        {
            vector<bool> tmp(p.size(), 0);
            A.push_back(tmp);
            P.push_back(tmp);
        }
        for(int i=0;i<heights.size();++i)
        {
            P[i][0] = 1;
            A[i][heights[0].size()-1] = 1;
        }
        for(int i=0;i<heights[0].size();++i)
        {
            P[0][i] = 1;
            A[heights.size()-1][i] = 1;
        }
        // water flow
        for(int i=0;i<heights.size();++i)
        {
            dfs(heights, P, i, 0);
            dfs(heights, A, i, heights[0].size()-1);
        }
        for(int i=0;i<heights[0].size();++i)
        {
            dfs(heights, P, 0, i);
            dfs(heights, A, heights.size()-1, i);
        }
        // ans
        vector<vector<int>> ans;

        for(int i=0;i<heights.size();++i)
        {
            for(int j=0;j<heights[0].size();++j)
            {
                if(A[i][j]&&P[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};