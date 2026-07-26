class Solution {
public:
    int maxProfit(vector<int>& p){
        int n=p.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1e6)));
        dp[0][1][0]=-p[0];
        dp[0][0][0]=0;
        for(int i=1;i<n;i++){
            for(int t=1;t<=2;t++){
                dp[i][0][0]=dp[i-1][0][0];
                dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][0][0]-p[i]);
                dp[i][0][t]=max(dp[i-1][0][t],dp[i-1][1][t-1]+p[i]);
                dp[i][1][t]=max(dp[i-1][1][t],dp[i-1][0][t]-p[i]);
            }
        }
        return max(0,max(dp[n-1][0][1],dp[n-1][0][2]));
    }
};