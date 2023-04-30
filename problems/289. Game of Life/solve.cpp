class Solution {
public:
    int check(vector<vector<int>>& board, int i, int j)
    {
        if(i<0||j<0||i>=board.size()||j>=board[0].size()) return 0;
        return board[i][j] & 1;
    }
    void update(vector<vector<int>>& board, int i, int j)
    {
        int cnt=0;
        cnt+=check(board, i-1, j-1);
        cnt+=check(board, i-1, j);
        cnt+=check(board, i-1, j+1);
        cnt+=check(board, i, j-1);
        cnt+=check(board, i, j+1);
        cnt+=check(board, i+1, j-1);
        cnt+=check(board, i+1, j);
        cnt+=check(board, i+1, j+1);
        if(board[i][j]==1)
        {
            if(cnt<2 || cnt>3) board[i][j] = 3;
        }
        else
        {
            if(cnt==3) board[i][j] = 2;
        }
        
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[i].size();++j)
                update(board, i, j);
                
        for(int i=0;i<board.size();++i)
            for(int j=0;j<board[i].size();++j)
                if(board[i][j]==2)
                    board[i][j] = 1;
                else if(board[i][j]==3)
                    board[i][j] = 0;
    }
};