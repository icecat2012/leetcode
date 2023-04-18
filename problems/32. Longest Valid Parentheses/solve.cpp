class Solution {
public:
    int longestValidParentheses(string s) {
        int best=0, l=0, r=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')
                ++l;
            else
                ++r;
            if(l==r)
                best = max(best, l+r);
            else if(l<r)
                l=0, r=0;
        }
        l=0, r=0;
        for(int i=s.size()-1;i>=0;--i)
        {
            if(s[i]=='(')
                ++l;
            else
                ++r;
            if(l==r)
                best = max(best, l+r);
            else if(l>r)
                l=0, r=0;
        }
        return best;
    }
};