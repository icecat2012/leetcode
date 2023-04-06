class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col=matrix[0].size();
        int l=0, r=row*col-1;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            int i=mid/col, j=mid%col;
            if (matrix[i][j]==target) return true;
            if(matrix[i][j]>target)
                r = mid-1;
            else
                l = mid+1;
        }
        return false;
    }
};