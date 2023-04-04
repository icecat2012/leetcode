class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool tb[257];
        int best=INT_MIN, left=0, right=0;
        memset(tb, 0, sizeof(tb));
        while(right<s.size() && left<s.size())
        {
            while(right<s.size() && tb[s[right]]==0)
            {
                tb[s[right]]=1;
                ++right;
            }
            if (right-left>best)
                best = right-left;
            tb[s[left]] = 0;
            ++left;
        }
        return best==INT_MIN?0:best;
    }
};