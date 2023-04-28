class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int, int> n;
        for(auto &n1:nums1)
            for(auto &n2:nums2)
                ++n[n1+n2];

        int ans=0;
        for(auto &n1:nums3)
            for(auto &n2:nums4)
                if(n.count(-(n1+n2)))
                    ans += n[-(n1+n2)];
        return ans;
    }
};