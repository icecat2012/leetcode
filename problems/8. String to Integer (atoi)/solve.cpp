class Solution {
public:
    int myAtoi(string s) {
        long long int ans=0;
        bool sign=true;
        int i=0;
        while(s[i]==' ') ++i;
        if (s[i]=='+') {++i;}
        else if(s[i]=='-') {sign=false;++i;}
        while(i<s.size())
        {
            if(s[i]<'0'||s[i]>'9')
                break;
            ans*=10;
            ans+=s[i]-'0';
            ++i;
            if(ans-1>INT_MAX)
                break;
        }
        if(sign==false)
            ans*=-1;
        if (ans>INT_MAX) ans=INT_MAX;
        else if(ans<INT_MIN) ans=INT_MIN;
        return (int)ans;
    }
};