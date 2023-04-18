class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int needs=0, need[256], nows=0, now[256];
        memset(need, 0, sizeof(need));
        memset(now, 0, sizeof(now));
        for (auto &w:p)
        {
            if (need[w]==0) ++needs;
            ++need[w];
        }
        int left=0, right=0;
        while (left<s.size() && right<s.size())
        {
            while (left<s.size() && right<s.size() && left+p.size() > right && nows<needs)
            {
                if (need[s[right]]==0)
                {
                    ++right;
                    left=right;
                    memset(now, 0, sizeof(now));
                    nows=0;
                    continue;
                }
                ++now[s[right]];
                if (now[s[right]]==need[s[right]])
                    ++nows;
                ++right;
            }
            
            if (nows==needs)
                ans.push_back(left);
            if(now[s[left]]==need[s[left]]) --nows;
            --now[s[left]];
            ++left;
            right = (left>right)?left:right;
        }
        return ans;
    }
};