class Solution {
public:
    struct cmp{
        inline bool operator() (const vector<int> &a, const vector<int> &b)
        {
            return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];
        }
    };
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp());
        int i=1, ans=0, start=intervals[0][0], end=intervals[0][1];
        while(i<intervals.size())
        {
            if(end>intervals[i][0])
            {
                end = min(end, intervals[i][1]);
                ++ans;
            }
            else
                end = intervals[i][1];
            ++i;
        }
        return ans;
    }
};