class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1, ll=height[0], rr=height[height.size()-1];
        int ans=0, tmp;
        while(l<r)
        {
            if(height[l]<height[r])
            {
                tmp = ll-height[l];
                if(tmp>0)
                    ans+=tmp;
                else
                    ll = height[l];
                ++l;
            }
            else
            {
                tmp = rr-height[r];
                if(tmp>0)
                    ans+=tmp;
                else
                    rr = height[r];
                --r;
            }
        }
        return ans;
    }
};