class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        else if(strs.size()==1)
            return strs[0];

        int n=INT_MAX;
        for(auto &p:strs)
            n = min(n, (int)p.size());

        string ans="";
        for(int i=0;i<n;++i)
        {
            char target=strs[0][i];
            for (int j=1;j<strs.size();++j)
                if (strs[j][i]!= target)
                    return ans;
            ans+=target;
        }
        return ans;
        
    }
};