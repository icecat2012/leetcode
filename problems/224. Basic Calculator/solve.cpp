class Solution {
public:
    int calculate(string s) {
        int sign=1;
        int result=0;
        int current=0;
        stack<int> ss;
        for(int i=0;i<s.size();++i)
        {
            switch(s[i])
            {
                case ' ':break;
                case '+':
                    result+=(sign*current);
                    current = 0;
                    sign = 1;
                    break;
                case '-':
                    result+=(sign*current);
                    current = 0;
                    sign = -1;
                    break;
                case '(':
                    ss.push(result);
                    ss.push(sign);
                    sign = 1;
                    result = 0;
                    break;
                case ')':
                    result+=(sign*current);
                    result*=ss.top();
                    ss.pop();
                    result+=ss.top();
                    ss.pop();
                    current = 0;
                    sign = 1;
                    break;
                default:
                    current*=10;
                    current+=(int)(s[i]-'0');
            }
        }
        result+=(sign*current);
        return result;
    }
};