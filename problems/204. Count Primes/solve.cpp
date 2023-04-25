class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        bool a[n];
        memset(a, 0, sizeof(a));
        a[0] = true;
        a[1] = true;
        int ans=0;
        for(int i=2;i<n;++i)
        {
            if(a[i]) continue;
            ++ans;
            int j=i<<1;
            while(j<n)
            {
                a[j] = true;
                j += i;
            }
        }
        
        return ans;
    }
};