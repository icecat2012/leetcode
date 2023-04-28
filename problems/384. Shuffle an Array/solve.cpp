class Solution {
public:
    vector<int> data, data1;
    Solution(vector<int>& nums) {
        data = nums;
        data1 = nums;
        srand(time(NULL));
    }
    vector<int> reset() {
        return data;
    }
    
    vector<int> shuffle() {
        int k=rand();
        srand(k);
        int a=rand()%data.size(), b=rand()%data.size();
        swap(data1[a], data1[b]);
        return data1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */