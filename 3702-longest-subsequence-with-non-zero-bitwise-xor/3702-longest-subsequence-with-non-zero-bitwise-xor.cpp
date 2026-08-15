class Solution {
public:
    int longestSubsequence(vector<int>& nums){
        int n=nums.size();
        int xr=nums[0];
        int cnt0=0;
        if(nums[0]==0){cnt0++;}
        for(int i=1;i<nums.size();i++){
            xr^=nums[i];
            if(nums[i]==0){cnt0++;}
        }
        if(cnt0==n){return 0;}
        if(xr!=0){return n;}
        return n-1;
    }
};