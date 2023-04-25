class Solution {
public:
    unordered_set<int> done;
    bool isHappy(int n) {
        if(n==1) return true;
        if(done.count(n)) return false;
        done.insert(n);
        int ans=0;
        while(n)
        {
            int i=(n%10);
            ans+= (i*i);
            n/=10;
        }
        return isHappy(ans);
    }
};