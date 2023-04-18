class Solution {
public:
    struct cmp{
        inline bool operator() (const string &a, const string &b)
        {
            return a+b>b+a;
        }
    };
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(auto &p:nums)
            ans.push_back(to_string(p));
        sort(ans.begin(), ans.end(), cmp());
        string result="";
        for(auto &p:ans)
            result+=p;
        return result[0]=='0'?"0":result;
    }
};