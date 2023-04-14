class Solution {
public:
    int total;
    vector<int> prob;
    Solution(vector<int>& w) {
        srand(time(NULL));
        total=0;
        for(auto &p:w)
        {
            total+=p;
            prob.push_back(total);
        }
    }
    int find1(int p)
    {
        for(int i=0;i<prob.size();++i)
            if(p<prob[i])
                return i;
        return prob.size()-1;
    }
    int pickIndex() {
        int p = rand() % total;
        return find1(int(p));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */