class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k){
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        vector<vector<int>> pre(n,vector<int>(2001,0));
        for(int i=0;i<n;i++){
            pre[i][0]=piles[i][0];
            for(int j=1;j<piles[i].size();j++){
                pre[i][j]+=pre[i][j-1]+piles[i][j];
            }
        }
        for(int x=1;x<=k;x++){
            if(piles[0].size()>=x){
                dp[0][x]=pre[0][x-1];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=k;j++){
                for(int x=0;x<min(j,(int)piles[i].size());x++){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-x-1]+pre[i][x]);
                }
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
            }
        }
        return dp[n-1][k];
    }
};