//memoization
class Solution {
public:
int ss(int index,int buy,int x,vector<int>& prices,vector<vector<vector<int>>> &dp,int k,int n){
    if(index==n||x==k){return 0;}
    if(dp[index][buy][x]!=-1){return dp[index][buy][x];}
    int profit;
    if(buy==0){
        profit=max(-prices[index]+ss(index+1,1-buy,x,prices,dp,k,n),ss(index+1,buy,x,prices,dp,k,n));
    }
    else{
        profit=max(prices[index]+ss(index+1,1-buy,x+1,prices,dp,k,n),ss(index+1,buy,x,prices,dp,k,n));
    }
    return dp[index][buy][x]=profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return ss(0,0,0,prices,dp,k,n);
    }
};