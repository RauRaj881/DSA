class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins){
        int m=coins.size();
        int n=coins[0].size();
        long long inf=1e16;
        vector<vector<vector<long long>>> dp(m,vector<vector<long long>>(n,vector<long long>(3,-inf)));
        dp[0][0][0]=coins[0][0];
        if(coins[0][0]<0){dp[0][0][1]=0;}
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<=2;k++){
                if(i==0&&j==0){
                    continue;
                }
                if(coins[i][j]>=0){
                    if(i>0){dp[i][j][k]=dp[i-1][j][k]+coins[i][j];}
                    if(j>0){dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+coins[i][j]);}
                }
                else{
                    if(k==0){
                        if(i>0){dp[i][j][k]=dp[i-1][j][k]+coins[i][j];}
                        if(j>0){dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+coins[i][j]);}
                    }
                    else{
                        long long a=-inf,b=-inf,c=-inf,d=-inf;
                        if(i>0){a=dp[i-1][j][k]+coins[i][j];}
                        if(j>0){b=dp[i][j-1][k]+coins[i][j];}
                        if(i>0){c=dp[i-1][j][k-1];}
                        if(j>0){d=dp[i][j-1][k-1];}
                        dp[i][j][k]=max({a,b,c,d});
                    }
                }
                }
            }
        }
        long long ans=INT_MIN;
        for(int k=0;k<=2;k++){
            ans=max(ans,dp[m-1][n-1][k]);
        }
        return ans;
    }
};