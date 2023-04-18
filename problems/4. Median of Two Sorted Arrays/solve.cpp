class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size())
        {
            vector<int> tmp=nums1;
            nums1=nums2;
            nums2=tmp;
        }
        int total = nums1.size()+nums2.size();
        int half = total>>1;
        int l=0, r=nums1.size()-1;
        while (true)
        {
            int mid1 = (l+r)>>1;
            int mid2 = half - mid1 -2;

            int left1 = (mid1>=0)? nums1[mid1] : INT_MIN;
            int left2 = (mid2>=0)? nums2[mid2] : INT_MIN;
            int right1 = (mid1+1<nums1.size())? nums1[mid1+1]:INT_MAX;
            int right2 = (mid2+1<nums2.size())? nums2[mid2+1]:INT_MAX;
            if (left1<=right2 && left2<=right1)
            {
                if (total%2==1)
                    return min(right1, right2);
                else
                    return (max(left1, left2)+min(right1, right2))/2.0;
            }
            else
            {
                if (left1>right2)
                    r = mid1-1;
                else
                    l = mid1+1;
            }
        }
    }
};