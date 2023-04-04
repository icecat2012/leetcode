class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> tb;
        for(auto &p:strs)
        {
            string key=p;
            sort(key.begin(), key.end());
            if (!tb.count(key))
                tb[key] = vector<string>();
            tb[key].push_back(p);
        }
        vector<vector<string>> ans;
        for (auto &p:tb)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};