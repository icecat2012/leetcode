class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // set<int> tb;
        // for (auto &p:nums)
        // {
        //     if(tb.count(p))
        //         return true;
        //     tb.insert(p);
        // }
        // return false;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;++i)
            if (nums[i]==nums[i+1])
                return true;
        return false;
    }
};