class Solution {
public:
    int coinChange(vector<int>& c,int amt){
        int n=c.size();
        vector<vector<int>> dp(n,vector<int>(amt+1,1e9));
        dp[0][0]=0;
        for(int i=c[0];i<=amt;i+=c[0]){
            dp[0][i]=i/c[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                int nt=dp[i-1][j];
                int t=INT_MAX;
                if(c[i]<=j){t=1+dp[i][j-c[i]];}
                dp[i][j]=min(t,nt);
            }
        }
        if(dp[n-1][amt]==1e9){return -1;}
        return dp[n-1][amt];
    }
};