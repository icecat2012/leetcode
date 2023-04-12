class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for (auto &p:s)
        {
            switch(p)
            {
                case '(':
                    a.push(')');
                    break;
                case '[':
                    a.push(']');
                    break;
                case '{':
                    a.push('}');
                    break;
                default:
                    if(a.size()==0)
                        return false;
                    if(a.top()!=p)
                        return false;
                    a.pop();
                    break;
            }
        }
        return a.size()==0?true:false;
    }
};