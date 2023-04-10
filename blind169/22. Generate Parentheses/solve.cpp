class Solution {
public:
    vector<string> ans;
    void rec(string a, int l, int r)
    {
        if (l==0 && r==0)
        {
            ans.push_back(a);
            return;
        }
        
        if (l>0)
            rec(a+"(", l-1, r);
        if (l < r)
            rec(a+")", l, r-1);
        return;
    }
    vector<string> generateParenthesis(int n) {
        rec("", n, n);
        return ans;
    }
};