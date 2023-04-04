class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        bool mp[11][11];
        memset(mp, 0, sizeof(mp));
        int row=matrix.size(), col=matrix[0].size();
        for (int i=0;i<row;++i)
            mp[i][col]=1;
        for (int i=0;i<col;++i)
            mp[row][i]=1;
        
        vector<int> ans;
        int last=-1, i=0, j=0;
        while(last!=ans.size())
        {
            last = ans.size();
            while(mp[i][j+1]!=1)
                {mp[i][j]=1;ans.push_back(matrix[i][j++]);}
            while(mp[i+1][j]!=1)
                {mp[i][j]=1;ans.push_back(matrix[i++][j]);}
            while(j-1>=0 && mp[i][j-1]!=1)
                {mp[i][j]=1;ans.push_back(matrix[i][j--]);}
            while(i-1>=0 && mp[i-1][j]!=1)
                {mp[i][j]=1;ans.push_back(matrix[i--][j]);}
        }
        if (mp[i][j]==0)
            ans.push_back(matrix[i][j]);
        return ans;
    }
};