class Solution {
public:
    vector<vector<string>> ans;
    bool check(string &s, int l, int r)
    {
        while(l<r)
        {
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    void dfs(vector<string> now, int index, string &s)
    {
        if(index==s.size())
        {
            ans.push_back(now);
            return;
        }
        for(int i=index;i<s.size();++i)
        {
            if(check(s, index, i))
            {
                now.push_back(s.substr(index, i-index+1));
                dfs(now, i+1, s);
                now.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> now;
        dfs(now, 0, s);
        return ans;
    }
};