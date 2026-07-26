class Solution {
public:
    int maxProfit(vector<int>& p){
        int n=p.size();
        vector<vector<int>> dp(n,vector<int>(2,INT_MIN));
        dp[0][0]=0;
        dp[0][1]=-p[0];
        for(int i=1;i<n;i++){
            for(int tp=0;tp<2;tp++){
                if(tp==0){
                    dp[i][tp]=max(dp[i-1][tp],dp[i-1][1]+p[i]);
                }
                else{
                    dp[i][tp]=max(dp[i-1][0]-p[i],dp[i-1][1]);
                }
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};