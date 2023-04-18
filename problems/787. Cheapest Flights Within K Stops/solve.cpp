class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(src==dst) return 0;
        vector<int> price(n, INT_MAX);
        price[src] = 0;
        unordered_map<int, vector<vector<int>>> f;
        for(auto &flight:flights)
        {
            if(!f.count(flight[0]))
                f[flight[0]] = vector<vector<int>>();
            f[flight[0]].push_back({flight[1], flight[2]});
        }

        queue<vector<int>> work;
        work.push({src, 0});
        while(work.size()>0)
        {
            if(k==-1) break;
            for(int i=work.size();i>0;--i)
            {
                int d=work.front()[0], c=work.front()[1];
                for (auto &next:f[d])
                {
                    if (next[1]+c<price[next[0]])
                    {
                        price[next[0]] = next[1]+c;
                        work.push({next[0], next[1]+c});
                    }
                }
                work.pop();
            }
            --k;
        }
        
        return price[dst]==INT_MAX?-1:price[dst];
    }
};