class Solution {
public:
    string trans(string a)
    {
        string ans="";
        int cnt=1, i=1;
        for(i=1;i<a.size();++i)
        {
            if(a[i]==a[i-cnt])
                {++cnt;}
            else
            {
                ans += to_string(cnt);
                ans += a[i-cnt];
                cnt=1;
            }
        }
        ans += to_string(cnt);
        ans += a[i-cnt];
        return ans;
    }
    string countAndSay(int n) {
        if(n==1) return "1";
        string say = countAndSay(n-1);
        return trans(say);
    }
};