class Solution {
public:
int ss(int index,int buy,vector<int>& prices,vector<vector<int>> &dp,int n){
    if(index>=n){return 0;}
    if(dp[index][buy]!=-1){return dp[index][buy];}
    if(buy==0){
        dp[index][buy]=max(-prices[index]+ss(index+1,1-buy,prices,dp,n),ss(index+1,buy,prices,dp,n));
    }
    else{
        dp[index][buy]=max(prices[index]+ss(index+2,1-buy,prices,dp,n),ss(index+1,buy,prices,dp,n));
    }
    return dp[index][buy];
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return ss(0,0,prices,dp,n); 
    }
};