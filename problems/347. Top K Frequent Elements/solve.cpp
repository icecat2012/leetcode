class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto &p:nums)
            ++mp[p];
        priority_queue<pair<int, int>> q;
        for(auto &p:mp)
            q.push(make_pair(p.second, p.first));
        
        vector<int> ans;
        for(;k>0;--k)
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};