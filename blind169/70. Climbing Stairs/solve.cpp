class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int s_2 = 1, s_1 = 2, tmp;
        for (int i=3;i<=n;++i)
        {
            tmp = s_2+s_1;
            s_2 = s_1;
            s_1 = tmp;
        }
        return s_1;
    }
};