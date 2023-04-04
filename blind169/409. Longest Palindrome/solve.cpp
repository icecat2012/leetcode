class Solution {
public:
    int transform(char &a)
    {
        if(a>='a'&&a<='z')
            return (int)a-'a';
        else
            return (int)a-'A'+26;
    }
    int longestPalindrome(string s) {
        int tb[26*2];
        memset(tb, 0, sizeof(tb));
        for(auto &p : s)
        {
            ++tb[transform(p)];
        }
        int ans=0;
        bool flag=false;
        for(int i=0;i<26*2;++i)
        {
            if(tb[i]%2==1)
                flag=true;
            ans += (tb[i]>>1)<<1;
        }
        return flag?ans+1:ans;
    }
};