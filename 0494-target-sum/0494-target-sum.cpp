class Solution {
public:
int tarsum(int index, vector<vector<int>> &dp,vector<int>& nums,int target){
    if(index==0){
        if(target==0&&nums[0]==0){return 2;}
        else if(target==0||nums[0]==target){return 1;}
        else{return 0;}
    }
    if(dp[index][target]!=-1){return dp[index][target];}
    int take=0;
    if(nums[index]<=target){
     take=tarsum(index-1,dp,nums,target-nums[index]);
    }
    int nottake=tarsum(index-1,dp,nums,target);
    return dp[index][target]=take+nottake;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totsum=0;
        for(auto it:nums){
            totsum+=it;
        }
        int newtar=(totsum+target)/2;
        if ((totsum + target) % 2 != 0 || abs(target) > totsum) return 0;
        vector<vector<int>> dp(n,vector<int>(newtar+1,-1));
        return tarsum(n-1,dp,nums,newtar);
    }
};