class Solution {
public:
    bool valid(char &a)
    {
        if((a>='a'&&a<='z' )||(a>='A'&&a<='Z' )||(a>='0'&&a<='9' ))
            return true;
        return false;
    }
    bool same(char &a, char &b)
    {
        if (a>='A' && a<='Z')
            a = a-'A'+'a';
        if (b>='A' && b<='Z')
            b = b-'A'+'a';
        return a==b;
    }
    bool isPalindrome(string s) {
        int i=0, j=s.size()-1;
        while (i<j)
        {
            while(i<s.size()-1 && !valid(s[i])) ++i;
            while(j>0 && !valid(s[j])) --j;
            if (j<=i) break;
            // cout<<i<<' '<<j<<' '<<s[i]<<' '<<s[j]<<endl;
            if (same(s[i], s[j]))
            {
                ++i;
                --j;
                continue;
            }
            return false;
        }
        return true;
    }
};