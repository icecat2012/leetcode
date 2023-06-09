class Solution {
public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        if(board[i][j]=='X' || board[i][j]=='1') return;
        board[i][j]='1';
        dfs(board, i-1, j);
        dfs(board, i, j-1);
        dfs(board, i+1, j);
        dfs(board, i, j+1);
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int i=1;i<m-1;++i)
        {
            if(board[i][0]=='O')
                dfs(board, i, 0);
            if(board[i][n-1]=='O')
                dfs(board, i, n-1);
        }
        for(int i=0;i<n;++i)
        {
            if(board[0][i]=='O')
                dfs(board, 0, i);
            if(board[m-1][i]=='O')
                dfs(board, m-1, i);
        }
        //
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(board[i][j]=='1')
                    board[i][j] = 'O';
                else if(board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
    }
};