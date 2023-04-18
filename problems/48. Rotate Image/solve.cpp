class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(auto &row:matrix)
            reverse(row.begin(), row.end());
        int n=matrix.size();
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n-i-1;++j)
            {
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            }
        }
    }
};