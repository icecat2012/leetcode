class Solution {
public:
    bool mp[7][7];
    bool find(vector<vector<char>>& board, string &word, int i, int j, int now)
    {
        if(now>=word.size()) return true;
        if(i<0||j<0||i>=board.size()||j>=board[0].size()) return false;
        if(mp[i][j]) return false;
        if(board[i][j]!=word[now]) return false;
        
        mp[i][j] = true;
        if(find(board, word, i+1, j, now+1)) return true;
        if(find(board, word, i-1, j, now+1)) return true;
        if(find(board, word, i, j+1, now+1)) return true;
        if(find(board, word, i, j-1, now+1)) return true;
        mp[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();++i)
        {
            for(int j=0;j<board[0].size();++j)
            {
                memset(mp, 0, sizeof(mp));
                if(find(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};