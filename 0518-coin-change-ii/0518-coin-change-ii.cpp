//memoization
/*class Solution {
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
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(5001,-1));
        return cochange(n-1,dp,coins,amount);
    }
};*/
//space optimization
/*class Solution {
public:
    int change(int amount, vector<int>& coins) {
        long long n=coins.size();
        vector<long long> prev(amount+1,0);
        for(long long sum=0;sum<=amount;sum++){
            if(sum%coins[0]==0){prev[sum]=1;}
        }
        for(int i=1;i<n;i++){
            vector<long long> curr(amount+1);
            for(long long sum=0;sum<=amount;sum++){
                long long nottake=prev[sum];
                long long take=0;
                if(coins[i]<=sum){
                    take=curr[sum-coins[i]];
                }
                curr[sum]=take+nottake;
            }
            prev=curr;
        }
        return (int)prev[amount];
    }
};*/
//tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount+1, 0));
        for(int sum=0;sum<=amount;sum++){
            if(sum%coins[0]==0){
                dp[0][sum]=1;
            }
        }
        for(int i=1;i<n;i++){
            for(int sum=0;sum<=amount;sum++){
                long long nottake=dp[i-1][sum];
                long long take=0;
                if(coins[i]<=sum){
                    take=dp[i][sum-coins[i]];
                }
                __int128 tmp = (__int128)take + (__int128)nottake;
                dp[i][sum] = (long long)tmp;
            }
        }
        return dp[n-1][amount];
    }
};