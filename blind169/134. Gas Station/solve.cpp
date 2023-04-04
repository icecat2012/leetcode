class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0, car=0, start=0;

        for (int i=0;i<gas.size();++i)
        {
            total += gas[i]-cost[i];
            car += gas[i]-cost[i];
            if (car<0)
            {
                car = 0;
                start = (i+1)%gas.size();
            }
        }
        return total>=0?start:-1;
    }
};