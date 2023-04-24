class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // y = mx + b
        // m = (y1-y2)/(x1-x2)
        // b = y1 - mx1;
        if (points.size()<3) return points.size();
        unordered_map<float, int> group;
        int best=1;
        for(int i=0;i<points.size();++i)
        {
            for(int j=i+1;j<points.size();++j)
            {
                auto p1=points[i];
                auto p2=points[j];
                float m;
                if(p1[0]-p2[0]==0)
                    m = numeric_limits<float>::max();
                else
                    m = (float)(p1[1]-p2[1])/(float)(p1[0]-p2[0]);
                ++group[m];
            }
            for(auto &p:group)
                best = max(best, p.second+1);
            group.clear();
        }
        return best;
    }
};