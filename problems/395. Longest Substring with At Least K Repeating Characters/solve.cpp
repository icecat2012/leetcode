class Solution {
public:
    int find(string s, int k)
    {
        if(s.size()==0) return 0;
        cout<<s<<endl;
        unordered_map<char, int> n;
        for(auto &p:s)
            ++n[p];
        unordered_set<char> b;
        for(auto &p:n)
            if(p.second<k)
                b.insert(p.first);
        if(b.size()==0) return s.size();
        int ans=0;
        while(s.size()>0)
        {
            int i=s.size()-1;
            while(i>=0 && b.count(s[i])) --i;
            if(i<0) break;
            s = s.substr(0, i+1);
            i=s.size()-1;
            while(i>=0 && !b.count(s[i])) --i;
            if(i<0) 
            {
                ans = max(ans, find(s.substr(i+1), k));
                break;
            }
            else
            {
                ans = max(ans, find(s.substr(i+1), k));
                s = s.substr(0, i+1);
            } 
        }
        return ans;
    }
    int longestSubstring(string s, int k) {
        return find(s, k);
    }
};