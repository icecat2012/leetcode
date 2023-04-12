class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss, tt;
        for(auto &p:s)
        {
            if(p!='#')
                ss.push(p);
            else if(ss.size()>0)
                ss.pop();
        }
        for(auto &p:t)
        {
            if(p!='#')
                tt.push(p);
            else if(tt.size()>0)
                tt.pop();
        }
        if (ss.size()!=tt.size())
            return false;
        while(ss.size()>0)
        {
            if(ss.top()!=tt.top())
                return false;
            ss.pop();
            tt.pop();
        }
        return true;
    }
};