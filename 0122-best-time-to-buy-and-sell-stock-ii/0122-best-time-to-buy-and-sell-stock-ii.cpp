//memoization
/*class Solution {
public:
int recur(int index,int x,vector<int>& prices,int n,int profit,vector<vector<int>> &dp){
    if(index==n){
        return 0;
    }
    if(dp[index][x]!=-1){
        return dp[index][x];
    }

    if(x==0){
        profit=max((-prices[index]+recur(index+1,1-x,prices,n,profit,dp)),recur(index+1,x,prices,n,profit,dp));
    }
    else{
        profit=max((prices[index]+recur(index+1,1-x,prices,n,profit,dp)),recur(index+1,x,prices,n,profit,dp));
    }
    return dp[index][x]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return recur(0,0,prices,n,0,dp);
    }
};*/
//tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
            if(j==0){
        int profit=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
        dp[i][j]=profit;
    }
    else{
        int profit=max(prices[i]+dp[i+1][0],dp[i+1][1]);
        dp[i][j]=profit;
    }
            }
        }
        return dp[0][0];
    }
};