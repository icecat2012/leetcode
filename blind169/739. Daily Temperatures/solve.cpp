class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> rec;
        
        for(int i=temperatures.size()-1;i>=0;--i)
        {
            while(rec.size()>0)
            {
                if (temperatures[rec.top()]>temperatures[i])
                {
                    ans[i] = rec.top()-i;
                    rec.push(i);
                    break;
                }
                else
                    rec.pop();
            }
            if(rec.size()==0)
            {
                rec.push(i);
                continue;
            }
        }
        return ans;
    }
};