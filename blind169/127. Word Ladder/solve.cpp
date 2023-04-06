class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        map<string, vector<string>> edge;
        map<string, set<string>> node;
        for(auto &p:wordList)
        {
            node[p] = set<string>();
            for(int i=0;i<p.size();++i)
            {
                string t=p;
                t[i]='*';
                if(!edge.count(t))
                    edge[t] = vector<string>();
                edge[t].push_back(p);
            }
        }
        for(auto &p:edge)
            for(auto &t:p.second)
                node[t].insert(p.second.begin(), p.second.end());
        
        queue<string> work;
        unordered_set<string> done;
        work.push(beginWord);
        int step=0;
        while(work.size()>0)
        {
            int rounds=work.size();
            ++step;
            for(int i=0;i<rounds;++i)
            {
                string now = work.front();
                if (now==endWord)
                    return step;
                work.pop();
                done.insert(now);
                for (auto &next:node[now])
                {
                    if(next==now)
                        continue;
                    if(!done.count(next))
                        work.push(next);
                }
            }
        }
        return 0;
    }
};