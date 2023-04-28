class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> a;
        for(auto &p:s)
            ++a[p];
        for(int i=0;i<s.size();++i)
            if(a[s[i]]==1) return i;
        return -1;
    }
};