class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> index(nums.begin(), nums.end());
        int i=1;
        while (index.count(i)) ++i;
        return i;
    }
};