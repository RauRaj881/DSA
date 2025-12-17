class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
    long long n=prices.size();
    vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(3,vector<long long>(k+1,0)));
        for(int t=1;t<=k;t++){
            dp[0][1][t]=-prices[0];
            dp[0][2][t]=prices[0];
        }
        for(int i=1;i<n;i++){
            for(int t=1;t<=k;t++){
                dp[i][0][t]=max(dp[i-1][0][t],max(dp[i-1][1][t]+prices[i],dp[i-1][2][t]-prices[i]));
                dp[i][1][t]=max(dp[i-1][1][t],dp[i-1][0][t-1]-prices[i]);
                dp[i][2][t]=max(dp[i-1][2][t],dp[i-1][0][t-1]+prices[i]);
            }
        }
        return dp[n-1][0][k];
    }
};