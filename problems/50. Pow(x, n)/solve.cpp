class Solution {
public:
    unordered_map<int, double> tb;
    double calculate(double x, int n)
    {
        if(tb.count(n)) return tb[n];
        int m=n/2;
        tb[n] = myPow(x, m)*myPow(x, n-m);
        return tb[n];
    }
    double myPow(double x, int n) {
        tb[0] = 1;
        tb[1] = x;
        tb[-1] = 1/x;
        if (x==1) return 1;
        return calculate(x, n);
    }
};