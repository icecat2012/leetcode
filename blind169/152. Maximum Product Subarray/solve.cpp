class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int best=nums[0], max_=nums[0], min_=nums[0], tmp;
        for(int i=1;i<nums.size();++i)
        {
            tmp = max_;
            max_ = max({nums[i], tmp*nums[i], min_*nums[i]});
            min_ = min({nums[i], tmp*nums[i], min_*nums[i]});
            best = max(best, max_);
        }
        return best;
    }
};