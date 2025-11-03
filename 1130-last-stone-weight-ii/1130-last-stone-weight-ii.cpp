class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum=0;
        for(auto it:stones){sum+=it;}
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
        for(int i=0;i<n;i++){dp[i][0]=true;}
        dp[0][stones[0]]=true;
        for(int i=1;i<n;i++){
            for(int k=1;k<=sum;k++){
                bool nottake=dp[i-1][k];
                bool take=false;
                if(stones[i]<=k){take=dp[i-1][k-stones[i]];}
                dp[i][k]=take||nottake;
            }
        }
        int mn=1e8;
        for(int k=0;k<=sum;k++){
            if(dp[n-1][k]){
                mn=min(mn,abs(k-(sum-k)));
            }
        }
        return mn;
    }
};