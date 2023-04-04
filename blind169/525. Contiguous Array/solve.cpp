class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zeros=0, best=0;
        unordered_map<int, int> table;
        table[0]=-1;
        for (int i=0;i<nums.size();++i)
        {
            zeros += nums[i]==0?1:-1;
            if (table.count(zeros))
                best = max(best, i-table[zeros]);
            else
                table[zeros] = i;
        }
        return best; 
        
    }
};