//memoization
/*class Solution {
public:
int recur(int index,int x,int k,int n,vector<int>& prices, vector<vector<vector<int>>> &dp,int profit){
    if(index==n||k==2){return 0;}
    if(dp[index][x][k]!=-1){
        return dp[index][x][k];
    }

    if(x==0){
        profit=max((-prices[index]+recur(index+1,1-x,k,n,prices,dp,profit)),recur(index+1,x,k,n,prices,dp,profit));
    }
    else{
        profit=max((prices[index]+recur(index+1,1-x,k+1,n,prices,dp,profit)),recur(index+1,x,k,n,prices,dp,profit));
    }
    return dp[index][x][k]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return recur(0,0,0,n,prices,dp,0);
    }
};*/
//tabulation 1
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                if(j==0){
                    dp[i][j][k]=max(-prices[i]+dp[i+1][1][k],dp[i+1][0][k]);
                }
                else{
                    dp[i][j][k]=max(prices[i]+dp[i+1][0][k+1],dp[i+1][1][k]);
                }
            }
            }
        }
        return dp[0][0][0];
    }
};*/
//tabulation 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,0)));
        for(int t=1;t<=2;t++){
            dp[0][1][t]=-prices[0];
        }
        for(int i=1;i<n;i++){
            for(int t=1;t<=2;t++){
                dp[i][0][t]=max(dp[i-1][0][t],dp[i-1][1][t]+prices[i]);
                dp[i][1][t]=max(dp[i-1][1][t],dp[i-1][0][t-1]-prices[i]);
            }
        }
        return dp[n-1][0][2];
    }
};
//space optimization
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
        vector<vector<int>> prev(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            vector<vector<int>> curr(2,vector<int>(3));
            for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                if(j==0){
                    curr[j][k]=max(-prices[i]+prev[1][k],prev[0][k]);
                }
                else{
                    curr[j][k]=max(prices[i]+prev[0][k+1],prev[1][k]);
                }
            }
            }
            prev=curr;
        }
        return prev[0][0];
    }
};*/