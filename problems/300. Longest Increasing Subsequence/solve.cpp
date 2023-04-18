class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> stak;
        for(auto &p:nums)
        {
            if(stak.size()==0 || p>stak[stak.size()-1])
            {
                stak.push_back(p);
            }
            else
            {
                auto it = lower_bound(stak.begin(), stak.end(), p);
                *it = p;
            }
        }
        return (int)stak.size();
    }
};