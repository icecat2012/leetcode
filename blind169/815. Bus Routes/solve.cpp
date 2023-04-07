class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        map<int, unordered_set<int>> stop;
        for(int i=0;i<routes.size();++i)
        {
            for(int j=0;j<routes[i].size();++j)
            {
                if(!stop.count(routes[i][j]))
                    stop[routes[i][j]] = unordered_set<int>();
                stop[routes[i][j]].insert(i);
            }
        }
        
        queue<int> stops;
        unordered_set<int> visit;
        for(auto &bus:stop[source])
        {
            visit.insert(bus);
            for(auto &s:routes[bus])
                if(s==target)
                    return 1;
                else
                    stops.push(s);
        }
        int ans=0;
        while(stops.size()>0)
        {
            int total = stops.size();
            ++ans;
            for(int i=0;i<total;++i)
            {
                if (stops.front()==target)
                    return ans;
                for (auto &b:stop[stops.front()])
                {
                    if (!visit.count(b))
                    {
                        visit.insert(b);
                        for (auto &s:routes[b])
                            stops.push(s);
                    }
                }
                stops.pop();
            }
        }
        return -1;
    }
};