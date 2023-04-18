class Solution {
public:
    vector<string> ans;
    void dfs(vector<string> &t, string tmp, string d)
    {
        if (d.size()==0)
        {
            ans.push_back(tmp);
            return;
        }
        for(auto &p:t[(int)d[0]-'2'])
        {
            dfs(t, tmp+p, d.substr(1));
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return ans;
        vector<string> tem{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(tem, "", digits);
        return ans;
    }
};