class Solution {
public:
    string best="";
    string longestPalindrome(string s) {
        int start, end;
        for(int i=0;i<s.size();++i)
        {
            for (int j=s.size()-1;j>=i;--j)
            {
                bool flag=true;
                start=i;
                end=j;
                while(start<end)
                {
                    if(s[start]==s[end])
                    {
                        ++start;
                        --end;
                    }
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                if (flag && j-i+1>best.size())
                {
                    best = s.substr(i, j-i+1);
                    break;
                }
            }
            if (s.size()-i<best.size())
                break;
        }
        return best;
    }
};