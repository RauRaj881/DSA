class Solution {
public:
    int maxProfit(vector<int>& p){
        int n=p.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,-1e9)));
        dp[0][0][1]=-p[0];
        dp[0][0][0]=0;
        for(int i=1;i<n;i++){
            for(int tk=0;tk<=2;tk++){
                int x=0;
                if(tk>0){x=p[i]+dp[i-1][tk-1][1];}
                dp[i][tk][0]=max(dp[i-1][tk][0],x);
                dp[i][tk][1]=max(dp[i-1][tk][1],dp[i-1][tk][0]-p[i]);
            }
        }
        return max({dp[n-1][1][0],dp[n-1][2][0],dp[n-1][0][0]});
    }
};