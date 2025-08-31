//memoization
/*class Solution {
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
};*/
//tabulation
/*class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                 if(buy==0){
               dp[i][buy]=max(-prices[i]+dp[i+1][1-buy],dp[i+1][buy]);
    }
                 else{
                 dp[i][buy]=max(prices[i]+dp[i+2][1-buy],dp[i+1][buy]);
    }        
            }
        }
        return dp[0][0];
    }
};*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> prev(2,0);
        vector<int> prev2(2,0);
        for(int i=n-1;i>=0;i--){
             vector<int> curr(2);
            for(int buy=0;buy<=1;buy++){
                 if(buy==0){
               curr[buy]=max(-prices[i]+prev[1-buy],prev[buy]);
                }
                 else{
                 curr[buy]=max(prices[i]+prev2[1-buy],prev[buy]);
                  }        
            }
            prev2=prev;
            prev=curr;
        }
        return prev[0];
    }
};