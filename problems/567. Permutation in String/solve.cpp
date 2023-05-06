class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        int c[26], n[26], cs=0, ns=0;
        memset(c, 0, sizeof(c));
        for(auto p:s1)
        {
            int pp = p-'a';
            if(c[pp]==0)
                ++cs;
            ++c[pp];
        }

        for(int i=0; i<s2.size()-s1.size()+1;++i)
        {
            int j=i;
            memset(n, 0, sizeof(n));
            ns = 0;
            for(;j<i+s1.size();++j)
            {
                pp = s2[j] - 'a';
                if(c[pp]==0) 
                {
                    i=j; 
                    break;
                }
                ++n[pp];
                if(n[pp]==c[pp]) ++ns;
                if(ns==cs) return true;
            }
        }
        return false;

    }
};