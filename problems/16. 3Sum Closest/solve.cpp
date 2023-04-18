class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int min_v=INT_MAX, best=INT_MAX;
        for (int i=0;i<nums.size()-2;++i)
        {
            int j=i+1, k=nums.size()-1;
            while(j<k)
            {
                int tmp = nums[i]+nums[j]+nums[k];
                int square = (tmp-target)*(tmp-target);
                if (square<min_v)
                {
                    // cout<<nums[i]<<' '<<nums[i+1]<<' '<<nums[i+2]<<endl;
                    best = nums[i]+nums[j]+nums[k];
                    min_v = square;
                }
                if (tmp-target==0)
                    return best;
                else if(tmp>target)
                    --k;
                else
                    ++j;
            }
        }
        return best;
    }
};