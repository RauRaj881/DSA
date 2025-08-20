//memoization
/*class Solution {
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
};*/
//tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int sum=0;sum<=amount;sum++){
        if(sum%coins[0]==0){
            dp[0][sum]=sum/coins[0];
        }
        else dp[0][sum]=1e9;
        }
        for(int i=1;i<n;i++){
            for(int sum=0;sum<=amount;sum++){
                int nottake=dp[i-1][sum];
                int take=1e9;
                if(coins[i]<=sum){
                    take=1+dp[i][sum-coins[i]];
                }
                dp[i][sum]=min(take,nottake);
            }
        }
        if(dp[n-1][amount]!=1e9){return dp[n-1][amount];;}
        return -1;
    }
};