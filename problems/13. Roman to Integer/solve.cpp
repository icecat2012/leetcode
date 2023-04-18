class Solution {
public:
    int romanToInt(string s) {
        vector<int> ss;
        for(auto &p:s)
        {
            int a;
            switch(p)
            {
                case 'I': a=1; break;
                case 'V': a=5; break;
                case 'X': a=10; break;
                case 'L': a=50; break;
                case 'C': a=100; break;
                case 'D': a=500; break;
                case 'M': a=1000; break;
            }
            ss.push_back(a);
        }
        for(int i=0;i<ss.size()-1;++i)
            if(ss[i]<ss[i+1])
                ss[i] *= -1;
        
        int ans=0;
        for(auto &p:ss)
            ans+=p;
        return ans;
    }
};