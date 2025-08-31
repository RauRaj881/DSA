class Solution {
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
};