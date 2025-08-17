class Solution {
public:
bool SubSumUtil(int index,int target,vector<vector<int>> &dp,vector<int>&nums){
    if(target==0){return true;}
    if(index==0){return nums[index]==target;}
    if(dp[index][target]!=-1){return dp[index][target];}
    bool take =false;
    if(nums[index]<=target){
        take=SubSumUtil(index-1,target-nums[index],dp,nums);
    }
    bool nottake=SubSumUtil(index-1,target,dp,nums);
    return dp[index][target]=take||nottake;
}
    bool canPartition(vector<int>&nums){
        int n=nums.size();
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2==1){return false;}
        else {
            int target=sum/2;
            vector<vector<int>> dp(n,vector<int>(target+1,-1));
            return SubSumUtil(n-1,target,dp,nums);
        } 
    }
};