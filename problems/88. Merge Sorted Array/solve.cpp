class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m-1;i>=0;--i)
            nums1[i+n] = nums1[i];
        int i=n, j=0, now=0;
        while(i<m+n && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                nums1[now] = nums1[i];
                ++i;
            }
            else
            {
                nums1[now] = nums2[j];
                ++j;
            }
            ++now;
        }
        if(j<n)
            for(;j<n;++j)
            {
                nums1[now] = nums2[j];
                ++now;
            }
    }
};