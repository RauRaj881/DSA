class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2e4+1,-1));
        dp[0][nums[0]]=1;
        if(nums[0]!=0)dp[0][0]=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<=1e4;j++){
                if(dp[i-1][j]==-1){continue;}
                int xr=j^nums[i];
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                dp[i][xr]=max(dp[i][xr],dp[i-1][j]+1);
            }
        }
        if(dp[n-1][target]==-1){return -1;}
        return n-dp[n-1][target];
    }
};