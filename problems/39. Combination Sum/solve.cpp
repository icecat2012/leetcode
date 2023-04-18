class Solution {
public:
    vector<vector<int>> ans;
    void find(vector<int>& candidates, vector<int> now, int pt, int target)
    {
        if (target<0)
            return;
            
        for (int i=pt;i<candidates.size();++i)
        {
            if (target-candidates[i]==0)
            {
                now.push_back(candidates[i]);
                ans.push_back(now);
                return;
            }
            else if (target-candidates[i]<0)
                return;
            now.push_back(candidates[i]);
            find(candidates, now, i, target-candidates[i]);
            now.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        find(candidates, vector<int>(), 0, target);
        return ans;
    }
};