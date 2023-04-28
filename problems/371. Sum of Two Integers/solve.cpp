class Solution {
public:
    int getSum(int a, int b) {
        while(b)
        {
            int inc = (unsigned int)(a&b)<<1;
            a = a^b;
            b = inc;
        }
        return a;
    }
};