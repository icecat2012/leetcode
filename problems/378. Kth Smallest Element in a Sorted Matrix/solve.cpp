class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> a;
        for(auto &p:matrix)
            for(auto &pp:p)
                a.push_back(pp);
        sort(a.begin(), a.end());
        return a[k-1];
    }
};