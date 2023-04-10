class Solution {
public:
    bool col[9], pos[18], neg[18];
    vector<string> tem;
    vector<vector<string>> ans;
    vector<string> tmp;
    void dfs(int n, int lvl)
    {
        int po, ne;
        if (tmp.size()==n)
        {
            ans.push_back(tmp);
            return;
        }
        for (int i=0;i<n;++i)
        {
            ne = i+lvl;
            po = i-lvl + 9;
            if (col[i] || pos[po] || neg[ne])
                continue;
            col[i] = 1;
            pos[po] = 1;
            neg[ne] = 1;
            tmp.push_back(tem[i]);
            dfs(n, lvl+1);
            col[i] = 0;
            pos[po] = 0;
            neg[ne] = 0;
            tmp.pop_back();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        memset(col, 0, sizeof(col));
        memset(pos, 0, sizeof(pos));
        memset(neg, 0, sizeof(neg));
        string s="";
        for (int i=0;i<n;++i)
            s+=".";
        for (int i=0;i<n;++i)
        {
            s[i]='Q';
            tem.push_back(s);
            s[i]='.';
        }

        dfs(n, 0);

        return ans;
    }
};