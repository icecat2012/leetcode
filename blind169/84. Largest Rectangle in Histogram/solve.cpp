class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<pair<int, int>> rec;
        for(int i=0;i<heights.size();++i)
        {
            int start = i;
            while (rec.size()>0 && rec.top().second>heights[i])
            {
                start = rec.top().first;
                maxArea = max(maxArea, rec.top().second * (i-start));
                rec.pop();
            }
            rec.push(make_pair(start, heights[i]));
        }
        while(rec.size()>0)
        {
            maxArea = max(maxArea, rec.top().second*((int)heights.size()-rec.top().first));
            rec.pop();
        }
        return maxArea;
    }
};