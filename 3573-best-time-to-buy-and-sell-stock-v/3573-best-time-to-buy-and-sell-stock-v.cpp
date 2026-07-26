#define ll long long
class Solution {
public:
    long long maximumProfit(vector<int>& p, int k){
        int n=p.size();
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(3,vector<ll>(k+1,-1e17)));
        dp[0][0][0] = 0;
        dp[0][1][0]=-p[0];
        dp[0][2][0]=p[0];
        for(int i=1;i<n;i++){
            for(int t=0;t<=k;t++){
                if(t==0){
                    dp[i][0][0]=dp[i-1][0][0];
                    dp[i][1][0]=max(dp[i-1][1][0],dp[i-1][0][0]-p[i]);
                    dp[i][2][0]=max(dp[i-1][2][0],dp[i-1][0][0]+p[i]);
                }
                else{
                    dp[i][0][t]=max(dp[i-1][0][t],max(dp[i-1][1][t-1]+p[i],dp[i-1][2][t-1]-p[i]));
                    dp[i][1][t]=max(dp[i-1][1][t],dp[i-1][0][t]-p[i]);
                    dp[i][2][t]=max(dp[i-1][2][t],dp[i-1][0][t]+p[i]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<=k;i++){
            ans=max(ans,dp[n-1][0][i]);
        }
        return ans;
        
    }
};