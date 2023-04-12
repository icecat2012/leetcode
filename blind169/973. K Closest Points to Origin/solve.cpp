struct cmp{
    inline bool operator()(const vector<int> &a, const vector<int> &b)
    {
        return a[0]<b[0];
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> a;
        for(auto &p:points)
        {
            if(a.size()<k)
                {a.push({p[0]*p[0]+p[1]*p[1], p[0], p[1]});}
            else if(a.top()[0]>p[0]*p[0]+p[1]*p[1])
            {
                a.pop();
                a.push({p[0]*p[0]+p[1]*p[1], p[0], p[1]});
            }
        }
        vector<vector<int>> ans;
        for (int i=0;i<k;++i)
        {
            ans.push_back({a.top()[1], a.top()[2]});
            a.pop();
        }
        return ans;
    }
};