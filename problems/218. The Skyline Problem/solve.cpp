class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<pair<int, int>>> d;
        for(auto &p:buildings)
        {
            d[p[0]].push_back(make_pair(p[2], 1));
            d[p[1]].push_back(make_pair(p[2], -1));
        }
        vector<vector<int>> ans;
        multiset<int> n;
        for(auto &p:d)
        {
            for(auto &pp:p.second)
            {
                if(pp.second==1)
                    n.insert(pp.first);
                else
                    n.erase(n.find(pp.first));
            }
            // x=p.first, y= *n.rbegin();
            int y = n.size()>0? *n.rbegin():0;
            if(ans.size()==0 || y!=ans.back()[1])
                ans.push_back({p.first, y});
        }
        return ans;
    }
};