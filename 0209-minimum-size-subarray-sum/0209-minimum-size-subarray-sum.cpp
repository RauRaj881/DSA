class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int minlength=n+1;
        int sum=0;
        while(r<n){
            sum+=nums[r];
            while(l<=r&&sum>=target){
                minlength=min(minlength,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(minlength==n+1){return 0;}
        return minlength;
    }
};