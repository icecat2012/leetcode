class Solution {
public:
    vector<vector<int>> ans;
    void search(vector<int> &nums, vector<int> &now)
    {
        if(now.size()==nums.size())
        {
            ans.push_back(now);
            return;
        }
        
        for (auto &c:nums)
        {
            if (find(now.begin(), now.end(), c)!=now.end())
                continue;
            now.push_back(c);
            search(nums, now);
            now.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> now;
        search(nums, now);
        return ans;
    }
};