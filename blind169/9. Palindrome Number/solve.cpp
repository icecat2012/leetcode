class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> xx;
        while(x>0)
        {
            xx.push_back(x%10);
            x/=10;
        }
        int l=0, r=xx.size()-1;
        while(l<r)
        {
            if(xx[l]!=xx[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
};