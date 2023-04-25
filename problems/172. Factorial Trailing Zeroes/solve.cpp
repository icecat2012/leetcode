class Solution {
public:
    int trailingZeroes(int n) {
        int five_=0, two_=0;
        for(int i=1;i<=n;++i)
        {
            int j=i;
            while((j&1)==0 && j>0)
            {
                ++two_;
                j>>=1;
            }
            j=i;
            while(j%5==0 && j>0)
            {
                ++five_;
                j/=5;
            }
        }
        return min(two_, five_);
    }
};