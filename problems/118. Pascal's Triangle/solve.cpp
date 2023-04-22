class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> tmp;
        for(int i=1;i<=numRows;++i)
        {
            tmp.push_back(1);
            for(int j=1;j<i-1;++j)
            {
                // cout<<i<<' '<<j<<' '<<i-1<<' '<<j-1<<endl;
                tmp[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};