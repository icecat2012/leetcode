class Solution {
public:
    string decodeString(string s) {
        stack<string> a;
        string curr="", num="", tmp;
        for(auto &p:s)
        {
            if(p>='0' && p<='9')
            {
                num+=p;
            }
            else if(p=='[')
            {
                a.push(curr);
                a.push(num);
                curr = "";
                num = "";
            }
            else if(p==']')
            {
                tmp = "";
                for(int k=0;k<stoi(a.top());++k)
                    tmp+=curr;
                a.pop();
                curr = a.top() + tmp;
                a.pop();
                num = "";
            }
            else
            {
                curr+=p;
            }
        }
        return curr;
    }
};