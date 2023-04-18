class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) return {};
        if(n==1) return {0};
        vector<int> res;
        vector<int> degree(n,0);

        vector<int> adj[n];

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                q.push(i);
            }
        }

        while(!q.empty()){
            
            res.clear();


            int level = q.size();

            for(int i=0;i<level;i++){
                int tar = q.front();
                q.pop();
                res.push_back(tar);

                for(auto it : adj[tar]){
                    degree[it]--;
                    if(degree[it]==1){
                        q.push(it);
                    }
                }
            }



        }

        return res;
    }
};