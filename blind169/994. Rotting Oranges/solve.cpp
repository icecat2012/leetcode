class Solution {
public:
    queue<pair<int,int>> work, nxt;
    int orangesRotting(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j]==2)
                    work.push(make_pair(i,j));
        int t=-1;
        while(work.size()>0)
        {
            int limit=work.size();
            for(int c=0;c<limit;++c)
            {
                int i=work.front().first, j=work.front().second;
                grid[i][j]=2;
                work.pop();
                
                if(i+1<grid.size() && grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    work.push(make_pair(i+1,j));
                }
                if(j+1<grid[0].size() && grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    work.push(make_pair(i,j+1));
                }
                if(i-1>=0 && grid[i-1][j]==1)
                {
                    grid[i-1][j]=2;
                    work.push(make_pair(i-1,j));
                }
                if(j-1>=0 && grid[i][j-1]==1)
                {
                    grid[i][j-1]=2;
                    work.push(make_pair(i,j-1));
                }
            }
            ++t;
        }

        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
                if(grid[i][j]==1)
                    return -1;
        return t==-1?0:t;
        
    }
};