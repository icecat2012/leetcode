class Solution {
public:
    inline int transform(char a)
    {
        return (int)a;
    }
    string minWindow(string s, string t) {
        int left=0, right=0, best=INT_MAX, need[256], needs=0, now[256], nows=0, tmp;
        string best_s;
        memset(need, 0, sizeof(need));
        memset(now, 0, sizeof(now));
        for(auto &p:t)
        {
            tmp = transform(p);
            if(need[tmp]==0) ++needs;
            ++need[tmp];
        }

        while(left<s.size() && right<s.size())
        {
            while (right<s.size() && nows<needs) 
            {
                tmp=transform(s[right]);
                ++now[tmp];
                if (now[tmp]==need[tmp]) ++nows;
                ++right;
            }
            if (nows<needs)
                break;
            
            while (left<=right && nows>=needs)
            {
                tmp=transform(s[left]);
                if (now[tmp]==need[tmp]) --nows;
                --now[tmp];
                ++left;
            }
            if (nows==needs-1 && right-left<best)
            {
                best = right-(left-1);
                best_s = s.substr(left-1, best);
            }
        }
        return best==INT_MAX?"":best_s;
    }
};