class Solution {
public:
    int jump(vector<int>& nums) {
        int mxsteps=-1;
        int newsteps=nums[0];
        int jump=0;
        int n=nums.size();
        if(n<=1)return 0;
        int j=0;
        while(j<n){
            jump++;
            int t=newsteps;
            for(j=mxsteps+1;j<=newsteps && j<n;j++){
                t=max(t,j+nums[j]);
            }
            mxsteps=newsteps;
            newsteps=t;
            if(mxsteps>=n-1)break;
        }
        return jump;
    }
};