class Solution {
public:
    int waysToReachTarget(int tar, vector<vector<int>>& tp){
        int n=tp.size();
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
        for(int i=0;i<=tp[0][0];i++){
            int vl=tp[0][1];
            if(i*vl<=tar)dp[0][i*vl]=1;
        }
        int mod=1e9+7;
        for(int i=1;i<n;i++){
            int cnt=tp[i][0];
            int mk=tp[i][1];
            for(int k=0;k<=tar;k++){
               for(int j=0;j<=cnt;j++){
                if(j*mk<=k){
                    dp[i][k]=(dp[i][k]+dp[i-1][k-j*mk])%mod;
                }
               }
            }
        }
        return dp[n-1][tar];
    }
};