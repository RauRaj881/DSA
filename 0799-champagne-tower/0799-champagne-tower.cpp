class Solution {
public:
    double champagneTower(int prd, int rw, int gl){
        vector<vector<pair<double,double>>> dp(101,vector<pair<double,double>>(101));
        dp[0][0].first=prd>1?1:prd;
        dp[0][0].second=prd<=1?0:(double)(prd-1);
        for(int i=1;i<=rw;i++){
            for(int j=0;j<=i;j++){
                double x=j>0?dp[i-1][j-1].second/2:0;
                double y=dp[i-1][j].second/2;
                double tot=(x+y);
                dp[i][j].first=(tot>1?1:tot);
                dp[i][j].second=tot<=1?0:tot-1;
            }
        }
        return dp[rw][gl].first;
    }
};