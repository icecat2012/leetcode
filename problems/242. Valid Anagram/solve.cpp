class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;

        int tb[256], tbs=0;
        memset(tb, 0, sizeof(tb));
        for (auto &p:t)
        {
            if(tb[p]==0) ++tbs;
            ++tb[p];
        }

        for (auto &p:s)
        {
            if(tb[p]==1) --tbs;
            --tb[p];
        }
        return tbs>0?false:true;
    }

};