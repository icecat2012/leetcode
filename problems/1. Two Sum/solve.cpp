class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        vector<int> ans;
        for (int i=0;i<nums.size();++i)
        {
            if(index.count(target-nums[i]))
            {
                ans.push_back(i);
                ans.push_back(index[target-nums[i]]);
                return ans;
            }
            index[nums[i]] = i;
        }
        return ans;
    }
};