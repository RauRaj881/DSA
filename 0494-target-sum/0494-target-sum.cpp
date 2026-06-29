class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int tar){
        int n=nums.size();
        int sm=0;
        for(auto it:nums){sm+=it;}
        if((sm+tar)%2!=0||abs(tar)>sm){return 0;}
        int tar2=(sm+tar)/2;
        vector<vector<int>> dp(n,vector<int>(tar2+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
        if(nums[0]<=tar2){dp[0][nums[0]]++;}
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar2;j++){
                int nt=dp[i-1][j];
                int t=0;
                if(nums[i]<=j){
                    t=dp[i-1][j-nums[i]];
                }
                dp[i][j]=t+nt;
            }
        }
        return dp[n-1][tar2];
    }
};