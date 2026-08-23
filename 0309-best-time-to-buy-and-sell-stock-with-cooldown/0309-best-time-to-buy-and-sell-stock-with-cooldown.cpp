class Solution {
public:
    int maxProfit(vector<int>& p){
        int n=p.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][1]=-p[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+p[i]);
            int cr=0;
            if(i>=2){cr=dp[i-2][0];}
            dp[i][1]=max(dp[i-1][1],cr-p[i]);
        }
        return dp[n-1][0];
    }
};