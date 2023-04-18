class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check row
        bool mp[9];
        for(int i=0;i<9;++i)
        {
            memset(mp, 0, sizeof(mp));
            for(int j=0;j<9;++j)
            {
                if (board[i][j]=='.')
                    continue;
                if (mp[board[i][j]-'1']==1)
                    return false;
                mp[board[i][j]-'1']=1;
            }
        }
        //check col
        for(int i=0;i<9;++i)
        {
            memset(mp, 0, sizeof(mp));
            for(int j=0;j<9;++j)
            {
                if (board[j][i]=='.')
                    continue;
                if (mp[board[j][i]-'1']==1)
                    return false;
                mp[board[j][i]-'1']=1;
            }
        }
        //check block
        for(int offi=0;offi<3;++offi)
        {
            for(int offj=0;offj<3;++offj)
            {
                memset(mp, 0, sizeof(mp));
                for(int i=0+offi*3;i<3+offi*3;++i)
                {
                    for(int j=0+offj*3;j<3+offj*3;++j)
                    {
                        if (board[i][j]=='.')
                            continue;
                        if (mp[board[i][j]-'1']==1)
                            return false;
                        mp[board[i][j]-'1']=1;
                    }
                }
                
            }
        }
        return true;
    }
};