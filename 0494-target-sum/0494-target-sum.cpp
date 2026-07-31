class Solution {
public:
    int findTargetSumWays(vector<int>& nums,int tar){
        int n=nums.size();
        int sum=0;
        for(auto it:nums){sum+=it;}
        if((tar+sum)%2!=0||abs(tar)>sum){return 0;}
        int trg=(tar+sum)/2;
        vector<vector<int>> dp(n,vector<int>(trg+1,0));
        dp[0][0]=1;
        if(nums[0]<=trg){dp[0][nums[0]]++;}
        for(int i=1;i<n;i++){
            for(int j=0;j<=trg;j++){
                int nt=dp[i-1][j];
                int t=0;
                if(nums[i]<=j){t=dp[i-1][j-nums[i]];}
                dp[i][j]=nt+t;
            }
        }
        return dp[n-1][trg];
    }
};