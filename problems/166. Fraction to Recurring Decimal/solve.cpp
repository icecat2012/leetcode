class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0) return "0";
        long long int a=numerator, b=denominator;

        vector<bool> l(abs(b), 0);
        string ans;
        if((a<0 && b>0) || (a>0 && b<0))
            ans+="-";
        a = llabs(a);
        b = llabs(b);
        ans += to_string(a/b);
        a %= b;
        if(a==0) return ans;

        stack<int> rec;
        string ans_="";
        while(a>0)
        {
            if(l[a]==1)
            {
                int d=1;
                while(rec.top()!=a)
                {
                    ++d;
                    rec.pop();
                }
                ans_ = ans_.substr(0, ans_.size()-d) + "(" + ans_.substr(ans_.size()-d, d)+")";
                return ans+"."+ans_;
            }
            l[a] = 1;
            rec.push(a);
            a*=10;
            ans_ += to_string(a/b);
            a %= b;
        }

        return ans+"."+ans_;
    }
};