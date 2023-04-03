class Solution {
public:
    struct cmp{
        inline bool operator() (const vector<int> &a, const vector<int> &b)
        {
            return a[0]<b[0];
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()<=1)
            return intervals;

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end(), cmp());
        int start = intervals[0][0], end = intervals[0][1] , now=1;
        while (now<intervals.size())
        {
            if (end<intervals[now][0])
            {
                ans.push_back({start, end});
                start = intervals[now][0];
                end = intervals[now][1];
            }
            else
            {
                start = min(start, intervals[now][0]);
                end = max(end, intervals[now][1]);
            }
            ++now;
        }
        ans.push_back({start, end});
        return ans;
    }

};