class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> tb(nums.begin(), nums.end());
        
        int max_l;
        for (int i=0;i<nums.size();++i)
        {
            if (!tb.count(nums[i]-1))
            {
                int start=nums[i], cnt=1;
                while(tb.count(++start))
                    ++cnt;
                max_l = max(max_l, cnt);
            }
        }
        return max_l;
    }
};