class Solution {
public:
    int minScoreTriangulation(vector<int>& v){
        int n=v.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                dp[i][j]=1e9;
                for(int k=i+1;k<j;k++){
                    int curr=v[i]*v[j]*v[k]+dp[i][k]+dp[k][j];
                    dp[i][j]=min(dp[i][j],curr);
                }
            }
        }
        return dp[0][n-1];
    }
};