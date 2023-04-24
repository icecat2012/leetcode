class Solution {
public:
    vector<string> ans;
    unordered_set<string> a;
    void find(string &s, int n, string now)
    {
        if(n==s.size())
        {
            ans.push_back(now.substr(1));
            return;
        }
        string tmp="";
        for(int i=n;i<s.size();++i)
        {
            tmp+=s[i];
            if(a.count(tmp))
                find(s, i+1, now+' '+tmp);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto &p:wordDict)
            a.insert(p);
        string now="";
        find(s, 0, now);
        return ans;
    }
};