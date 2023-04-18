class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        int a, b;
        for(auto &p:tokens)
        {
            if(p=="+")
            {
                b = num.top();
                num.pop();
                a = num.top();
                num.pop();
                num.push(a+b);
            }
            else if(p=="-")
            {
                b = num.top();
                num.pop();
                a = num.top();
                num.pop();
                num.push(a-b);
            }
            else if(p=="*")
            {
                b = num.top();
                num.pop();
                a = num.top();
                num.pop();
                num.push(a*b);
            }
            else if(p=="/")
            {
                b = num.top();
                num.pop();
                a = num.top();
                num.pop();
                num.push(a/b);
            }
            else
            {
                num.push(stoi(p));
            }
        }
        return num.top();
    }
};