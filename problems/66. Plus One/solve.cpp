class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int inc=1;
        for(int i=digits.size()-1;i>=0;--i)
        {
            digits[i] += inc;
            inc = digits[i]/10;
            digits[i] %= 10;
            if (inc==0)
                return digits;
        }
        if (inc==1)
        {
            digits.insert(digits.begin(), inc);
            return digits;
        }
        else
            return digits;
    }
};