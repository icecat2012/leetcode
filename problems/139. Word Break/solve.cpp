class Solution {
public:
    unordered_set<string> index;
    unordered_map<int, bool> dp;
    
    bool find(string s, int now)
    {
        if(s.size()==now) return true;
        if(dp.count(now)) return dp[now];

        string tmp="";
        bool flag = false;
        for(int i=now;i<s.size();++i)
        {
            tmp+=s[i];
            if(index.count(tmp))
                flag |= find(s, i+1);
        }
        dp[now] = flag;
        return flag;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto &p:wordDict)
            index.insert(p);
        return find(s, 0);
    
    }
};