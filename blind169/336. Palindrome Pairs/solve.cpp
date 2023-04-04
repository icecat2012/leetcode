class Solution {
public:
    bool valid(string &a)
    {
        int i=0, j=a.size()-1;
        while(i<j)
        {
            if(a[i++]!=a[j--])
                return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> index;
        string tmp;
        for(auto &w:words)
        {
            tmp=w;
            reverse(tmp.begin(), tmp.end());
            index[tmp] = index.size();
        }

        vector<vector<int>> ans;
        if(index.count(""))
        {
            for(int i=0;i<words.size();++i)
            {
                if(words[i]!="" && valid(words[i]))
                {
                    ans.push_back({i, index[""]});
                    ans.push_back({index[""], i});
                }
            }
        }

        for(int i=0;i<words.size();++i)
        {
            if(index.count(words[i]) && index[words[i]]!=i)
            {
                ans.push_back({i, index[words[i]]});
            }
            
            for(int j=1;j<words[i].size();++j)
            {
                string left = words[i].substr(0,j);
                string right = words[i].substr(j, words[i].size()-j);
                if (valid(left) && index.count(right))
                    ans.push_back({index[right], i});
                if (valid(right) && index.count(left))
                    ans.push_back({i, index[left]});
            }
        }

        return ans;
    }
};