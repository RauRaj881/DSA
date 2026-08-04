class Solution {
public:
    int stoneGameV(vector<int>& s){
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+s[i];
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                for(int k=i;k<j;k++){
                    int ltsm=pre[k+1]-pre[i];
                    int rtsm=pre[j+1]-pre[k+1];
                    if(ltsm<rtsm){
                        dp[i][j]=max(dp[i][j],ltsm+dp[i][k]);
                    }
                    else if(rtsm<ltsm){
                        dp[i][j]=max(dp[i][j],rtsm+dp[k+1][j]);
                    }
                    else{
                        dp[i][j]=max(dp[i][j],ltsm+max(dp[i][k],dp[k+1][j]));
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};