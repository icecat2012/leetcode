class Solution {
public:

    bool canJump(vector<int>& nums) {
        int max_p=0, now=0;
        while (true)
        {
            max_p = max(nums[now]+now, max_p);
            if (max_p>=nums.size()-1 )
                return true;
            else if (now<max_p)
                ++now;
            else
                return false;
        }
        
    }
};