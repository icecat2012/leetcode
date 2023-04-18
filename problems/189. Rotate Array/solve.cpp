class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        // if(k==0)
        //     return;
        // vector<int> tmp(nums.begin(), nums.end()-k);
        // nums.assign(nums.end()-k, nums.end());
        // nums.insert(nums.begin()+k, tmp.begin(), tmp.end());
        reverse(nums.begin(), nums.end()-k);
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};