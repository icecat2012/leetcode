class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0, j=height.size()-1, max_p=INT_MIN;
        while (i<j)
        {
            int min_v = min(height[i], height[j]);
            if (min_v*(j-i)>max_p)
            {
                max_p = min_v*(j-i);
            }
            
            if(height[i]> height[j])
                --j;
            else
                ++i;
        }
        return max_p;
    }
};