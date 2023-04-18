class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> index;
        for (int j=0;j<numCourses;++j)
            index[j] = vector<int>();
        for(auto &p:prerequisites)
            index[p[0]].push_back(p[1]);
        vector<int> work;
        unordered_set<int> done;
        for(auto &p:index)
            if(p.second.size()>0)
                work.push_back(p.first);
            else
                done.insert(p.first);
        int last=-1;
        while(work.size()!=last)
        {
            last = work.size();
            for(int j=work.size()-1;j>=0;--j)
            {
                int p=work[j];
                for(int i=index[p].size()-1;i>=0;--i)
                    if(done.count(index[p][i]))
                    {
                        index[p].erase(index[p].begin()+i);
                    }
                if(index[p].size()==0)
                {
                    done.insert(p);
                    work.erase(work.begin()+j);
                }
            }
        }
        return work.size()==0?true:false;
    }
};