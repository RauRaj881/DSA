class Solution {
public:
    int stoneGameVII(vector<int>& s){
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[i][i]=0;
        }
        vector<int> pre(n+1,0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+s[i];
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                int lt=pre[j]-pre[i];
                int rt=pre[j+1]-pre[i+1];
                dp[i][j]=max(rt-dp[i+1][j],lt-dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};