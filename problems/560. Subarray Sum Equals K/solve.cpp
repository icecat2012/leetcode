class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      vector<int> s(nums.begin(), nums.end());
      int t=0;
      for(auto &p:s)
      {
        t += p;
        p = t;
      }
      unordered_map<int, int> saw;
      int ans=0;
      saw[0] = 1;
      for(int i=0;i<nums.size();++i)
      {
        if (saw.count(s[i]-k))
        {
            ans += saw[s[i]-k];
        }
        
        if (!saw.count(s[i]))
            saw[s[i]]=0;
        ++saw[s[i]];
      }
      return ans;
    }
};