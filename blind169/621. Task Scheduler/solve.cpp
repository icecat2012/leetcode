class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> works;
        for(auto &p:tasks)
            ++works[p];
        
        priority_queue<int> ready;
        queue<pair<int, int>> waiting;
        for(auto &p:works)
            ready.push(p.second);
        
        int tt=0, now;
        while(ready.size()>0 || waiting.size()>0)
        {
            while(waiting.size()>0 && waiting.front().second<tt)
            {
                ready.push(waiting.front().first);
                waiting.pop();
            }
            if(ready.size()==0)
            {
                ++tt;
                continue;
            }
            now = ready.top()-1;
            ready.pop();
            if(now>0)
                waiting.push(make_pair(now, tt+n));
            ++tt;
        }
        return tt;
    }
};