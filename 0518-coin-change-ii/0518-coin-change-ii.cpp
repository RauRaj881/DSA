//memoization
class Solution {
public:
int cochange(int index,vector<vector<int>> &dp, vector<int>& coins,int amount){
    if(index==0){
        if(amount==0||amount%coins[index]==0){
            return 1;
        }
        else{return 0;}
    }
    if(dp[index][amount]!=-1){return dp[index][amount];}
    int nottake=cochange(index-1,dp,coins,amount);
    int take=0;
    if(coins[index]<=amount){
        take=cochange(index,dp,coins,amount-coins[index]);
    }
    return dp[index][amount]=take+nottake;
}
    int change(int amount, vector<int>& coins) {
        int totsum=0;
        int n=coins.size();
        for(auto it:coins){
            totsum+=it;
        }
        vector<vector<int>> dp(n,vector<int>(5001,-1));
        return cochange(n-1,dp,coins,amount);
    }
};