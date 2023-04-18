struct cmp{
    inline bool operator()(const pair<int, string> &a, const pair<int, string> &b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        return a.first<b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> a;
        
        sort(words.begin(), words.end());
        string last=words[0]; 
        int cnt=0;
        for(auto &p:words)
        {
            if(last!=p)
            {
                a.push(make_pair(cnt, last));
                last=p;
                cnt=1;
                continue;
            }
            ++cnt;
        }
        a.push(make_pair(cnt, last));
        vector<string> ans;
        while(ans.size()<k)
        {
            ans.push_back(a.top().second);
            a.pop();
        }
        // cout<<"FIN"<<endl;
        return ans;
    }
};