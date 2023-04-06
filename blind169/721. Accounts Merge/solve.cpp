class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<set<string>>> index;
        for(auto &p:accounts)
        {
            if(!index.count(p[0]))
                index[p[0]]=vector<set<string>>();
            set<string> t(p.begin()+1, p.end());
            index[p[0]].push_back(t);
        }
        for(auto &p:index)
        {
            for(int i=p.second.size()-1;i>=0;--i)
            {
                for(int j=i-1;j>=0;--j)
                {
                    bool flag=false;
                    for(auto &t:p.second[i])
                    {
                        if(p.second[j].count(t))
                        {
                            p.second[j].insert(p.second[i].begin(), p.second[i].end());
                            p.second.erase(p.second.begin()+i);
                            flag=true;
                            break;
                        }
                    }
                    if(flag)
                        break;
                }
                
            }
        }

        vector<vector<string>> ans;
        for(auto &p:index)
        {
            vector<string> ans_;
            for (auto &emails:p.second)
            {
                ans_.clear();
                ans_.push_back(p.first);
                for (auto &email:emails)
                    ans_.push_back(email);
                ans.push_back(ans_);
            }
        }
        return ans;

    }
};