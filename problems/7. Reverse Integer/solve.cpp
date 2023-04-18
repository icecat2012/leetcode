class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN) return 0;
        int sign = x<0?-1:1;
        int ans=0;
        x = abs(x);
        ans+=(x%10);
        x/=10;
        while(x>0)
        {
            if(INT_MAX/10<ans) return 0;
            ans*=10;
            ans+=(x%10);
            x/=10;
        }
        return sign*ans;
    }
};