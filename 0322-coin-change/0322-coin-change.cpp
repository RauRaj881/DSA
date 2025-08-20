class Solution {
public:
int coinchange(int index,int amount, vector<vector<int>> &dp,vector<int>& coins){
    if(index==0){
        if(amount%coins[0]==0){return amount/coins[0];}
        else {return 1e9;}
    }
    if(dp[index][amount]!=-1){return dp[index][amount];}
        int nottake=coinchange(index-1,amount,dp,coins);
        int take=1e9;
        if(coins[index]<=amount){
            take=1+coinchange(index,amount-coins[index],dp,coins);
        }
        return dp[index][amount]=min(take,nottake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int x=coinchange(n-1,amount,dp,coins);
        if(x!=1e9){return x;}
        else return -1;
    }
};