class Solution {
public:
    bool mp[51][51];
    void dfs(vector<vector<int>>& image, int i, int j, int color, int target)
    {
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size()) return;
        if(image[i][j]!=target) return;
        if(mp[i][j]) return;
        mp[i][j] = 1;
        if (image[i][j]==target)
        {
            image[i][j] = color;
        }
        dfs(image, i+1, j, color, target);
        dfs(image, i-1, j, color, target);
        dfs(image, i, j+1, color, target);
        dfs(image, i, j-1, color, target);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        memset(mp, 0, sizeof(mp));
        dfs(image, sr, sc, color, image[sr][sc]);
        return image;
    }
};