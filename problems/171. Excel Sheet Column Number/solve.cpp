class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(auto &p:columnTitle)
        {
            int c = p-'A'+1;
            ans *= 26;
            ans += c;
        }
        return ans;
    }
};