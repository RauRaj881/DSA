//memoization
/*class Solution {
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
};*/
//tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int prev=-1;prev<i;prev++){
                int nottake=dp[i+1][prev+1];
             int take=0;
            if(prev==-1||nums[i]>nums[prev]){
            take=1+dp[i+1][i+1];
            }
          dp[i][prev+1]=max(take,nottake);
            }
        }
        return dp[0][0];
    }
};