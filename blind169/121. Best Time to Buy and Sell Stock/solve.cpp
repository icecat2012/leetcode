class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_p=INT_MIN, min_v=INT_MAX;
        for (int i=0;i<prices.size();++i)
        {
            min_v = min(min_v, prices[i]);
            max_p = max(max_p, prices[i]-min_v);
        }
        return max_p;
    }
};