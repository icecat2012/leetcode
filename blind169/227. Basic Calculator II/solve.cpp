class Solution {
public:
    int calculate(string s) {
        int result=0, pre=0, cur=0, tmp;
        char last='+';
        int i=0;
        s += '+';
        while(i<s.size())
        {
            if(s[i]==' ')
            {++i;continue;}
            else if(s[i]>='0' && s[i]<='9')
            {
                cur*=10;
                cur+=(s[i]-'0');
            }
            else
            {
                if(last=='+')
                {
                    result += cur;
                    pre = cur;
                }
                else if(last=='-')
                {
                    result -= cur;
                    pre = -cur;
                }
                else if(last=='*')
                {
                    result -= pre;
                    tmp = pre*cur;
                    result += tmp;
                    pre = tmp;
                }
                else
                {
                    result -= pre;
                    tmp = pre/cur;
                    result += tmp;
                    pre = tmp;
                }
                cur = 0;
                last = s[i];
            }
            ++i;
        }
        return result;
    }
};