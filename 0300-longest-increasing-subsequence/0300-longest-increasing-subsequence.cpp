class Solution {
public:
int LIS(int index,int prev,vector<int>& nums,vector<vector<int>> &dp,int n){
    if(index==n){return 0;}
    if(dp[index][prev+1]!=-1){return dp[index][prev+1];}
    int nottake=LIS(index+1,prev,nums,dp,n);
    int take=0;
    if(prev==-1||nums[index]>nums[prev]){
        take=1+LIS(index+1,index,nums,dp,n);
    }
    return dp[index][prev+1]=max(take,nottake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return LIS(0,-1,nums,dp,n);
    }
};