class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[256];
        memset(a, 0, sizeof(a));
        for(auto &p:magazine)
            ++a[p];
        for(auto &p:ransomNote)
        {
            if (a[p]==0) return false;
            --a[p];
        }
        return true;
    }
};