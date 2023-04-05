class TimeMap {
public:

    struct cmp{
        inline bool operator()(const pair<int, string> &a, const pair<int, string> &b)
        {
            return a.first<b.first;
        }
    };

    unordered_map<string, vector<pair<int, string>>> tb;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (!tb.count(key))
            tb[key] = vector<pair<int, string>>();
        auto in = make_pair(timestamp, value);
        auto it=lower_bound(tb[key].begin(), tb[key].end(), in, cmp());
        tb[key].insert(it, in);
    }
    
    string get(string key, int timestamp) {
        if (!tb.count(key))
            return "";
            
        for(int i=tb[key].size()-1;i>=0;--i)
        {
            if(tb[key][i].first>timestamp)
                continue;
            return tb[key][i].second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */