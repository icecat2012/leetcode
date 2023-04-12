class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> pos;
        vector<int> ans;
        for(auto &p:asteroids)
        {
            if(p>0)
            {
                pos.push(p);
            }
            else
            {
                while(pos.size()>0 && p+pos.top()<0) pos.pop();
                if(pos.size()==0)
                    ans.push_back(p);
                else if(pos.top()+p==0)
                    pos.pop();
            }
        }
        int i=ans.size();
        while(pos.size()>0)
        {
            ans.push_back(pos.top());
            pos.pop();
        }
        reverse(ans.begin()+i, ans.end());
        return ans;
    }
};