class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> edge;
        vector<int> degree(numCourses, 0);
        for(int i=0;i<numCourses;++i)
            edge[i] = vector<int>();
        for(auto &p:prerequisites)
        {
            edge[p[1]].push_back(p[0]);
            ++degree[p[0]];
        }
        //
        vector<int> finished;
        queue<int> work;
        for(int i=0;i<numCourses;++i)
        {
            if(degree[i]==0)
            {
                work.push(i);
            }
        }
        
        while(work.size()>0)
        {
            int t=work.front();
            work.pop();
            finished.push_back(t);
            for(auto &p:edge[t])
            {
                if(degree[p]==1)
                    work.push(p);
                --degree[p];
            }
        }
        
        if(finished.size()!=numCourses)
        {
            finished.clear();
        }
        return finished;
    }
};