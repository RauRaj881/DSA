class Solution {
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
};