class Solution {
public:
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0;i<9;++i)
        {
            for(int j=0;j<9;++j)
            {
                if(board[i][j]=='.')
                {
                    for(char k='1';k<='9';++k)
                    {
                        if(valid(board, i, j, k))
                        {
                            board[i][j]=k;
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';  
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool valid(vector<vector<char>>& board, int i, int j, char t)
    {
        for(int k=0;k<9;++k)
        {
            if(board[i][k]==t) return false;
            if(board[k][j]==t) return false;
        }
        for(int k=i/3*3;k<(i/3+1)*3;++k)
        {
            for (int l=j/3*3;l<(j/3+1)*3;++l)
            {
                if (board[k][l]==t) return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
       solve(board);
    }
};