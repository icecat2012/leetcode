class Solution {
public:
    struct cmp{
        inline bool operator() (const vector<int> &a, const vector<int> &b)
        {
            return a[1]<b[1];
        }
    };
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> index;
        for (int i=0;i<startTime.size();++i)
            index.push_back({startTime[i], endTime[i], profit[i]});
        sort(index.begin(), index.end(), cmp());

        priority_queue<pair<int, int>> tb, tb_;
        tb.push(make_pair(0,0));
        for(int i=0;i<index.size();++i)
        {
            while(tb.top().second>index[i][0])
            {
                tb_.push(tb.top());
                tb.pop();
            }
            int local_best=tb.top().first;
            while(tb_.size()>0)
            {
                tb.push(tb_.top());
                tb_.pop();
            }
            
            tb.push(make_pair(index[i][2] + local_best, index[i][1]));
        }
        return tb.top().first;

    }
};