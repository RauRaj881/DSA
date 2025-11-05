class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums){sum+=it;}
        if(sum<target){return -1;}
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        if(nums[0]<=target)dp[0][nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int k=0;k<=target;k++){
                int nottaken=dp[i-1][k];
                int taken=-1;
                if (nums[i] <= k && dp[i-1][k - nums[i]] != -1)
                    taken = 1 + dp[i-1][k - nums[i]];
                dp[i][k]=max(taken,nottaken);
            }
        }
        return dp[n-1][target];
    }
};