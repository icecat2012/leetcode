class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int smal = INT_MAX, mid = INT_MAX;
        for(int &n: nums){
            if(n <= smal) smal = n;
            else if(n <= mid) mid = n;
            else return true;
        }
        return false;
    }
};