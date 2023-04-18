class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> tb;
        int target = nums.size()>>1;
        for (auto &p:nums)
        {
            if (!tb.count(p))
                tb[p] = 0;
            if(++tb[p] > target)
                return p;
        }
        return -1;
        // int c=0, ans=nums[0];
        // for(int i=0; i<nums.size(); i++){
        //     if(c == 0) ans=nums[i];
        //     c += (ans==nums[i]) ? 1:-1;
        // }
        // return ans;
    }
};